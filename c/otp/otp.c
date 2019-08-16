#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// return a byte array of msgLen from our otp file 
// takes a fptr and length of message
int otpBytes(FILE *otpPtr, unsigned char *otp, int msgLen){
   int fileSize;
   fseek(otpPtr, 0L, SEEK_END);
   fileSize = ftell(otpPtr);
   rewind(otpPtr);
   printf("file size(bytes) = %d\n", fileSize);

   if (msgLen > fileSize)
	 return -1;

   if (fread(otp, 1, msgLen, otpPtr) < msgLen)
   	return -1;

   return 0;
}

// take a simple message from the console

int main(int argc, char *argv[]){

    int opt;
    int m = -1, f = -1, p = -1;  // default initialize args to not present
    char *message = NULL;
    char *msgFilename = NULL;
    char *padFilename = NULL;

    while ((opt = getopt(argc, argv, "m:f:p:")) != -1) {
        switch (opt) {
            case 'm':
                m = 1;
                message = optarg;
                break;
            case 'f':
                f = 1;
                msgFilename = optarg;
                break;
            case 'p':
                printf("p is called: %s", optarg);
                p = 1;
                padFilename = optarg;
		break;
            default: /* '?' */
                fprintf(stderr, "Usage: %s -p pad [-f file] [-m] message\n", argv[0]);
                exit(EXIT_FAILURE);
       }
   }

   printf("m=%d, f=%d, p=%d\n", m, f, p);

   // enforce requirement for otp filename
   if (p<0) {
       fprintf(stderr, "Expected filename for one time pad [-p filename]\n");
       exit(EXIT_FAILURE);
   }

   // get message from args if not in options and not encrypting a file
   if (m<0 && f<0) {
       if (optind >= argc) {
           fprintf(stderr, "Expected message after options\n");
           exit(EXIT_FAILURE);
       }
       message = argv[optind];
   }

  printf("message argument = %s\n", argv[optind]);
  printf("message Filename = %s\n", msgFilename);
  printf("pad Filename = %s\n", padFilename);
  printf("message = %s\n", message);

  /* For now lets just do the simple case of a message an an otp file first securely open file */
  FILE *padPtr;
  padPtr = fopen(padFilename, "rb");
  int msgLen = sizeof(message);
  printf("msg length = %d\n", msgLen);
  unsigned char *otp = malloc(msgLen);
  
  otpBytes(padPtr, otp, msgLen); 
  printf("OTP = %s\n", otp);

  for ( int i=0; i<msgLen; ++i) {
	  printf("otp = %c, message = %c, ciphertext = %d\n", otp[i], message[i], otp[i] ^ message[i]); 
	  otp[i] = otp[i] ^ message[i];
  }

  printf("encrypted message: ");
  for(int i=0; i<msgLen; ++i)
	  printf("%x", otp[i]);
  printf("\n");

  // free all our memory and rsources
  free(otp);
  fclose(padPtr);
  
  // and exit
  exit(EXIT_SUCCESS);
}

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

#define MAXLINE 100

void readXBytes(void *socket, unsigned int x, void* buffer){
  int bytesRead = 0;
  int result;
  while(bytesRead < x){
    result = read(socket, buffer+ bytesRead, x - bytesRead);
    if( result < 1 ){
      printf("read error\n");
      break;
    }
    bytesRead += result;
  }
}

int main(int argc, char **argv){
  // declare sockets char buffer and address structure
  int sockfd, n;
  char sendline[MAXLINE], recvline[MAXLINE + 1];
  struct sockaddr_in servaddr;

  // check our arguments
  if(argc != 2){
      printf("argument error\n");
      return 1;
    }

  // cute declaration inside if statement to auto error check
  // parentheses are necessary cuz assignment is lower priority
  if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    printf("socket error\n");
    return 1;
  }

  // set servaddr to all zeros and set port and socket type
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(6666);

  // presentation to numeric function
  if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0){
    printf("address error\n");
    return 1;
  }

  // try to connect to the server
  if( connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0){
    printf("connection error\n");
    return 1;
  }

  // print the address and port bound to
  struct sockaddr_in sin;
  socklen_t len = sizeof(sin);
  if (getsockname(sockfd, (struct sockaddr *)&sin, &len) == -1){
    printf("getsockname\n");
    return 1;
  }
  else
      printf("port number %d\n", ntohs(sin.sin_port));


  while(fgets(sendline, MAXLINE, stdin) != NULL){

    if( write(sockfd, sendline, strlen(sendline)) < 0){
      printf("write failed\n");
      return 1;
    }

    readXBytes((void *) sockfd, 10, (void *)recvline);
    fputs(recvline, stdout);

    }

  return 0;
}

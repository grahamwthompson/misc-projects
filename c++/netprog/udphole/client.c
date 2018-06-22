#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

#define MAXLINE 100

void dg_cli(FILE *fp, int sockfd, const struct sockaddr *pservaddr, socklen_t servlen){
  int n;
  char sendline[MAXLINE], recvline[MAXLINE + 1];

  while(fgets(sendline, MAXLINE, fp) != NULL){
    sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);
    n = recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);

    recvline[n] = 0;
    printf("recieving: ");
    fputs(recvline, stdout);
  }

}

int main(int argc, char **argv){
  int sockfd;
  struct sockaddr_in servaddr;

  // check our arguments
  if(argc != 2){
      printf("argument error\n");
      return 1;
    }

  // setup sending socket and addresses
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(6666);
  inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);

  // get private address and port for our socket
  //printf("local address %d\n", inet_pton(AF_INET, ))
  printf("port number %d\n", ntohs(sin.sin_port))

  dg_cli(stdin, sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

  return 0;

}

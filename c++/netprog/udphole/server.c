#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

#define MAXLINE 100

void dg_echo(int sockfd, struct sockaddr* pcliaddr, socklen_t clilen)
{
  int n;
  socklen_t len;
  char mesg[MAXLINE];
  printf("Gets to the echo function\n");

  for(;;){
    len = clilen;
    n = recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);
    sendto(sockfd, mesg, n, 0, pcliaddr, len);
  }
}

int main(){
  // declare just 1 socket for udp
  int sockfd;
  // declare socket address struct for our server and client
  struct sockaddr_in servaddr, cliaddr;

  // create socket of datagram type
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  bzero(&servaddr, sizeof(servaddr));

  servaddr.sin_family = AF_INET;                 // Internet socket type
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);  // host to network long
  // sets the port the socket uses to 6666
  servaddr.sin_port = htons(6666);  // host to network short

  // bind the listen socket to our servaddr must be converted to type sockaddr
  bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

  dg_echo(sockfd, (struct sockaddr *) &cliaddr, sizeof(cliaddr));

  return 0;
}

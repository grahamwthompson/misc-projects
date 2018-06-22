#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

#define MAXLINE 100

int main(){
  // declare 2 sockets
  int listenfd, connectionfd;
  // declare socket address struct for our server
  struct sockaddr_in servaddr;
  // declare char buffer for writing stuff to socket
  char buff[MAXLINE];

  // create socket of internet stream types
  listenfd = socket(AF_INET, SOCK_STREAM, 0);

  // special network function equivalent to
  // memset(&servaddr, sizeof(servaddr), 0)
  // some functions require that the last 8 bits of a sockaddr
  // be set to zero for some reason
  bzero(&servaddr, sizeof(servaddr));

  servaddr.sin_family = AF_INET;                 // Internet socket type
  // sets the address that the socket may connect to to
  // a generic allow any INADDR_ANY number
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);  // host to network long
  // sets the port the socket uses to 6666
  servaddr.sin_port = htons(6666);  // host to network short

  // bind the listen socket to our servaddr must be converted to type sockaddr
  bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

  // change the socket to a listening socket which accepts incoming connections
  // by the kernel, second value is the number of connections kernel will queue
  listen(listenfd, 5);

  for(;;){
    // returns a new socket descriptor for each client that connects
    connectionfd = accept(listenfd, (struct sockaddr*) NULL, NULL);

    // print the address and port bound to
    struct sockaddr_in sin;
    socklen_t len = sizeof(sin);
    if (getsockname(connectionfd, (struct sockaddr *)&sin, &len) == -1){
      printf("getsockname\n");
      return 1;
    }
    else
        printf("port number %d\n", ntohs(sin.sin_port));

    // get the address and port of the peer may be doable without
    // this call as well
    getpeername(connectionfd, (struct sockaddr*)&sin, &len);
    printf("Remote Port: %d\n", ntohs(sin.sin_port));

    // writes something to buffer then writes it to the connection
    snprintf(buff, sizeof(buff), "world is a gay\n you are also a gay\n\r");
    write(connectionfd, buff, strlen(buff));

    // close the connection after we finish
    close(connectionfd);
  }

  printf("This works I guess\n");
  return 0;
}

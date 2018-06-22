#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
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

void run_thread(void *ptr){
  char buffer[MAXLINE];
  bzero(buffer, MAXLINE);
  int n;
  for(;;){
    readXBytes(ptr, 10, (void *)buffer);
    printf("%s\n", buffer);
    write(ptr, buffer, strlen(buffer));
  }
  /*
  for(;;){
    while( (n=read(ptr, buffer, MAXLINE-1)) > 0){
      if(n<0){
        printf("Read Error\n");
      }
      printf("%s\n", buffer);
      printf("%d writing buffer\n");
      write(ptr, buffer, strlen(buffer));
    }
  }
  */

}

int main(){
  printf("Server starts\n");
  int listenfd, connectionfd;
  struct sockaddr_in servaddr;
  char buff[MAXLINE];

  listenfd = socket(AF_INET, SOCK_STREAM, 0);

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;                 // Internet socket type
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);  // host to network long
  servaddr.sin_port = htons(6666);  // host to network short

  // bind the listen socket to our servaddr must be converted to type sockaddr
  bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
  listen(listenfd, 5);

  for(;;){
    printf("enters for loop\n");
    // returns a new socket descriptor for each client that connects
    connectionfd = accept(listenfd, (struct sockaddr*) NULL, NULL);
    printf("Created a new connection socket\n");

    // try moving the connection to a new thread
    //pthread_t thread;
    //pthread_create(&thread, NULL, run_thread, (void *) connectionfd);
    //printf("created a new thread for socket friend");
    //pthread_join(thread, NULL);
    //printf("Thread rejoins");
    run_thread((void *) connectionfd);

    // writes something to buffer then writes it to the connection
    //snprintf(buff, sizeof(buff), "world is a gay\n you are also a gay\n\r");
    //write(connectionfd, buff, strlen(buff));

    // close the connection after we finish
    close(connectionfd);
  }

  return 0;
}

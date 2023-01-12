#ifndef _REENTRANT
#define _REENTRANT
#endif

#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "util.h"

// How many pending connections queue will hold
#define BACKLOG 20

#define MSGSIZE 2048

// Initialize variables
int sockfd;
struct sockaddr_in my_addr;
socklen_t addr_size;
int fd;

/**********************************************
 * init
   - port is the number of the port you want the server to be
     started on
   - initializes the connection acception/handling system
   - YOU MUST CALL THIS EXACTLY ONCE (not once per thread,
     but exactly one time, in the main thread of your program)
     BEFORE USING ANY OF THE FUNCTIONS BELOW
   - if init encounters any errors, it will call exit().
************************************************/
void init(int port)
{
  // Check for socket open error
  if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
  {
    perror("Error: Can't create socket");
    exit(1);
  }

  // Bind the socket, making its address reusable
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(port);
  my_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  // Set the "re-use" option so we can shut down and restart the server without waiting for the standard timeout
  int enable = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) == -1)
  {
    perror("Error: Can't set socket option");
    exit(1);
  }

  // Check for bind error
  if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(my_addr)) == -1)
  {
    perror("Error: Could not bind");
    exit(1);
  }

  // Set up the socket to listen for incoming connection requests
  if (listen(sockfd, BACKLOG) == -1)
  {
    perror("Error: Could not listen");
    exit(1);
  }
}

/**********************************************
 * accept_connection - takes no parameters
   - returns a file descriptor for further request processing.
     DO NOT use the file descriptor on your own -- use
     get_request() instead.
   - if the return value is negative, the request should be ignored.
***********************************************/
int accept_connection(void)
{
    // Accept connections and serve our message
    addr_size = sizeof(my_addr);
  
    // Check for connection error
    if ((fd = accept(sockfd, (struct sockaddr *)&my_addr, &addr_size)) < 0)
    {
      perror("Error: Failed to accept connection");
      return -1;
    }

    return fd;
  }


/**********************************************
 * get_request
   - parameters:
      - fd is the file descriptor obtained by accept_connection()
        from where you wish to get a request
      - filename is the location of a character buffer in which
        this function should store the requested filename. (Buffer
        should be of size 1024 bytes.)
   - returns 0 on success, nonzero on failure. You must account
     for failures because some connections might send faulty
     requests. This is a recoverable error - you must not exit
     inside the thread that called get_request. After an error, you
     must NOT use a return_request or return_error function for that
     specific 'connection'.
************************************************/
int get_request(int fd, char *filename)
{
  char msg[MSGSIZE];
  char begin[3];

  int readsz = 0;
  int index = 0;

  // Check if a proper GET Request
  if ((read(fd, begin, 3) >= 0))
  {
    if (strcmp(begin, "GET") != 0)
    {
      perror ("Error: Not a GET request");
      close(fd);
      return -1;
    }
  }
  else
  {
    perror ("Error: Failing to read GET request header");
    close(fd);
    return -1;
  }
  

  // Read in path of file
  if ((readsz = read(fd, msg, MSGSIZE - 1)) >= 0)
  {
    msg[readsz] = '\0';

    // Read to start of file name
    strcpy(msg, strchr(msg, '/'));

    // Get filename
    while (msg[index] != ' ')
    {
      filename[index] = msg[index];
      
      
      // Check for double "//" or ".." in filepath
      if ((msg[index] == '/' && msg[index+1] =='/') || (msg[index] == '.' && msg[index+1] =='.'))
      {
          perror("Invalid filepath.");
          close(fd);
      }
      
      index++;
    }

    filename[index] = '\0';

    return 0;
  }
  else  
  {
    // Check if read failed
    perror ("Error: Server read problem");
  }
  
  return -1;
}

/**********************************************
 * return_result
   - returns the contents of a file to the requesting client
   - parameters:
      - fd is the file descriptor obtained by accept_connection()
        to where you wish to return the result of a request
      - content_type is a pointer to a string that indicates the
        type of content being returned. possible types include
        "text/html", "text/plain", "image/gif", "image/jpeg" cor-
        responding to .html, .txt, .gif, .jpg files.
      - buf is a pointer to a memory location where the requested
        file has been read into memory (the heap). return_result
        will use this memory location to return the result to the
        user. (remember to use -D_REENTRANT for CFLAGS.) you may
        safely deallocate the memory after the call to
        return_result (if it will not be cached).
      - numbytes is the number of bytes the file takes up in buf
   - returns 0 on success, nonzero on failure.
************************************************/
int return_result(int fd, char *content_type, char *buf, int numbytes)
{

  // Write file information to socket descriptor
  dprintf(fd, "HTTP/1.1 200 OK\n");
  dprintf(fd, "Content-Type: %s\n", content_type);
  dprintf(fd, "Content-Length: %d\n", numbytes);
  dprintf(fd, "Connection: Close\n");
  dprintf(fd, "\n");

  // Write buffer to socket descriptor
  write(fd, buf, numbytes);

  close(fd);
  return 0;
}

/**********************************************
 * return_error
   - returns an error message in response to a bad request
   - parameters:
      - fd is the file descriptor obtained by accept_connection()
        to where you wish to return the error
      - buf is a pointer to the location of the error text
   - returns 0 on success, nonzero on failure.
************************************************/
int return_error(int fd, char *buf)
{
  // Write file information to socket descriptor
  dprintf(fd, "HTTP/1.1 404 Not Found\n");
  dprintf(fd, "Connection: Close\n");
  dprintf(fd, "\n");
  
  // Write buffer to socket descriptor
  write(fd, buf, 25);

  close(fd);
  return 0;
}

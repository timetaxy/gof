#include <iostream>
using namespace std;
#include <sys/socket.h>
#include <netinet/in.h>

#define SERV_TCP_PORT   8000

class WebServer {
  public :
    void execute(int fd) {
    }
};

int 
main()
{
  int sockFd, newSockFd, nSockAddr;
  struct sockaddr_in cliAddr, servAddr;

  if ((sockFd=socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    cout << "Can't open socket stream" << endl;
    exit(0);
  }

  nSockAddr = sizeof(struct sockaddr_in);
  bzero((char*)&servAddr, nSockAddr);
  servAddr.sin_family = AF_INET;
  servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servAddr.sin_port = htons(SERV_TCP_PORT);

  if (bind(sockFd, (struct sockaddr *)&servAddr, nSockAddr) < 0) {
    cout << "Can't bind local address" << endl;
    exit(0);
  }

  listen(sockFd, 5);

  WebServer *pHttpd;
  while (1) {
    newSockFd = accept(sockFd, (struct sockaddr *)&cliAddr, nSockAddr);
    if (newSockFd < 0) {
      cout << "Accept Error" << endl;
      continue;
    }

    pHttpd = new WebServer;

    if ((childPid=fork()) < 0) {
      cout << "Can't fork process" << endl;
    }
    else if (childPid == 0) {
      WebServer *pTmpHttpd = pHttpd;
      close(sockFd);
      pTmpHttpd->execute(newSockFd);
      delete(pTmpHttpd);
      exit(0);
    }
    else {}

    close(newSockFd);
  }
}

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
using namespace std;

#define MAX_BUF_SIZE    500

class InternetClient {
  public :
    void DoService(string serverName, int port) {
      int sock;
      string req = MakeRequest();
      if ((sock=ConnectToServer(serverName, port)) < 0) return;
      SendRequest(sock, req);
      string rsp = RecvResponse(sock);
      ProcessResponse(rsp);
    }

    virtual string MakeRequest() = 0;
    virtual void ProcessResponse(string rsp) = 0;

    int ConnectToServer(string serverName, int port) {
      int sock;
      struct sockaddr_in server;
      struct hostent *pHostInfo;

      if (serverName.empty()) 
        serverName = "localhost";

      sock = socket(AF_INET, SOCK_STREAM, 0);
      if (sock < 0) {
        cout << "Error in Socket Creation" << endl;
        return -1;
      }

      pHostInfo = gethostbyname(serverName.data());
      if (pHostInfo == NULL) {
        cout << "Error in gethostbyname" << endl;
        return -1;
      }

      server.sin_family = pHostInfo->h_addrtype;
      memcpy((char*)&server.sin_addr, pHostInfo->h_addr, pHostInfo->h_length);
      server.sin_port = htons(port);

      if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        cout << "Error in connect" << endl;
        return -1;
      }

      return sock;
    }

    void SendRequest(int sock, string req) {
      write(sock, req.data(), req.length());
    }

    string RecvResponse(int sock) {
      string rsp;
      int nread;
      char buf[MAX_BUF_SIZE+1];
      bzero(buf, MAX_BUF_SIZE);

      do {
        nread = read(sock, buf, MAX_BUF_SIZE);
        if (nread < 0) {
          cout << "Error in read" << endl;
          return rsp;
        }
        else if (nread == 0) // -- EOF
          return rsp;
        else 
          rsp += string(buf, nread);
      } while (nread >= MAX_BUF_SIZE);

      return rsp;
    }
};

class HTTPClient : public InternetClient {
  public :
    string MakeRequest() {
      string req;
      // -- �̿��ڷκ��� URL ������ �Է¹޾� HTTP Request ���ڿ��� ����
      req = "GET / HTTP/1.0\n\n";
      return req;
    }

    void ProcessResponse(string rsp) {
      // -- �� ���������� rsp ���ڿ��� ����
      cout << rsp << endl;
    }
};

class SMTPClient : public InternetClient {
  public :
    string MakeRequest() {
      string req;
      // -- �̿��ڷκ��� ������ �Է¹޾� SMTP Request ���ڿ��� ����
      return req;
    }

    void ProcessResponse(string rsp) {
      // -- ���� �߽� ����� �̿��ڿ��� ǥ��
    }
};

int
main()
{
  HTTPClient hCli;
  hCli.DoService("localhost", 80);
}
#include <iostream>
using namespace std;

class Request {
  public :
    virtual ~Request() {} // -- make polymorphic type.
};
class HelpRequest : public Request {};
class PrintRequest : public Request {};

class Handler {
  public : 
    Handler(Handler* pObj) : pSuccessor_(pObj) {}
    virtual void HandleRequest(Request *pReq) {
      if (dynamic_cast<HelpRequest*>(pReq) != NULL) {
        // -- HelpRequest�� ���� ó��
        cout << "HelpRequest Processing" << endl;
      }
      else if (dynamic_cast<PrintRequest*>(pReq) != NULL) {
        // -- PrintRequest�� ���� ó��
        cout << "PrintRequest Processing" << endl;
      }
      else {
        // -- �⺻���� ó��
        cout << "Default Processing" << endl;
      }
    }

  private :
    Handler* pSuccessor_;
};

int 
main()
{
  Handler hdlr(0);
  Request *pReq = new PrintRequest;

  hdlr.HandleRequest(pReq);
}
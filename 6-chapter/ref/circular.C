#include <iostream>
using namespace std;

class B;

class A {
  public :
    void setData(B *pB) { pData_ = pB; }

    A* Clone(B* pB) {
      A* pA = new A(*this);
      pA->pData_ = pB;
      return pA;
    }

  private :
    B *pData_;
};

class B {
  public : 
    void setData(A *pA) { pData_ = pA; }

    B* Clone(A* pA) {
      B* pB = new B(*this);
      pB->pData_ = pA;
      return pB;
    }

  private :
    A *pData_;
};

int 
main()
{
  A a; 
  B b;

  a.setData(&b);
  b.setData(&a);

  A* pNewA = a.Clone(&b);
  B* pNewB = b.Clone(&a);
}

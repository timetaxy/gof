#include <iostream>
using namespace std;

class A {
  public :
    virtual void print() = 0;
};

class B : public A {
  public :
    void print() {
      cout << "class B" << endl;
    }
};

class C : public B {
  public :
    void print() {
      cout << "class C" << endl;
    }
};

int
main()
{
  C c;
  A* pA = &c;

  pA->print();
}

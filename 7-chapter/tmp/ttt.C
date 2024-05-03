#include <iostream>
using namespace std;

class A {
  public :
    static void initData() {
      for (int i = 0; i < 3 ; i++)
        data_[i] = i+1;
    }

    void print() {
      for (int i=0; i < 3; i++)
        cout << "data[" << i << "] = " << data_[i] << endl;
    }

    static int data_[3];
};

int A::data_[3];

int 
main()
{
  A::initData();
  A a1;
  a1.print();
}

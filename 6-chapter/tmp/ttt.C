#include <iostream>
#include <list>
#include <iterator>
#include <string>
using namespace std;

char *p1 = "I am Tom";
char *p2 = "You are girl";

class A {
  public :
    A() {
      data_.push_front(p1);
      data_.push_front(p2);
    }

    A* Clone() {
      A* p = new A(*this);
      list<char*>::iterator iter1;
      list<char*>::iterator iter2;

      iter2 = p->data_.begin();
      for (iter1=data_.begin(); iter1 != data_.end(); iter1++) {
        char *pStr = new char[strlen(*iter1)+1];
        strcpy(pStr, *iter1);
        *iter2 = pStr;
        iter2++;
      }

      return p;
    }

    void print() {
      list<char*>::iterator iter;
      for (iter=data_.begin(); iter != data_.end(); iter++)
        cout << *iter << endl;
    }

  private :
    list<char *> data_;
};

int
main()
{
  A one;
  A* pAnother = one.Clone();

  one.print();
  cout << endl;
  pAnother->print();
}

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

class Graphic {
};

class Triangle : public Graphic {
};

class Rectangle : public Graphic {
};

class ComposedGraphic {
  public :
    void add(Graphic *pObj) {
      pComponent_.insert(pObj);
    }

    void remove(Graphic *pObj) {
    }

  private :
    list<Graphic *> pComponent_;
};


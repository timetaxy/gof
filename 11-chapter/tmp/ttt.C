#include <iostream>
#include <list>
#include <iterator>
#include <map>
using namespace std;

class Position {
  public : 
    Position() {}
    Position(int x, int y) { x_ = x; y_ = y; }
    int x_, y_;
};

class Graphic {
  public :
    virtual void Draw(Position& pos) = 0;
    virtual Graphic* Clone() = 0;
};

class Triangle : public Graphic {
  public :
    void Draw(Position& pos) {}
    Graphic* Clone() { return new Triangle(*this); }
};

class Rectangle : public Graphic {
  public : 
    void Draw(Position& pos) {}
    Graphic* Clone() { return new Rectangle(*this); }
};

class GraphicComposite : public Graphic {
  public : 
    void Draw(Position& pos) {}
    Graphic* Clone() { 
      GraphicComposite *pGraphicComposite = new GraphicComposite(*this);
      list<Graphic*>::iterator iter1;
      list<Graphic*>::iterator iter2;

      iter2 = pGraphicComposite->components_.begin();
      for (iter1 = components_.begin(); iter1 != components_.end(); iter1++) {
        Graphic* pNewGraphic = (*iter1)->Clone();
        *iter2 = pNewGraphic;
        iter2++;
      }

      return pGraphicComposite;
    }

  private : 
    list<Graphic*> components_;
};

class Document {
  public :
    void add(Graphic* pGraphic) {}
};

class Mouse {
  public :
    bool isLeftButtonPushed() { 
      bool isPushed;
      // -- GUI 함수 활용 Left Button 상태 체크
      return isPushed;
    }

    Position getPosition() {
      Position pos;
      // -- GUI 함수 활용 현재 마우스 위치 파악
      return pos;
    }
};

Mouse _mouse; // -- Global Variable

class GraphicEditor {
  public : 
    void addNewGraphics(Graphic* pSelected) {
      Graphic* pObj = pSelected->Clone();
      while (_mouse.isLeftButtonPushed()) {
        Position pos = _mouse.getPosition();
        pObj->Draw(pos);
      }

      curDoc_.add(pObj);
    }

  private :
    Document curDoc_;
};

class Palette {
  public :
    Palette() {
      Graphic* pGraphic = new Triangle;
      items_[1] = pGraphic;

      pGraphic = new Rectangle;
      items_[2] = pGraphic;

      // -- 필요한 만큼 등록 
    }

    void registerNewGraphic(Graphic* pGraphic) {
      items_[items_.size()+1] = pGraphic;
    }

    Graphic* getSelectedObj() {
      return items_[getItemOrder()];
    }

    int getItemOrder() {
      int i;
      Position curPos = _mouse.getPosition();
      // -- 현재 마우스 위치가 몇 번째 항목을 지정하는 지 판별
      return i;
    }

  private :
    map<int, Graphic*> items_;
};

int
main()
{
  Palette palette;
  GraphicEditor ged;

  ged.addNewGraphics(palette.getSelectedObj());
}

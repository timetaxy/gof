#include <iostream>
using namespace std;

#define FRONT_DIRECTION   1
#define SIDE_DIRECTION    2
#define REAR_DIRECTION    4

class Item {
  public : 
    Item(int dir) { direction_ = dir; } 
    int GetDirection() { return direction_; }

  private :
    int direction_;
};

class Airplane {
  public :
    void AddItem(Item* pItem) {
      direction_ += pItem->GetDirection();
    }

    void Attack() {
      if (direction_ & SIDE_DIRECTION) {
        // -- ���� ���� ����
        cout << "�������" << endl;
      }
      if (direction_ & REAR_DIRECTION) {
        // -- �Ĺ� ���� ����
        cout << "�Ĺ����" << endl;
      }

      // -- ���� ���� ����
      cout << "�������" << endl;
    }

  private :
    int direction_;
};

int
main()
{
  Item side(SIDE_DIRECTION);
  Airplane onePlayer;

  onePlayer.AddItem(&side);
  onePlayer.Attack();
} 
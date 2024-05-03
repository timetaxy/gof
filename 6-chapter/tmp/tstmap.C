#include <iostream>
#include <map>
#include <string>
using namespace std;

class Position {
  public : 
    int x_, y_;
};

struct ltPosition {
  bool operator() (const Position& p1, const Position& p2) {
    if (p1.x_ < p2.x_ || (p1.x_ == p2.x_ && p1.y_ < p2.y_))
      return true;
    else
      return false;
  }
};

int 
main()
{
  map<Position, string, ltPosition> m;
  Position p1, p2;
  p1.x_ = p1.y_ = 1;
  p2.x_ = p2.y_ = 2;

  m[p1] = "Hi";
  m[p2] = "TEL";
}

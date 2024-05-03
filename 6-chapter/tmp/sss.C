#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int
main()
{
  /**
  char* pa = "I am Tom";
  char* pb = "You are girl";
  **/

  list<char*> words;
  list<char*>::iterator iter;

  words.push_front("I am Tom");
  words.push_front("You are girl");

  for (iter=words.begin(); iter != words.end(); iter++)
    cout << *iter << endl;
}

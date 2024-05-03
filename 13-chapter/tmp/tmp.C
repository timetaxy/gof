#include <iostream>
#include <string>
using namespace std;

void func(char *p)
{
  while ((*p) != '\0') {
    cout << *p++;
  }

  cout << endl;
}

int
main()
{
  static char s[] = "I am Tom";
  func(s);
}


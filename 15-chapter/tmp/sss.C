#include <iostream>
#include <map>
using namespace std;

map<string, char*> test;

int
main()
{
  char *pStr = new char[10];
  strcpy(pStr, "abcdef");

  test["abc"] = pStr;
  char *pOut = test["abc"];
  cout << pOut << endl;

  delete pStr;
  test.erase("abc");

  pOut = test["abc"];
  if (pOut != NULL)
    cout << *pOut << endl;
  else
    cout << "OK" << endl;
}

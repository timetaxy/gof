#include <iostream>
#include <string>
using namespace std;

int main()
{
  char *pFile = "abc.doc";

  cout << strrchr(pFile, '.') << endl;
}

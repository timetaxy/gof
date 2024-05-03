#include <iostream>
#include <string>
using namespace std;

int 
main()
{
  string s = "abcd.efg";
  string::size_type pos = s.rfind(".");

  cout << pos << endl;

  string s2 = s.substr(pos+1, s.length()-pos-1);
  cout << s2 << endl;
}

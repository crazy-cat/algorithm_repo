// Author: qushuqian
// Problem:
// solution:
 
#include <iostream>
#include <assert.h>

using namespace std;

bool string_to_int(const char* s, int* ret_int) {
  *ret_int = 0;
  if (!s) return false;
  int flag = 1;
  int ret = 0;
  if (*s == '-') {
    flag = -1;
    s++;
  }
  while (*s) {
   if (*s < '0' || *s > '9')
     return false;
   int temp = ret;
   ret = ret * 10 + *s - '0';
   if (temp > ret)
    return false;
   s++;
  }
  *ret_int = ret * flag;
  return true;
}

int main() {
  {
    char p[] = "123";
    int ret = 0;
    string_to_int(p, &ret);
    cout << p << '\t' << ret << endl;
  }
  {
    char p[] = "-123";
    int ret = 0;
    string_to_int(p, &ret);
    cout << p << '\t' << ret << endl;
  }
  {
    char p[] = "0";
    int ret = 0;
    string_to_int(p, &ret);
    cout << p << '\t' << ret << endl;
  }
  {
    char p[] = "1234567890123456789";
    int ret = 0;
    string_to_int(p, &ret);
    cout << p << '\t' << ret << endl;
  }
  {
    char p[] = "-1234567890123456789";
    int ret = 0;
    string_to_int(p, &ret);
    cout << p << '\t' << ret << endl;
  }
  return 0;
}

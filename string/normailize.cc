#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

char* normailize(char* s) {
  if (!s || !*s || !*(s+1))
    return s;
  char* p = s;
  char* q = s;

  while(*q == ' ')
    q++;
  // such as "   "
  if (!*q) {
    *(p+1) = *q;
    return s;
  }
  *p++ = *q;
  q++;
  while(*q) {
    if (*q != ' ' || *(p-1) != ' ')
      *p++ = *q;
    q++;
  }
  if (*(p-1) == ' ')
    *(p-1) = '\0';
  else
    *p = '\0';
  return s;
}


int main() {
  char s1[] = " ";
  char s2[] = " ss ";
  char s3[] = "  sdf   fdds ";
  cout << s1;
  cout << "@@" << normailize(s1) << endl;
  cout << s2;
  cout << "@@" << normailize(s2) << endl;
  cout << s3;
  cout << "@@" << normailize(s3) << endl;
  return 0;
}

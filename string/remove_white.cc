#include <iostream>

using namespace std;

int remove_whitespace(char* str) {
  if (!str || !*str) return 0;
  int white_space_num = 0;
  char* p = str;
  char* q = str;
  while (*q) {
    if (*q != ' ') {
      *p++ = *q++;
    } else {
      white_space_num++;
      q++;
    }
  }
  *p = '\0';
  return white_space_num;
}

int main() {
  char str[] = "  asdf  dd  ";
  cout << str << endl;
  cout << remove_whitespace(str) << endl;
  cout << str << endl;
  return 0;
}

// Author: qushuqian
// Problem:输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，
// 输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r
// stdnts.”。
// solution:
 
#include <iostream>
#include <assert.h>

using namespace std;

char* delete_special_char(char* origin_str, char* char_set) {
  assert(origin_str && char_set);
  bool hash_char[256];
  for (int i = 0; i < sizeof(hash_char); i++)
    hash_char[i] = false;
  for (char* p = char_set; *p; p++)
    hash_char[*p] = true;
  char* p = origin_str;
  char* q = origin_str;
  while (*q) {
    if (!hash_char[*q]) {
      *p = *q;
      p++;
    }
    q++;
  }
  *p = *q;
  return origin_str;
}


int main() {
  char origin_str[] = "They are students.";
  char char_set[] = "aeiou";
  cout << origin_str << "\t" << char_set << endl;
  cout << delete_special_char(origin_str, char_set) << endl;
  char origin_str_1[] = "aeiou";
  cout << origin_str_1 << "\t" << char_set << endl;
  cout << delete_special_char(origin_str_1, char_set) << endl;
  return 0;
}

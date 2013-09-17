// Author: qushuqian
// Problem: 输入一个正整数数组，将它们连接起来排成一个数，输出能排出的所有数字中最
// 小的一个。例如输入数组{32, 321}，则输出这两个能排成的最小数字32132。
// solution: 可以直接比较AB和BA的字符串大小
 
#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

bool compare_num_str(const char* s1, const char* s2) {
  assert(s1 && s2 && *s1 && *s2);
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  int combine_len = len1 + len2 + 1;
  char * combine_1_2 = new char[combine_len]();
  char * temp = combine_1_2;
  const char* p = s1;
  while (*p) *temp++ = *p++;
  p = s2;
  while (*p) *temp++ = *p++;
  char * combine_2_1 = new char[combine_len]();
  temp = combine_2_1;
  p = s2;
  while (*p) *temp++ = *p++;
  p = s1;
  while (*p) *temp++ = *p++;
  bool ret = false;
  if (strcmp(combine_1_2, combine_2_1) > 0)
    ret = true;
  delete [] combine_1_2;
  delete [] combine_2_1;
  return ret;
}

bool compare_num_str_my(const char* s1, const char* s2) {
  assert(s1 && s2 && *s1 && *s2);
  const char* p = s1;
  const char* q = s2;
  int len1 = 0;
  int len2 = 0;
  while (*p++)
    len1++;
  while (*q++)
    len2++;
  p = s1;
  q = s2;
//  cout << s1 << '\t' << s2 << endl;
  int max_len = (len1 >= len2 ? len1 : len2);
  for (int i = 0; i < max_len; i++) {
    if (!*p) p = s1;
    if (!*q) q = s2;
    if (*p > *q) return true;
    else if (*p < *q) return false;
    p++;
    q++;
  }
  if (*p && !*q) {
    char* head = new char[p-s1+1]();
    char* temp = head;
    q = s1;
    while(q < p) {
      *temp++ = *q;
      q++;
    }
//    cout << p << '\t' << head;
    bool ret = compare_num_str_my(p, head);
    delete [] head;
    return ret;
  }
  if (*q && !*p) {
    char* head = new char[q-s2+1]();
    char* temp = head;
    p = s2;
    while(p < q) {
      *temp++ = *p;
      p++;
    }
 //   cout << q << '\t' << head;
    bool ret = compare_num_str_my(head, q);
    delete [] head;
    return ret;
  }
  return false;
}

int main() {
  {
    char s1[] = "32";
    char s2[] = "32";
    cout << s1 << '\t' << s2 << endl;
    cout << '\t' << compare_num_str_my(s1, s2) << endl;
    cout << s1 << '\t' << s2 << '\t' << compare_num_str(s1, s2) << endl;
  }
  {
    char s1[] = "321";
    char s2[] = "32";
    cout << s1 << '\t' << s2 << '\t' << compare_num_str_my(s1, s2) << endl;
    cout << s1 << '\t' << s2 << '\t' << compare_num_str(s1, s2) << endl;
  }
  {
    char s1[] = "324";
    char s2[] = "32";
    cout << s1 << '\t' << s2 << '\t' << compare_num_str_my(s1, s2) << endl;
    cout << s1 << '\t' << s2 << '\t' << compare_num_str(s1, s2) << endl;
  }
  {
    char s1[] = "323";
    char s2[] = "32";
    cout << s1 << '\t' << s2 << '\t' << compare_num_str_my(s1, s2) << endl;
    cout << s1 << '\t' << s2 << '\t' << compare_num_str(s1, s2) << endl;
  }
  {
    char s1[] = "334";
    char s2[] = "3343";
    cout << s1 << '\t' << s2 << '\t' << compare_num_str_my(s1, s2) << endl;
    cout << s1 << '\t' << s2 << '\t' << compare_num_str(s1, s2) << endl;
  }
  {
    char s1[] = "3434";
    char s2[] = "34";
    cout << s1 << '\t' << s2 << '\t' << compare_num_str_my(s1, s2) << endl;
    cout << s1 << '\t' << s2 << '\t' << compare_num_str(s1, s2) << endl;
  }
  return 0;
}

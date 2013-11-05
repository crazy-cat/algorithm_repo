// Author: qushuqian
// Problem:输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，
// 输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r
// stdnts.”。
// solution:
 
#include <iostream>
#include <assert.h>
#include <string>

using namespace std;



int main() {
  int num = 0x80000000;
  cout << num << endl;
//  cout << hex << num << endl;
  int neg_num = -1 * num;
  cout << neg_num << endl;
//  cout << hex << neg_num << endl;
  int num_1 = 0x7FFFFFFF;
  cout << num_1 << endl;
//  cout << hex << num << endl;
  int neg_num_1 = -1 * num_1;
  cout << neg_num_1 << endl;
//  cout << hex << neg_num << endl;
//  cout << hex << 2147395599 << endl;  
  string tmp("asdf");
  cout << tmp.substr(2) << endl;
  int i = 1;
  int j = 1;
  cout << i%j << endl;
  cout << i/j << endl;
  
  return 0;
}

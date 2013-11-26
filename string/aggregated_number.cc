// Author: qushuqian
// Problem:
// we will name a number "aggregated number" if the digits in the number can divided into several parts, and the later part is the sum of the former parts.
//
// like 112358, because 1+1=2, 1+2=3, 2+3=5, 3+5=8
// 122436, because 12+24=36
// 1299111210, because 12+99=111, 99+111=210
// 112112224, because 112+112=224
//
// so can you provide a function to check whether this number is aggregated number or not?
// solution:
 
#include <iostream>
#include <assert.h>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

bool __aggregated_number(string& num, int begin, int first, int second) {
  if (begin == num.size()) return true;
  int third = 0;
  for (int i = begin; i < num.size(); i++) {
    third += num[i] - '0';
    if (third == first + second) {
      return __aggregated_number(num, i+1, second, third);
    }
    third *= 10;
  }
  return false;
}

bool is_aggregated_number(int number) {
  int n = abs(number);
  int flag = (number >> 31)&1 ? -1 : 1;
  stringstream s_stream;
  s_stream << n;
  string str = s_stream.str();
  int first = 0;
  for (int i = 0; i < str.size() - 2; i++) {
    first += str[i] - '0';
    int second = 0;
    for (int j = i+1; j < str.size() - 1; j++) {
      second += str[j] - '0';
      // third
      if (__aggregated_number(str, j+1, flag * first, second)) {
        return true;
      }
      second *= 10;
    }
    first *= 10;
  }
  return false;
}

int main() {
  int num = 101;
  cout << num << " " << is_aggregated_number(num)<< endl;
  num = 12012;
  cout << num << " " << is_aggregated_number(num) << endl;
  num = -120132;
  cout << num << " " << is_aggregated_number(num) << endl;
  num = -120131;
  cout << num << " " << is_aggregated_number(num) << endl;
  num = 12113;
  cout << num << " " << is_aggregated_number(num) << endl;
  return 0;
}

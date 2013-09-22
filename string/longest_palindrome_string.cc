// Author: qushuqian
// Problem:最长回文子串LPS
// bananas的LPS为"anana"
// cabbad的LPS为"abba"
// 
// 给定字符串，找出其LPS的长度。
// 找出一个LPS。
// 找到所有LPS。
// solution:
 
#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

int lps(char* origin_str) {
  assert(origin_str);
  int len = strlen(origin_str);
  int odd_len = 2 * len + 1;
  char* odd_str = new char[odd_len+1]();
  for (int i = 0; i < odd_len; i++) {
    if (i&1)
      odd_str[i] = origin_str[i/2];
    else
      odd_str[i] = '#';
  }
  cout << odd_str << endl;
  int* radius = new int[odd_len]();
  for (int i = 0; i < odd_len; ++i) {
    radius[i] = 1;
  }
  int cur_center_right = 0;
  int cur_radius_right = 1;
  int max_radius = 1;

  for (int i = 1; i < odd_len; i++) {
    int cur_pos_right = cur_center_right + cur_radius_right - 1;
    if (i < cur_pos_right)
      radius[i] = radius[2*cur_center_right-i] > (cur_pos_right - i + 1) ? 
        radius[2*cur_center_right-i] : (cur_pos_right - i + 1);
    while (i + radius[i] <= odd_len && i - radius[i] >= 0 && odd_str[i + radius[i]] == odd_str[i - radius[i]])
      radius[i]++;
    if (i + radius[i] - 1 > cur_pos_right) {
      cur_center_right = i;
      cur_radius_right = radius[i];
    }
    if (max_radius < radius[i])
      max_radius = radius[i];
  }

  int ret_pos = 0;
  for (int i = 0; i < odd_len; i++) {
    if (radius[i] == max_radius) {
      ret_pos = i;
      break;
    }
  }
  for (int i = ret_pos-radius[ret_pos]+1; i <= ret_pos+ radius[ret_pos] -1; i++)
    cout << odd_str[i];
  
  delete [] radius;
  delete [] odd_str;
  return max_radius - 1;
}

int main() {
  char origin_str[] = "cabba";
  cout << origin_str ;
  cout << "\t" << lps(origin_str) << endl;
  return 0;
}

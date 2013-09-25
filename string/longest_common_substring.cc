// Author: qushuqian
// Problem:求两个字符串(字符数组)的最长公共子序列, 子序列不要求字符连续

// 输入字符串A: 'abcdefghi'
//           B: 'cadcdabghi'
// 
// 输出LCS长度:6 子串: acdghi
// solution:
 
#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

int lcs(char* str_a, char* str_b) {
  assert(str_a && str_b);
  if (!*str_a || !*str_b)
    return 0;
  int len_a = strlen(str_a);
  int len_b = strlen(str_b);
  int** ret = new int*[len_a];
  for (int i = 0; i < len_a; i++)
    ret[i] = new int[len_b]();

  // 1: left-up
  // 2: left
  // 3: up
  int** path = new int*[len_a];
  for (int i = 0; i < len_a; i++)
    path[i] = new int[len_b]();

  for (int i = 0; i < len_a; ++i) {
    if (str_a[i] == str_b[0]) {
      ret[i][0] = 1;
      path[i][0] = 1;
    } else if (i > 0 && ret[i-1][0]) {
      ret[i][0] = 1;
      path[i][0] = 3;
    }
  }
  for (int i = 0; i < len_b; ++i) {
    if (str_b[i] == str_a[0]) {
      ret[0][i] = 1;
      path[0][i] = 1;
    }
    else if (i > 0 && ret[0][i-1]) {
      ret[0][i] = 1;
      path[0][i] = 2;
    }
  }

  for (int i = 1; i < len_a; i++) {
    for (int j = 1; j < len_b; j++) {
      if (str_a[i] == str_b[j]) {
        ret[i][j] = ret[i-1][j-1] + 1;
        path[i][j] = 1;
      } else if (ret[i-1][j] > ret[i][j-1]) {
        ret[i][j] = ret[i-1][j];
        path[i][j] = 2;
      } else {
        ret[i][j] = ret[i][j-1];
        path[i][j] = 3;
      }
    }
  }
  int max_len = ret[len_a-1][len_b-1];
  cout << max_len << endl; 
//  for (int i = 0; i < len_a; ++i) {
//    for (int j = 0; j < len_b; ++j) {
//      cout << path[i][j] << '\t';
//    }
//    cout << endl;
//  }

  int i = len_a - 1;
  int j = len_b - 1;
  while (i >= 0 && j >= 0) {
    if (path[i][j] == 1) {
      cout << str_a[i];
      i--;
      j--;
    } else if (path[i][j] == 2) {
      i--;
    } else if (path[i][j] == 3) {
      j--;
    } else {
      cout << path[i][j] << '\t' << i << '\t' << j;
    }
  }
  cout << '\n';

  for (int i = 0; i < len_a; i++)
    delete [] path[i];
  delete [] path;
  path = NULL;
  for (int i = 0; i < len_a; i++)
    delete [] ret[i];
  delete [] ret;
  ret = NULL;
  return max_len;
}


// int lcs(char* str_a, char* str_b) {
//   assert(str_a && str_b);
//   if (!*str_a || !*str_b)
//     return 0;
//   int len_a = strlen(str_a);
//   int len_b = strlen(str_b);
//   int* lcs = new int[len_a]();
// 
//   for (int i = 0; i < len_a; ++i) {
//     if (str_a[i] == str_b[0])
//       lcs[i] = 1;
//     else if (lcs[i-1] > lcs[i])
//       lcs[i] = lcs[i-1];
//   }
// 
//   for (int i = 1; i < len_b; ++i) {
//     for (int j = 0; j < len_a; ++j) {
//       if (str_a[j] == str_b[i])
//         lcs[j] = lcs[j-1] + 1;
//       else if (lcs[j-1] > lcs[j])
//         lcs[j] = lcs[j-1];
//     }
//     for (int i = 0; i < len_a; ++i) {
//       cout << lcs[i] << '\t';
//     }
//     cout << endl;
//   }
//   int max_len = lcs[len_a-1];
// 
//   delete [] lcs;
//   return max_len;
// }

int main() {
  char str_a[] = "cabaaba";
  char str_b[] = "abaaaba";
  cout << str_a << '\t' << str_b << endl;
  cout << lcs(str_a, str_b) << endl;
  return 0;
}

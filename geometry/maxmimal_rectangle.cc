// Author: qushuqian
// Problem:Maximal Rectangle Given a 2D binary matrix filled with 0's and 1's, 
// find the largest rectangle containing all ones and return its area.
// solution:
 
#include <iostream>
#include <assert.h>
#include <stack>

using namespace std;

struct Interval {
  int begin;
  int end;
//  struct Interval():begin(0),end(0) {}
};

bool is_interval_overlap(const Interval& i1, const Interval& i2) {
  if (i1.begin >= i2.begin && i2.end >= i1.begin || 
      i2.begin >= i1.begin && i1.end >= i2.begin)
    return true;
  return false;
}

void print_rectangle(int** rect, int m, int n) {
  assert(rect && m > 0 && n > 0);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << rect[i][j] << '\t';
    }
    cout << endl;
  }
}

int rect_one_number(int** rect, int m, int n) {
  assert(rect && m > 0 && n > 0);
  int rect_number = 0;
  for (int i = 0; i < n; i++) {
    if (i ==0 && rect[0][i] == 1 || 
        i > 0 && rect[0][i] == 1 && rect[0][i-1] == 0)
      rect_number++;
  }
  cout << rect_number << endl;
  int begin = -1;
  int end = -1;
  bool last_interval_one = false;
  for (int i = 1; i < m; i++) {
    begin = -1;
    end = -1;
    for (int j = 0; j < n; j++) {
      if (j == 0 && rect[i][j] == 1 ||
          rect[i][j-1] == 0 && rect[i][j] == 1) {
        begin = j;
      }
      if (end < begin && rect[i-1][j] == 1)
        last_interval_one = true;

      if (j+1 < n && rect[i][j] == 1 && rect[i][j+1] == 0 ||
          j+1 == n && rect[i][j] == 1) {
        end = j;
        if (!last_interval_one)
          rect_number++;
//        cout << rect_number << '\t' << begin << '\t' << end << endl;
        last_interval_one = false;
      }
    }
  }
  return rect_number;
}

int max_rectangle(int** rect, int m, int n, int* begin_x, int* begin_y, int* end_x, int* end_y) {
  assert(rect && m > 0 && n > 0 && begin_x && begin_y && end_x && end_y);
  
  if (m > 1) {
    for (int i = m-2; i > -1; i--) {
      for (int j = 0; j < n; j++) {
        if (rect[i][j] == 1 && rect[i+1][j] >=1)
          rect[i][j] += rect[i+1][j];
      }
    }
  }
  int ret_area = 0;
  *begin_x = 0;
  *begin_y = 0;
  *end_x = 0;
  *end_y = 0;
  print_rectangle(rect, m, n);
  for (int i = 0; i < m; i++) {
    stack<int> s_begin_y;
    stack<int> s_height;
    for (int j = 0; j <= n; j++) {
      while (!s_height.empty() && (j<n &&s_height.top() > rect[i][j] || j == n)) {
        int temp_height = s_height.top();
        int temp_begin_y = s_begin_y.top();
        int temp_area = temp_height * (j - temp_begin_y);
        if (ret_area < temp_area) {
          ret_area = temp_area;
          *begin_x = i;
          *begin_y = temp_begin_y;
          *end_x = i + temp_height - 1;
          *end_y = j - 1;
        }
        s_height.pop();
        s_begin_y.pop();
      }
      if (j==n)
        break;
      if (s_height.empty() && rect[i][j] > 0 || !s_height.empty() && s_height.top() <= rect[i][j]) {
        s_height.push(rect[i][j]);
        s_begin_y.push(j);
      }
    }
  }

  return ret_area;
}

int main() {
  int n = 5;
  int m = 5;
  int** rect = new int*[m];
  for (int i = 0; i < m; i++) {
    rect[i] = new int[n]();
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (j <= n/2 && i <= m/2)// && (j & 1) == 0
        rect[i][j] = 1;
    }
  }
  int begin_x = 0;
  int begin_y = 0;
  int end_x = 0;
  int end_y = 0;
  print_rectangle(rect, m, n);
  cout << rect_one_number(rect, m, n) << endl;
  cout << max_rectangle(rect,m,n,&begin_x,&begin_y,&end_x,&end_y) << endl;
  cout << begin_x << '\t' << begin_y << '\t' << end_x << '\t' << end_y << endl;

  for (int i = 0; i < m; i++) {
    delete [] rect[i];
    rect[i] = NULL;
  }
  delete [] rect;
  rect = NULL;
  return 0;
}

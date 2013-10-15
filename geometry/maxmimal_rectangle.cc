// Author: qushuqian
// Problem:Maximal Rectangle Given a 2D binary matrix filled with 0's and 1's, 
// find the largest rectangle containing all ones and return its area.
// solution:
 
#include <iostream>
#include <assert.h>

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
        cout << rect_number << '\t' << begin << '\t' << end << endl;
        last_interval_one = false;
      }
    }
  }
  return rect_number;
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

int main() {
  int n = 5;
  int m = 5;
  int** rect = new int*[m];
  for (int i = 0; i < m; i++) {
    rect[i] = new int[n]();
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if ((i & 1) == 0 || (j & 1) == 0)// && (j & 1) == 0
        rect[i][j] = 1;
    }
  }
  print_rectangle(rect, m, n);
  cout << rect_one_number(rect, m, n) << endl;

  for (int i = 0; i < m; i++) {
    delete [] rect[i];
    rect[i] = NULL;
  }
  delete [] rect;
  rect = NULL;
  return 0;
}

// Author: qushuqian
// Problem: Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'
// solution:
 
#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_int (int i1, int i2) {
  return i1 > i2;
}

int main() {
  bool sudoku[10] = {false};
  for (int i = 0; i < 10; i++) {
    cout << sudoku[i] << '\t';
  }
  bool sus[sizeof(sudoku)];
  cout << endl;
  return 0;
}

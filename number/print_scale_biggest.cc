// Author: qushuqian
// Problem:输入数字n，按顺序输出从1 最大的n 位10 进制数。比如输入3，则输出1、2、3 一直到最大的3
// 位数即999。
// solution:
 
#include <iostream>
#include <assert.h>
#include <stdio.h>

using namespace std;

void print_scale_biggest(int* number, int scale, int current) {
  assert(number && scale > 0 && current >= 0);
  if (current == scale) {
    int i = 0;
    while (i < scale && number[i] == 0)
      i++;
    while (i < scale)
      printf("%d", number[i++]);
    printf("\n");
    return;
  }
  for (int i = 0; i < 10; i++) {
    number[current] = i;
    print_scale_biggest(number, scale, current + 1);
  }
  return;
}

void print_scale_num(int scale) {
  assert(scale > 0);
  int * number = new int[scale]();
//  for (int i = 0; i < scale; i++) {
//    number[i] = 0;
//  }
  print_scale_biggest(number, scale, 0);
  delete [] number;
}

int main() {
  int scale = 2;
  print_scale_num(scale);
  return 0;
}

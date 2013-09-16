#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem: 输入一个正数 n,输出所有和为 n 连续正数序列。
# 例如输入 15,由于 1+2+3+4+5=4+5+6=7+8=15,所以输出 3 个连续序列 1-5、4-6 和 7-8。
# solution: 
# 

import sys

def print_continue(i, j):
  if i >= j:
    sys.exit()
  while i <= j:
    print i,
    i += 1
  print ''  

def continual_integer_sequence(n):
  if n <= 0:
    sys.exit()
  i = 1
  j = 2
  sum_sub = i + j
  while j < n/2+2 and i < j:
    if sum_sub > n:
      sum_sub -= i
      i += 1
    elif sum_sub < n:
      j += 1
      sum_sub += j
    else:
      print_continue(i, j)
      sum_sub -= i
      i += 1
    
  while sum_sub > n and i < j:
    sum_sub -= i
    i += 1
  if sum_sub == n:
    print_continue(i, j)
  return

if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  integer = 15
  print integer, continual_integer_sequence(integer)
  integer = 35
  print integer, continual_integer_sequence(integer)

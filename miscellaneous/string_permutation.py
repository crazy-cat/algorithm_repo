#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem: 输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，则输出由字符a、b、
# c 所能排列出来的所有字符串abc、acb、bac、bca、cab 和cba。
# solution: 
# 

import sys

def permutation(array, index):
  if len(array) <= 1:
    return
  if index == len(array) - 1:
    print array,
    return

  permutation(array, index + 1)
  for i in range(index + 1, len(array)):
    temp = array[index]
    array[index] = array[i]
    array[i] = temp
    permutation(array, index + 1)
    temp = array[index]
    array[index] = array[i]
    array[i] = temp


if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  array = list('abc') 
  print array
  permutation(array, 0)
  array = [1, 2] 
  print array
  permutation(array, 0)

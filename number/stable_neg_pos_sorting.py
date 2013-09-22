#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem:给定大小为n的数组A, A中元素有正有负，给出方法对其排序，要求:
#     1. 负数在前，正数在后
#     2. 正数间相对位置不变
#     3. 负数间相对位置不变
# 时间复杂度为O(n), 空间复杂度为O(1)。
# solution: 
# 

import sys

def stable_sorting_partition(array):
  if len(array) == 1 or len(array) == 0:
    return array
  negative_number = 0
  for i in array:
    if i < 0:
      negative_number += 1
  if negative_number == 0 or negative_number == len(array):
    return array
  j = negative_number
  i = 0
  while i < negative_number and j < len(array):
    if array[i] > 0 and array[j] < 0:
      temp = array[i]
      array[i] = array[j] * -1
      array[j] = -1 * temp
      i += 1
      j += 1
    elif array[i] < 0:
      i += 1
    elif array[j] > 0:
      j += 1
  array_left = stable_sorting_partition(array[:negative_number])
  array_right = stable_sorting_partition(array[negative_number:])
  array = array_left + array_right
  return array

def stable_neg_pos_sorting(array):
  negative_number = 0
  for i in array:
    if i < 0:
      negative_number += 1
  array = stable_sorting_partition(array)
  for i in range(negative_number):
    if (array[i] > 0):
      array[i] = -1 * array[i]
  for i in range(negative_number,len(array)):
    if (array[i] < 0):
      array[i] = -1 * array[i]
  return array

if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  array = [-1, 2, 3, -4, -5]
  print array
  print stable_neg_pos_sorting(array)

  array = [1, -2, -3, -4, -5]
  print array
  print stable_neg_pos_sorting(array)

#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem:
# 给定大小为n的数组A, A中元素有正有负，给出方法对其排序，要求:
#    1. 负数在前，正数在后
#    2. 正数间相对位置不变
#    3. 负数间相对位置不变
# 时间复杂度为O(n), 空间复杂度为O(1)。
# solution: 
# 

import sys

def stable_sort(data_list):
  neg_num = 0
  for i in data_list:
    if i < 0:
      neg_num += 1
  if neg_num == 0 or neg_num == len(data_list):
    return data_list
  i = 0
  j = neg_num
  while i < neg_num and j < len(data_list):
    while i < neg_num and data_list[i] < 0:
      i += 1
    while j < len(data_list) and data_list[j] > 0:
      j += 1
    if i < neg_num and j < data_list:
      temp = data_list[i] * -1
      data_list[i] = data_list[j] * -1
      data_list[j] = temp
      i += 1
      j += 1
  neg_list = stable_sort(data_list[:neg_num])
  positive_list = stable_sort(data_list[neg_num:])
#  print neg_list, positive_list
  return [abs(item) * -1 for item in neg_list] + [abs(item) for item in positive_list]


if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  data_list = [1, 2, -2, 5, -8, -9, 3, 4]
  print data_list, stable_sort(data_list)

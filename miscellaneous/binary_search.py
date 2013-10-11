#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem:
# 从一个有序数组中二分查找指定元素下标
# 改进: 数组中有相同元素时，找最左或最右元素
# solution: 
# 

import sys

def binary_search(data_list, item):
  if not len(data_list): return -1
  low = 0
  high = len(data_list) - 1
  while low < high:
    mid = (high + low) / 2
    if data_list[mid] == item:
      return mid
    elif data_list[mid] > item:
      high = mid - 1
    else:
      low = mid + 1
  return -1

def binary_search_low(data_list, item):
  if not len(data_list): return -1
  low = 0
  high = len(data_list) - 1
  while low < high:
    mid = (high + low) / 2
    if data_list[mid] == item:
      high = mid
    elif data_list[mid] > item:
      high = mid - 1
    else:
      low = mid + 1
  if data_list[low] == item:
    return low
  return -1

def binary_search_high(data_list, item):
  if not len(data_list): return -1
  low = 0
  high = len(data_list) - 1
  while low < high:
    mid = (high + low) / 2 + 1
    if data_list[mid] == item:
      low = mid
    elif data_list[mid] > item:
      high = mid - 1
    else:
      low = mid + 1
  if data_list[low] == item:
    return low
  return -1

if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  data_list = [1, 2, 2, 2, 2, 2, 2, 3, 4]
  item = 2
  print data_list, item, binary_search(data_list, item)
  print data_list, item, binary_search_low(data_list, item)
  print data_list, item, binary_search_high(data_list, item)

#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem:
# 一个int数组，里面数据无任何限制，要求求出所有这样的数a[i]，
# 其左边的数都小于等于它，右边的数都大于等于它。
# 能否只用一个额外数组和少量其它空间实现。
# solution: 
# 

import sys

def find_bottom(data_list):
  if not len(data_list): return []
  max_list = [-1] * len(data_list)
  max_cur = data_list[0] 
  for i in range(len(data_list)):
    if data_list[i] > max_cur:
      max_cur = data_list[i]
    max_list[i] = max_cur 
  
  ret_list = []
  print max_list
  min_cur = data_list[-1]
  i = len(data_list) - 1
  while i > -1:
    if data_list[i] <= min_cur:
      min_cur = data_list[i]
      if data_list[i] >= max_list[i]:
        ret_list.append(data_list[i])
    i -= 1 
  return ret_list

if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  data_list = [1, 2, 5, 6, 8, 7, 9]
  print data_list, find_bottom(data_list)

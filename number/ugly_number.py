#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem:我们把只包含因子2、3 和5 的数称作丑数（Ugly Number）。
# 例如6、8 都是丑数，但14 不是，因为它包含因子7。习惯上我
# 们把1当做是第一个丑数。求按从小到大的顺序的第1500 个丑数。
# solution:
# 

import sys

def ugly_number(index):
  if index <= 0:
    sys.exit()
  ugly_number_list = []  
  ugly_number_list.append(1)
  index_2 = 0
  index_3 = 0
  index_5 = 0
  for i in range(1, index):
    temp_2 = ugly_number_list[index_2] * 2
    temp_3 = ugly_number_list[index_3] * 3
    temp_5 = ugly_number_list[index_5] * 5
    smallest = temp_2
    if smallest > temp_3:
      smallest = temp_3
    if smallest > temp_5:
      smallest = temp_5
    if smallest == temp_2:
      index_2 += 1
    if smallest == temp_3:
      index_3 += 1
    if smallest == temp_5:
      index_5 += 1
    ugly_number_list.append(smallest)
  return ugly_number_list[-1]

if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  integer = 20
  for i in range(1, integer+1):
    print ugly_number(i),

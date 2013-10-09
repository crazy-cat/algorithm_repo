#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem:String's Minimum Repetition Reprentation
# 字符串的循环最小表示
# 字符串bcad, 的循环表示有cadb, adbc, dbca, bcad, 其中按字典序最小的循环最小表示为adbc。
# 给定字符串s, 求最小循环表示。 
# solution: 
# 

import sys

def min_repet_repr(origin):
  i = 0
  j = 1 
  k = 0
  while i < len(origin) and j < len(origin) and k < len(origin):
    if origin[(i+k)%len(origin)] == origin[(j+k)%len(origin)]:
      k = k+1
      continue
    if origin[(i+k)%len(origin)] > origin[(j+k)%len(origin)]:
      i = i + k + 1
    else:
      j = j + k + 1
    if i == j:
      j = j + 1
    k = 0
  return min(i,j)

if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  origin = "bcad"
  print origin
  print min_repet_repr(origin)

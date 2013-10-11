#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem:String's Minimum Repetition Reprentation
# 字符串的循环最小表示
# 字符串bcad, 的循环表示有cadb, adbc, dbca, bcad, 其中按字典序最小的循环最小表示为adbc。
# 给定字符串s, 求最小循环表示。 
# solution: 
# 朴素解法，设置两个指针i,j分别从0，1开始比较以i, j开始的循环串
#            若rs(i) < rs(j) i = j, j++; 否i不变，j++
#            复杂度为O(n^2)
#
#       最小表示法
#            在比较rs(i)和rs(j)的过程中，不妨设在第k次比较时rs(i, k) > rs(j, k)
#            则可以看出,
#                对所有的循环字符串对rs(i + x), rs(j + x), 0 <= x <= k
#                都有rs(i + x) > rs(j + x)
#                因此，i可以直接跳过k个字符, i += (k + 1)
#            时间复杂度为O(n)
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
  origin = "aaacd"
  print origin
  print min_repet_repr(origin)

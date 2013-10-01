#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem: 
# solution: 
# 

import sys

def norm_prex(pattern):
  if len(pattern) == 0:
    return []
  temp = [-1] * len(pattern)
  ret = temp[:]
  k = -1
  i = 1
  for i in range(1, len(pattern)):
    while k >= 0 and pattern[i] != pattern[k+1]:
      k = ret[k]
    if pattern[i] == pattern[k+1]:
      k += 1
    ret[i] = k
  print ret
  return ret

def kmp(origin, pattern):
  if len(origin) < len(pattern) or len(origin) == 0 or len(pattern) == 0:
    sys.exit()
  pre_k = norm_prex(pattern)
  i = 0
  k = -1
  for i in range(len(origin)):
    while k >= 0 and origin[i] != pattern[k+1]:
      k = pre_k[k]
    if origin[i] == pattern[k+1]:
      k += 1
    if k == len(pattern) - 1:
      print i - k
      break

if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  origin = list('ababababc')
  pattern = list('ababc')
  print origin, pattern
  kmp(origin, pattern)


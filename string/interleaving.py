#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem: Interleaving String Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
# For example, Given: s1 = "aabcc", s2 = "dbbca", When s3 = "aadbbcbcac", return true. When s3 = "aadbbbaccc", return false.
# solution: 
# 

import sys


def is_interleaving(a,b,c):
  if len(a) + len(b) != len(c):
    return False
  if len(a) == 0:
    return b==c
  if len(b) == 0:
    return a==c
  if a[0] == c[0] and b[0] == c[0]:
    return (is_interleaving(a[1:], b, c[1:]) or is_interleaving(a, b[1:], c[1:]))
  elif a[0] == c[0] and b[0] != c[0]:
    return is_interleaving(a[1:], b, c[1:])
  elif b[0] == c[0] and a[0] != c[0]:
    return is_interleaving(a, b[1:], c[1:])
  return False

def is_interleave_dp(a, b, c):
  n = len(a)
  m = len(b)
  temp = [False] * (m+1)
  inter = []
  for i in range(n+1):
    inter.append(temp[:])
  inter[n][m] = True
  for i in range(n-1, -1, -1):
    if a[i] == c[m+i] and inter[i+1][m]:
      inter[i][m] = True
  for i in range(m-1, -1, -1):
    if b[i] == c[n+i] and inter[n][i+1]:
      inter[m][i] = True
  for i in range(n-1, -1, -1):
    for j in range(m-1, -1, -1):
      if a[i] == b[j] and a[i] == c[i+j+1]:
        inter[i][j] = (inter[i+1][j] or inter[i][j+1])
      elif a[i] != b[j] and a[i] == c[i+j+1]:
        inter[i][j] = inter[i+1][j]
      elif a[i] != b[j] and b[i] == c[i+j+1]:
        inter[i][j] = inter[i][j+1]
#  for i in range(n+1):
#    print inter[i]
  return inter[0][0]
    

if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  a = "aabcc"
  b = "dbbca"
  c = "aadbbcbcac"
  print a, b, c, is_interleaving(a, b, c)
  print a, b, c, is_interleave_dp(a, b, c)
  c = "aadbbbaccc"
  print a, b, c, is_interleaving(a, b, c)
  print a, b, c, is_interleave_dp(a, b, c)

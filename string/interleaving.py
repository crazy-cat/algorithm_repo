#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem: Interleaving String Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
# For example, Given: s1 = "aabcc", s2 = "dbbca", When s3 = "aadbbcbcac", return true. When s3 = "aadbbbaccc", return false.
# solution:  inter(i, j) says whether s1[0...i-1] and s2[0...j-1] can interleaving s3[0...i+j-1]
# inter(i, j) = inter(i-1, j) or inter(i, j-1) if s1[i-1] == s3[i+j-1] and s2[j-1] == s3[i+j-1]
# inter(i, j) = inter(i-1, j) if s1[i-1] == s3[i+j-1] and s2[j-1] != s3[i+j-1]
# inter(i, j) = inter(i, j-1) if s1[i-1] != s3[i+j-1] and s2[j-1] == s3[i+j-1]
# else iter(i, j) = false
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
  len_a = len(a)
  len_b = len(b)
  len_c = len(c)
  if len_a + len_b != len_c:
    return False
  temp = [False] * (len_b + 1)
  it_dp = []
  for i in range(len_a+1):
    it_dp.append(temp[:])
    
  for i in range(len_a+1):
    for j in range(len_b+1):
      if i == 0 and j == 0:
        it_dp[i][j] = True
      elif i == 0 and b[j-1] == c[j-1] and it_dp[0][j-1]:
        it_dp[i][j] = True
      elif j == 0 and a[i-1] == c[i-1] and it_dp[i-1][0]:
        it_dp[i][j] = True
      elif a[i-1]  == c[i + j - 1] and b[j-1] != c[i+j-1]:
        it_dp[i][j] = it_dp[i-1][j]
      elif b[j-1]  == c[i + j - 1] and a[i-1] != c[i+j-1]:
        it_dp[i][j] = it_dp[i][j-1]
      elif b[j-1]  == c[i + j - 1] and a[i-1] == c[i+j-1]:
        it_dp[i][j] = (it_dp[i][j-1] or it_dp[i-1][j])
#  for i in range(len_a+1):
#    print it_dp[i] 
  return it_dp[len_a][len_b]

#  n = len(a)
#  m = len(b)
#  temp = [False] * (m+1)
#  inter = []
#  for i in range(n+1):
#    inter.append(temp[:])
#  inter[n][m] = True
#  for i in range(n-1, -1, -1):
#    if a[i] == c[m+i] and inter[i+1][m]:
#      inter[i][m] = True
#  for i in range(m-1, -1, -1):
#    if b[i] == c[n+i] and inter[n][i+1]:
#      inter[m][i] = True
#  print ''
#  for i in range(n+1):
#    print inter[i]
#  print ''
#  for i in range(n-1, -1, -1):
#    for j in range(m-1, -1, -1):
#      if a[i] == b[j] and a[i] == c[i+j+1]:
#        inter[i][j] = (inter[i+1][j] or inter[i][j+1])
#      elif a[i] != b[j] and a[i] == c[i+j+1]:
#        inter[i][j] = inter[i+1][j]
#      elif a[i] != b[j] and b[i] == c[i+j+1]:
#        inter[i][j] = inter[i][j+1]
##    print inter[i]
#  for i in range(n+1):
#    print inter[i]
#  return inter[0][0]
    

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

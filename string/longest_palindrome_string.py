#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem: 最长回文子串LPS
# 
# bananas的LPS为"anana"
# cabbad的LPS为"abba"
# 
# 给定字符串，找出其LPS的长度。
# 找出一个LPS。
# 找到所有LPS。
# solution: 
#     LP[i][j] = true，如果 i >= j，即单字符的串和空串都是回文；
#
#     LP[i][j] = true，如果 S[i] = S[j] 并且 LP[i+1][j-1] = true；
#
#     否则，LP[i][j] = false。
# 

import sys

def lps(origin):
  if len(origin) == 0:
    return
  element = [True] * len(origin)
  lp = []
  for i in range(len(origin)):
    lp.append(element[:])
  max_lps = 1
  for m in range(2, len(origin)+1):
    for i in range(len(origin)-m+1):
      j = i + m -1
      lp[i][j] = False 
      if origin[i] == origin[j] and lp[i+1][j-1]:
        lp[i][j] = True
        if max_lps < m:
          max_lps = m
    print lp        
  print max_lps

if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  origin = list('ada')
  print origin
  lps(origin)


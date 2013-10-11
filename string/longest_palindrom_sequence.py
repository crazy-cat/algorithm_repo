#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem: 最长回文子序列
# solution: 
#     LP[i][j] = LP[i+1][j-1]+1 if s[i] = s[j] 
#     LP[i][j] = max(LP[i+1][j], LP[i][j-1]) if s[i] != s[j] 
#

import sys

def lps(origin):
  if len(origin) == 0:
    return

if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  origin = list('ada')
  print origin
  lps(origin)


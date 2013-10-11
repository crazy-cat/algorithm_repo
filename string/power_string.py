#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem: 
# Description
# Given two strings a and b we define a*b to be their concatenation. For example, if a = "abc" and b = "def" then a*b = "abcdef". If we think of concatenation as multiplication, exponentiation by a non-negative integer is defined in the normal way: a^0 = "" (the empty string) and a^(n+1) = a*(a^n).
# 
# Input
# 
# Each test case is a line of input representing s, a string of printable characters. The length of s will be at least 1 and will not exceed 1 million characters. A line containing a period follows the last test case.
# 
# Output
# 
# For each s you should print the largest n such that s = a^n for some string a.
# solution: 利用kmp中的next数组 next[n-1] 
# 假设字符串按照n-next[n-1]划分为123 其中1，2表示长度为n-next[n-1]的字串3的长度可能小于此值
# 则利用next[n-1]可以得出1=2 但是得不出2=3 此时需要判断判断以下字符串长度是否是n-next[n-1]的整数倍
# 

import sys

def power_string(input):
  if len(input) == 0:
    return 0
  next = [-1] * len(input)
  i = 1
  k = -1
  while i < len(input):
    while k >= 0 and input[i] != input[k+1]:
      k = next[k]
    if input[i] == input[k+1]:  
      k += 1
    next[i] = k
    i += 1
  sub_len = len(input) - next[len(input) - 1] - 1
  if len(input) % sub_len == 0:
    print input[:sub_len]
    return len(input) / sub_len
  else:
    print input
    return 1

if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  origin = "aaacd"
  print origin
  print power_string(origin)
  origin = "abab"
  print origin
  print power_string(origin)
  origin = "ababa"
  print origin
  print power_string(origin)
  origin = "aaaaa"
  print origin
  print power_string(origin)

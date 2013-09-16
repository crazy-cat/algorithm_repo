#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem: 输入一个整数，求该整数的二进制表达中有多少个1。例如输入10，由于其二进制表示为1010，有
# 两个1，因此输出2。
# solution: n&(n-1)
# 

import sys

def number_one(integer):
  temp = integer
  ret = 0
  if integer < 0:
    temp *= -1
    ret = 1
  while(temp):
    temp &= (temp-1)
    ret += 1
  return ret  

if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  integer = 4
  print integer, number_one(integer)
  integer = 1
  print integer, number_one(integer)
  integer = 0
  print integer, number_one(integer)
  integer = -1
  print integer, number_one(integer)

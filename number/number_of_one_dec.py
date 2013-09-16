#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem: 输入一个整数n，求从1 到n 这n 个整数的十进制表示中1 出现的次数。 
# 例如输入12，从1 到12 这些整数中包含1 的数字有1，10，11 和12，1 一共出现了5 次。
# solution: 
# 

import sys

def number_of_one(integer):
  if integer < 1:
    sys.exit()
  temp = integer
  ret = 0
  while temp:
    if temp % 10 == 1:
      ret += 1
    temp /= 10  
  return ret

def number_one_brute(integer):
  if integer < 1:
    sys.exit()
  ret = 0  
  for i in range(1, integer + 1):
    ret += number_of_one(i)
  return ret

def number_one_dec_scale(scale):
  if scale < 0:
    sys.exit()
  ten_base = 1  
  for i in range(scale - 1):
    ten_base *= 10
  return ten_base * scale  

def number_one_range(integer):
  if integer < 1:
    sys.exit()
  temp = integer
  scale = 0
  ret = 0
  remainder = 0
  ten_base = 1
  while temp:
    num = temp % 10
    temp /= 10
    if num > 1:
      ret += num * number_one_dec_scale(scale) + ten_base
    elif num == 1:
      ret += remainder + 1 + number_one_dec_scale(scale)
    remainder *= 10
    remainder += num
    ten_base *= 10
    scale += 1
  return ret

if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  integer = 141
  print integer, number_of_one(integer)
  integer = 100
  print integer, number_one_brute(integer)
  integer = 1000
  print integer, number_one_brute(integer)
  integer = 10000
  print integer, number_one_brute(integer), number_one_range(integer)
  print 4, number_one_dec_scale(4)
  integer = 25030
  print integer, number_one_brute(integer), number_one_range(integer)
  integer = 11
  print integer, number_one_brute(integer), number_one_range(integer)

#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem: 输入一个字符串，打印出该字符串中字符的所有zuhe。
# solution: 
# 

import sys

def combination_string(input_str, begin, selected_str):
  if begin == len(input_str):
    print selected_str
    return
  combination_string(input_str, begin + 1, selected_str + input_str[begin])
  combination_string(input_str, begin + 1, selected_str)


if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  input_str = "abc"
  select_str = ""
  combination_string(input_str, 0, select_str)


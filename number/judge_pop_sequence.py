#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem:输入两个整数序列。其中一个序列表示栈的push 顺序，判断另一个序列有没有可能是对应的pop 顺
# 序。为了简单起见，我们假设push 序列的任意两个整数都是不相等的。
# 比如输入的push 序列是1、2、3、4、5，那么4、5、3、2、1 就有可能是一个pop 系列
# solution: 
# 

import sys

def judge_pop_sequence(push_array, pop_array):
  if len(push_array) != len(pop_array):
    sys.exit()
  push_stack = []
  j = 0
  for i in range(len(push_array)):
    while(len(push_stack) > 0 and push_stack[-1] == pop_array[j]):
      push_stack.pop()
      j += 1
    push_stack.append(push_array[i])  
  print push_stack
  while(len(push_stack) > 0 and push_stack[-1] == pop_array[j]):
    push_stack.pop()
    j += 1
  if len(push_stack) == 0:
    return True
  return False

if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  push_array = [1, 2, 3, 4, 5]
  pop_array = [5, 4, 3, 2, 1]
  print push_array, pop_array, judge_pop_sequence(push_array, pop_array)
  push_array = [1, 2, 3, 4, 5]
  pop_array = [5, 3, 4, 2, 1]
  print push_array, pop_array, judge_pop_sequence(push_array, pop_array)
  push_array = [1, 2, 3, 4, 5]
  pop_array = [4, 5, 3, 2, 1]
  print push_array, pop_array, judge_pop_sequence(push_array, pop_array)


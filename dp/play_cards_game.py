#!/usr/bin/python
# coding:utf-8
# Author: qushuqian
# Problem:Consider the following game. A \u0093dealer\u0094 produces a sequence s1,...,sn of \u0093cards,\u0094 face up, where
# each card si has a value vi. Then two players take turns picking a card from the sequence, but
# can only pick the first or the last card of the (remaining) sequence. The goal is to collect cards of
# largest total value. (For example, you can think of the cards as bills of different denominations.)
# Assume n is even.
# Give an O(n2) algorithm to compute an optimal strategy for the first player
# solution: f(i,j) = max{ai +  min {f(i+2,j), f(i+1,j-1)}, aj + min{f(i,j-2), f(i+1,j-1)}}, if i > j
#  f(i,j) = ai, if i == j ; f(i,j) = 0, if i > j;
# 

import sys

def play_cards_game(card_array):
  if (len(card_array)&1) != 0:
    sys.exit()
  f = []
  temp_l = [0] * len(card_array)
  for i in range(len(card_array)):
    f.append(temp_l[:])
  path = []
  temp_l = [-1] * len(card_array)
  for i in range(len(card_array)):
    path.append(temp_l[:])
  for i in range(len(card_array)):
    f[i][i] = card_array[i]
    path.append(i)
  for m in range(2, len(card_array)+1):
    for i in range(len(card_array)-m+1):
      j = i+m-1
      if m == 2:
        if card_array[i] >= card_array[j]:
          f[i][j] = card_array[i]
          path[i][j] = i
        else:
          f[i][j] = card_array[j]
          path[i][j] = j
      else:
        if card_array[i] + min(f[i+2][j],f[i+1][j-1]) > card_array[j] + min(f[i+1][j-1],f[i][j-2]):
          f[i][j] = card_array[i] + min(f[i+2][j],f[i+1][j-1])
          path[i][j] = i
        else:
          f[i][j] = card_array[j] + min(f[i+1][j-1],f[i][j-2])
          path[i][j] = j
  print f[0][-1]
  print path[0][-1]
  print str(f)
  print path

if __name__ == '__main__':
  reload(sys)
  sys.setdefaultencoding('utf8')
  play_cards_game(card_array=[2,3,6,4])

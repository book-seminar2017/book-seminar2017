# !/usr/bin/python
# -*- coding:UTF-8 -*-

import sys
rate=0.0
f = open('input1.txt')
(N, K) = map(int, f.readline().split())
R = map(int, f.readline().split())
R.sort() # 各自sort実装
f.close

x=N-K
for i in range(x,N):
    rate = (rate + R[i])/2.0
print rate

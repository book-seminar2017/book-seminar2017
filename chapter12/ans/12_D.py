# -*- coding: utf-8 -*-
import sys

def assignColor():
    for i in range(n):
        if C[i] == -1:
            DFS(i)

#@profile
def DFS(start):
    S = [start]
    C[start] = start
    while len(S) != 0:
        u = S.pop(0)
        for i in adj_list[u]:
            if C[i] == -1:
                C[i] = start
                S.append(i)

if __name__ == "__main__":
    _input = sys.stdin.readlines()
    n, m = list(map(int, _input[0].split()))
    adj_list = [[] for i in range(n)]
    C = [-1] * n
    
    for i in range(m):
        s, t = list(map(int, _input[i+1].split()))
        adj_list[s].append(t)
        adj_list[t].append(s)
    assignColor()
    q = int(_input[m+1])
    for i in range(q):
        s, t = list(map(int, _input[m+i+2].split()))
        if C[s] == C[t]:
            print("yes")
        else:
            print("no")
            

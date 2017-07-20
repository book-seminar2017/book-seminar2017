# -*- coding: utf-8 -*-

def BFS(adj, start):
    n = len(adj)
    d = [-1] * n
    flag = [0] * n
    Q = []

    Q.append(start)
    d[start] = 0
    flag[start] = 1

    while len(Q) != 0:
        u = Q.pop(0)
        v = [i for i, x in enumerate(adj[u]) if (x == 1) and (flag[i] == 0)] 
        # v := 隣接ノードのうち未探索のノード番号
        
        for i in v:
            Q.append(i)
            d[i] = d[u] + 1
            flag[i] = 1
    
    return d

def main():
    n = int(input())
    adj = [[0 for i in range(n)] for j in range(n)]
    
    for i in range(n):
        tmp = list(map(int, input().split()))
        u = tmp[0]
        u = u -1
        k = tmp[1]
        v = tmp[2:]
        for j in range(k):
            adj[u][v[j]-1] = 1
    
    d = BFS(adj, 0)
    for i in range(n):
        print(i+1, d[i])


if __name__ == "__main__":
    main()

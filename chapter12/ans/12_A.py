# -*- coding: utf-8 -*-
def main():

    n = int(input())
    adj = [[0 for i in range(n)] for j in range(n)]
    
    for i in range(n):
        tmp = list(map(int, input().split()))
        u = tmp[0] - 1 #ノード番号を0オリジンに
        k = tmp[1]
        v = tmp[2:]
        for j in range(k):
            adj[u][v[j]-1] = 1

    for i in adj:
        print(*i)


if __name__ == "__main__":
    main()

import sys

def swap(a,b):
    swap = a
    a = b
    b = swap
    return (a,b)

def bubblesort(R):
    flag = 1
    while flag:
        flag = 0
        for j in reversed(xrange(len(R))):
            if R[j] < R[j-1]:
                R[j], R[j-1] = swap(R[j], R[j-1])
    return R

max_rate = 0.0
f = open("input3.txt")
N, K = f.readline().split()
R = f.readline().split()
bubblesort(R)
print R
f.close

for i in xrange(int(N)-int(K),int(N)):
    max_rate = (max_rate + int(R[i])) / 2.0
print max_rate

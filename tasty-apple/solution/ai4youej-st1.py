import sys
input = sys.stdin.readline

n, q = map(int, input().split())
t = list(map(int, input().split()))
s = list(map(int, input().split()))

ans = s.count(max(s))
for _ in range(q):
    p = int(input())
    if t[0] >= p: print(ans)
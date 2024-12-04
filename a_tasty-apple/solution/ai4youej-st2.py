import sys
input = sys.stdin.readline

n, q = map(int, input().split())
t = list(map(int, input().split()))
s = list(map(int, input().split()))

for _ in range(q):
    p = int(input())
    max_s = -1
    for i in range(n):
        if t[i] >= p: max_s = max(max_s, s[i])
    ans = 0
    for i in range(n):
        if t[i] >= p and s[i] == max_s: ans += 1
    print(ans)
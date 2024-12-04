import sys
input = sys.stdin.readline

n = int(input())
L = [input().rstrip(), input().rstrip()]

# Case 1: First, go right
r, c = 0, 0
dr, dc = 0, 1
while (r, c) != (1, n-1):
    r, c = r + dr, c + dc
    if r < 0 or r > 1 or c < 0 or c > n-1: break
    if L[r][c] == "L":
        if dr != 0: dr, dc = 0, 1
        elif r == 0: dr, dc = 1, 0
        else: dr, dc = -1, 0
poss1 = (r, c) == (1, n-1)

# Case 2: First, go down
r, c = 0, 0
dr, dc = 1, 0
while (r, c) != (1, n-1):
    r, c = r + dr, c + dc
    if r < 0 or r > 1 or c < 0 or c > n-1: break
    if L[r][c] == "L":
        if dr != 0: dr, dc = 0, 1
        elif r == 0: dr, dc = 1, 0
        else: dr, dc = -1, 0
poss2 = (r, c) == (1, n-1)

print("YES" if poss1 or poss2 else "NO")

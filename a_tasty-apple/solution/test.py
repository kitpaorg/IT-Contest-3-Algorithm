n, q = map(int, input().split())
taste = list(map(int, input().split()))
size = list(map(int, input().split()))
ts = []
for i in range(n):
    ts.append([taste[i], size[i]])
apple_t = [0 for i in range(200002)] #개수
apple_s = [0 for i in range(200002] #최대사이즈
ts.sort(key = lambda x : x[1], reverse = True)

apple_t[1] = 1
apple_t[ts[0][0] + 1] = -1
apple_s[1] = ts[0][1]
apple_s[ts[0][0]] = ts[0][1]
last_max = ts[0][1]
last_po = ts[0][0]

for i in range(1,n):
    at, az = ts[i][0], ts[i][1]
    if apple_s[1] == az:
        apple_t[1] += 1
        apple_t[at + 1] -= 1
        apple_s[at] = az
        if last_po < at:
            last_po = at
    else:
        if last_po <= at:
            if last_max == az:
                apple_t[last_po] += 1
                apple_t[at + 1] -= 1
                apple_s[at] = az
            else:
                apple_t[last_po + 1] += 1
                apple_s[last_po + 1] = az
                apple_t[at + 1] -= 1
                last_max = az
            if last_po < at:
                last_po = at

    print(apple_s)
    print(apple_t)
    print()

for i in range(2, n + 1):
    apple_t[i] += apple_t[i - 1]
for i in range(q):
    k = int(input())
    print(apple_t[k])

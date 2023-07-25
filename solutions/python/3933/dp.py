MAXN = 32768
DP = [[0 for j in range(MAXN)] for i in range(5)]
DP[0][0] = 1
for i in range(1, MAXN):
    if i * i >= MAXN:
        break
    for j in range(i * i, MAXN):
        for k in range(1, 5):
            DP[k][j] += DP[k - 1][j - i * i]
for i in range(MAXN):
    for j in range(4):
        DP[4][i] += DP[j][i]
while True:
    N = int(input())
    if N == 0:
        break
    print(DP[4][N])

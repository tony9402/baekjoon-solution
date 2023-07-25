import sys

input = lambda: sys.stdin.readline().rstrip()
N = int(input())
D = {}
for i in range(N):
    S = input()
    ext = S[S.rfind(".") + 1 :]
    D[ext] = D.get(ext, 0) + 1
result = sorted(D.items())
for x in result:
    print(*x)

import sys
from collections import defaultdict, deque

input = lambda: sys.stdin.readline().rstrip()
G = defaultdict(list)
N, M, K, X = map(int, input().split())
for i in range(M):
    u, v = map(int, input().split())
    G[u].append(v)

dist = [-1] * (N + 1)
dist[X] = 0
Q = deque([X])
while Q:
    cur = Q.popleft()
    for nxt in G[cur]:
        if dist[nxt] == -1:
            dist[nxt] = dist[cur] + 1
            Q.append(nxt)
result = [idx for idx, x in enumerate(dist) if x == K]
if len(result):
    print(*result)
else:
    print(-1)

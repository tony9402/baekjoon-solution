import sys
from typing import List


def input() -> str:
    return sys.stdin.readline().rstrip()


# check a > b
def compare(a: List[int], b: List[int]):
    if a[0] > b[0]:
        return True
    if a[0] == b[0] and (a[1] > b[1]):
        return True
    return False


def solution(N: int, S: List[str]) -> List[str]:
    V = sorted([(x, idx) for idx, x in enumerate(S)])

    pre, mx = -1, -1
    ans, cur = [-1, -1], [-1, -1]
    for i in range(1, N):
        cnt = 0
        while cnt < min(len(V[i - 1][0]), len(V[i][0])):
            if V[i - 1][0][cnt] != V[i][0][cnt]:
                break
            cnt += 1
        if pre != cnt:
            pre = cnt
            cur = [V[i - 1][1], V[i][1]]
        elif cur[1] > V[i][1]:
            cur[1] = V[i][1]
        if cur[0] > cur[1]:
            cur[0], cur[1] = cur[1], cur[0]
        if mx < cnt or (mx == cnt and compare(ans, cur)):
            mx = cnt
            ans = cur

    return [S[ans[0]], S[ans[1]]]


if __name__ == "__main__":
    N = int(input())
    S = [input() for i in range(N)]
    answer = solution(N, S)
    print("\n".join(answer))

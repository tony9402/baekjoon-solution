import sys
from typing import List

def input() -> str:
    return sys.stdin.readline().rstrip()


def get_next(N: int) -> int:
    ret = 0
    while N > 0:
        x = N % 10
        ret += x * x
        N //= 10
    return ret


def get_sequence(N: int) -> List[int]:
    cur = N
    ret, used = [cur], {cur,}
    while True:
        nxt = get_next(cur)
        if nxt in used: break
        used.add(nxt)
        ret.append(nxt)
        cur = nxt
    return ret


def solution(A: int, B: int) -> int:
    answer, mn = 0, 10**9
    flag = False
    seqA, seqB = get_sequence(A), get_sequence(B)
    d = {x:idx for idx, x in enumerate(seqA, 1)}
    for x in seqB:
        answer += 1
        mn = min(mn, answer + d.get(x, 10 ** 9))
    answer = 0 if mn == 10 ** 9 else mn
    return answer


if __name__ == "__main__":
    answer = []
    while True:
        x, y = map(int, input().split())
        if x == 0 and y == 0: break
        answer.append(f"{x} {y} {solution(x, y)}")
    print('\n'.join(answer))
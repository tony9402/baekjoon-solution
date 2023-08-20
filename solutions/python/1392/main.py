import sys
from typing import List

def input() -> str:
    return sys.stdin.readline().rstrip()


def solution(arr: List[int], query: List[int]) -> List[int]:
    times = []
    for idx, x in enumerate(arr, 1):
        times.extend([idx] * x)
    answer = [times[x] for x in query]
    return answer


if __name__ == "__main__":
    N, Q = map(int, input().split())
    arr: List[int] = [int(input()) for i in range(N)]
    query: List[int] = [int(input()) for i in range(Q)]
    answer = solution(arr, query)
    print('\n'.join(map(str, answer)))
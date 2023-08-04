import sys
from typing import List


def input() -> str:
    return sys.stdin.readline().rstrip()


Objects: List[List[str]] = [
    ["kor", "eng", "math"],
    ["apple", "pear", "orange"],
    ["red", "blue", "green"],
]


def get_index(type: int, value: str) -> int:
    for i in range(3):
        if Objects[type][i] == value:
            return i
    return -1


def solution(
    N: int, M: int, preference: List[List[str]], query: List[List[str]]
) -> List[int]:
    cnt: List[List[List[int]]] = [
        [[0 for k in range(3)] for j in range(3)] for i in range(3)
    ]

    for x, y, z in preference:
        idx_x = get_index(0, x)
        idx_y = get_index(1, y)
        idx_z = get_index(2, z)
        cnt[idx_x][idx_y][idx_z] += 1

    answer: List[int] = []
    for x, y, z in query:
        idx_x = get_index(0, x)
        idx_y = get_index(1, y)
        idx_z = get_index(2, z)
        range_x = range(0, 3) if idx_x == -1 else [idx_x]
        range_y = range(0, 3) if idx_y == -1 else [idx_y]
        range_z = range(0, 3) if idx_z == -1 else [idx_z]
        ans = 0
        for i in range_x:
            for j in range_y:
                for k in range_z:
                    ans += cnt[i][j][k]
        answer.append(ans)
    return answer


if __name__ == "__main__":
    N, M = map(int, input().split())  # type: (int, int)
    preference: List[List[str]] = [input().split() for i in range(N)]
    query: List[List[str]] = [input().split() for i in range(M)]
    answer: List[int] = solution(N, M, preference, query)
    answer = "\n".join(map(str, answer))
    print(answer)

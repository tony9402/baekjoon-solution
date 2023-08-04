import sys
from typing import Tuple


def input() -> str:
    return sys.stdin.readline().rstrip()


Dy: Tuple[int, ...] = (1, 0, -1, 0)
Dx: Tuple[int, ...] = (0, 1, 0, -1)


def solution(S: str) -> int:
    X, Y = [0, 0], [0, 0]
    dir, y, x = 0, 0, 0
    for ch in S:
        if ch == "R":
            dir = (dir + 1) % 4
        elif ch == "L":
            dir = (dir + 3) % 4
        elif ch == "F":
            y, x = y + Dy[dir], x + Dx[dir]
        else:
            y, x = y - Dy[dir], x - Dx[dir]
        X[0], X[1] = min(X[0], x), max(X[1], x)
        Y[0], Y[1] = min(Y[0], y), max(Y[1], y)
    return (Y[1] - Y[0]) * (X[1] - X[0])


if __name__ == "__main__":
    T = int(input())
    S = [input() for i in range(T)]
    answer = [solution(x) for x in S]
    answer = map(str, answer)
    print("\n".join(answer))

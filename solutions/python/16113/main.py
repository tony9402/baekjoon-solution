import sys
from typing import List


def input() -> str:
    return sys.stdin.readline().rstrip()


Digits: List[List[str]] = [
    ["###", "#.#", "#.#", "#.#", "###"],
    ["#", "#", "#", "#", "#"],
    ["###", "..#", "###", "#..", "###"],
    ["###", "..#", "###", "..#", "###"],
    ["#.#", "#.#", "###", "..#", "..#"],
    ["###", "#..", "###", "..#", "###"],
    ["###", "#..", "###", "#.#", "###"],
    ["###", "..#", "..#", "..#", "..#"],
    ["###", "#.#", "###", "#.#", "###"],
    ["###", "#.#", "###", "..#", "###"],
]


def solution(N: int, S: str) -> List[int]:
    w = len(S) // 5
    signal: List[str] = [S[i : i + w] for i in range(0, N, w)]
    idx: List[int] = [-1]
    for i in range(w):
        flag = True
        for j in range(5):
            if signal[j][i] != ".":
                flag = False
        if flag:
            idx.append(i)
    idx.append(w)
    answer: List[int] = []
    for i in range(1, len(idx)):
        l, r = idx[i - 1], idx[i]
        if r - l - 1 <= 0:
            continue
        for digit in range(10):
            flag = True
            for j in range(5):
                if Digits[digit][j] != signal[j][l + 1 : r]:
                    flag = False
            if flag:
                answer.append(digit)
                break
    return answer


if __name__ == "__main__":
    N = int(input())
    S = input()
    answer = solution(N, S)
    answer = "".join(map(str, answer))
    print(answer)

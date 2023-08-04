import sys


def input() -> str:
    return sys.stdin.readline().rstrip()


def solution(S: str) -> int:
    N = len(S)
    cntA = S.count("a")
    S = S + S
    ans = N + 1
    cntB = 0
    right = -1
    for i in range(N):
        while right + 1 < i + cntA:
            right += 1
            if S[right] == "b":
                cntB += 1
        ans = min(ans, cntB)
        if S[i] == "b":
            cntB -= 1
    return ans


if __name__ == "__main__":
    S = input()
    answer = solution(S)
    print(answer)

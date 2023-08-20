import sys

def input() -> str:
    return sys.stdin.readline().rstrip()


def solution(S: str) -> int:
    ans, cnt = 0, 1
    for i in range(1, len(S)):
        if ord(S[i]) - ord(S[i - 1]) == 1:
            cnt += 1
        else:
            if cnt == 3: ans += 1
            cnt = 1
    if cnt == 3: ans += 1
    return ans


if __name__ == "__main__":
    S = input()
    answer = solution(S)
    print(answer)
import sys

def input() -> str:
    return sys.stdin.readline().rstrip()


def solution(A: str, B: str, K: int) -> int:
    N, M = len(A), len(B)
    DP = [[0 for j in range(M + 1)] for i in range(N + 1)]
    cal = lambda x, y: K if x < 0 or y < 0 else abs(ord(A[x]) - ord(B[y]))
    for i in range(N + 1):
        for j in range(M + 1):
            if i == 0 and j == 0: continue
            DP[i][j] = 10 ** 9
            if i > 0 and j > 0:
                DP[i][j] = min(DP[i][j], DP[i - 1][j - 1] + cal(i - 1, j - 1))
            if i > 0:
                DP[i][j] = min(DP[i][j], DP[i - 1][j] + cal(i - 1, -1))
            if j > 0:
                DP[i][j] = min(DP[i][j], DP[i][j - 1] + cal(-1, j - 1))
    return DP[N][M]


if __name__ == "__main__":
    A: str = input()
    B: str = input()
    K: int = int(input())
    answer = solution(A, B, K)
    print(answer)
import sys

def input() -> str:
    return sys.stdin.readline().rstrip()


def solution(A: list[int], B: list[int]) -> list[int]:
    N = len(A)
    answer1, answer2, mx = 0, 0, -2 * 10 ** 9
    for i in range(2 * N):
        L, R = i // 2, (i + 1) // 2
        S = 0 if L != R else -A[L] * B[R]
        while L >= 0 and R < N:
            S += A[L] * B[R] + A[R] * B[L]
            if S > mx:
                answer1, answer2, mx = L, N - R - 1, S
            L, R = L - 1, R + 1
    return [answer1, answer2, mx]

if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    answer: list[int] = solution(A, B)
    print(*answer)
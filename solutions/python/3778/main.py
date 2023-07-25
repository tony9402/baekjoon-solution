import sys

input = lambda: sys.stdin.readline().rstrip()
T = int(input())
for tc in range(T):
    S, T = input(), input()
    cntS, cntT = {}, {}
    for ch in range(ord("a"), ord("z") + 1):
        cntS[chr(ch)] = 0
    for ch in S:
        cntS[ch] = cntS.get(ch, 0) + 1
    for ch in T:
        cntT[ch] = cntT.get(ch, 0) + 1

    answer = 0
    for k, valueS in cntS.items():
        valueT = cntT.get(k, 0)
        answer += valueS + valueT - 2 * min(valueS, valueT)
    print(f"Case #{tc+1}: {answer}")

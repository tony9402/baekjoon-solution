Dy = (-1, 1, 0, 0, -1, -1, 1, 1)
Dx = (0, 0, -1, 1, -1, 1, -1, 1)

N = int(input())
B = [input() for i in range(N)]

ansy, ansx, mx = -1, -1, 0
for i in range(N):
    for j in range(N):
        if B[i][j] != ".":
            continue
        ret = 0
        for dy, dx in zip(Dy, Dx):
            y, x = i, j
            cur = 0
            while True:
                y, x = y + dy, x + dx
                if not (0 <= y < N and 0 <= x < N) or B[y][x] == ".":
                    cur = 0
                    break
                if B[y][x] == "B":
                    break
                cur += 1
            ret += cur
        if ret > mx:
            mx = ret
            ansy, ansx = i, j

print("PASS" if mx == 0 else f"{ansx} {ansy}\n{mx}")

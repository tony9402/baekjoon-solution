N = int(input())
L, R = 1, 2

while L > N or N >= R:
    L *= 2
    R *= 2

print(L)

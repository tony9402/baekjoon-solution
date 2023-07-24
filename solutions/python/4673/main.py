def d(n):
    Sum = n
    while n != 0:
        Sum += n % 10
        n //= 10
    if Sum > 10000:
        Sum = 0
    return Sum


N = 10000
chk = [0] * (N + 1)
for i in range(N + 1):
    chk[d(i)] = 1

print("\n".join([f"{idx}" for idx, x in enumerate(chk) if x != 1]))

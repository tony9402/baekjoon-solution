N = int(input())
arr = [i for i in range(N + 1)]

while N != 1:
    idx = 1
    for i in range(2, N + 1, 2):
        arr[idx] = arr[i]
        idx += 1
    N = idx - 1

print(arr[1])

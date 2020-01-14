def PlusOne(digits):
    sums = 0
    for x in digits:
        sums = sums * 10 + x
    sumstr = str(sums + 1)
    return [int(j) for j in sumstr]


if __name__ == '__main__':
    print(PlusOne(input()))

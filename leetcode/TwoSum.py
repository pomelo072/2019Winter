def TwoSum(nums, target):
    TSum = {}
    for i, num in enumerate(nums):
        if TSum.get(target - int(num)) is not None:
            return [i, TSum.get(target - int(num))]
        TSum[num] = i


if __name__ == "__main__":
    a = input()
    li = []
    for x in a[1:-1].split(','):
        li.append(int(x))
    print(TwoSum(li, int(input())))

low = int(input())
high = int(input())

mid = low + (high - low)//2
print(mid)

while True:
    case = input()
    
    if case == '<':
        # print("less")
        high = mid - 1
    elif case == '>':
        low = mid + 1
        # print("high")
    else:
        print("result: " + str(mid))
        break
    mid = low + (high - low)//2
    print(mid)

    # jasdhjkasdh
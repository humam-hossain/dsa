def min_operations(n):
    dp = [float('inf')] * (n+1)
    prev = [0] * (n+1)
    dp[1] = 0

    for i in range(1, n):
        if dp[i+1] > dp[i]+1:
            dp[i+1] = dp[i]+1
            prev[i+1] = i
        if i*2 <= n and dp[i*2] > dp[i]+1:
            dp[i*2] = dp[i]+1
            prev[i*2] = i
        if i*3 <= n and dp[i*3] > dp[i]+1:
            dp[i*3] = dp[i]+1
            prev[i*3] = i

    # construct the sequence of operations
    sequence = []
    curr = n
    while curr != 1:
        if curr == prev[curr]+1:
            sequence.append('add 1')
        elif curr == prev[curr]*2:
            sequence.append('multiply by 2')
        elif curr == prev[curr]*3:
            sequence.append('multiply by 3')
        curr = prev[curr]

    # print the sequence of operations in reverse order
    print(' -> '.join(reversed(sequence)))
    return dp[n]


print(min_operations(20))
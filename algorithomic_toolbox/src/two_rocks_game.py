def calculate_next_move(pile1, pile2, memo):
    if pile1 == 0 and pile2 == 0:
        return None
    if memo[pile1][pile2] is not None:
        return memo[pile1][pile2]

    if pile1 > 0:
        if calculate_next_move(pile1 - 1, pile2, memo) is None:
            memo[pile1][pile2] = (1, 0)
            return memo[pile1][pile2]
    if pile2 > 0:
        if calculate_next_move(pile1, pile2 - 1, memo) is None:
            memo[pile1][pile2] = (2, 0)
            return memo[pile1][pile2]
    if pile1 > 0 and pile2 > 0:
        if calculate_next_move(pile1 - 1, pile2 - 1, memo) is None:
            memo[pile1][pile2] = (3, 0)
            return memo[pile1][pile2]

    for i in range(1, pile1 + 1):
        if calculate_next_move(pile1 - i, pile2, memo)[1] == 0:
            memo[pile1][pile2] = (1, i)
            return memo[pile1][pile2]
    for i in range(1, pile2 + 1):
        if calculate_next_move(pile1, pile2 - i, memo)[1] == 0:
            memo[pile1][pile2] = (2, i)
            return memo[pile1][pile2]
    for i in range(1, min(pile1, pile2) + 1):
        if calculate_next_move(pile1 - i, pile2 - i, memo)[1] == 0:
            memo[pile1][pile2] = (3, i)
            return memo[pile1][pile2]

    memo[pile1][pile2] = (1, 0)
    return memo[pile1][pile2]


pile1 = 10
pile2 = 10
memo = [[None for _ in range(pile2 + 1)] for _ in range(pile1 + 1)]
print("Initial piles:", pile1, pile2)

while True:
    opponent_move = int(input("Opponent move (1 or 2 or 3): "))
    if opponent_move == 1:
        pile1 -= 1
    elif opponent_move == 2:
        pile2 -= 1
    else:
        pile1 -= 1
        pile2 -= 1

    print("Current piles:", pile1, pile2)
    if pile1 == 0 and pile2 == 0:
        print("You win!")
        break

    next_move = calculate_next_move(pile1, pile2, memo)
    print("Your suggested move (1 or 2 or 3):", next_move[0])
    if next_move[0] == 1:
        pile1 -= next_move[1]
    elif next_move[0] == 2:
        pile2 -= next_move[1]
    else:
        pile1 -= next_move[1]
        pile2 -= next_move[1]

    print("Current piles:", pile1, pile2)
    if pile1 == 0 and pile2 == 0:
        print("You lose!")
        break

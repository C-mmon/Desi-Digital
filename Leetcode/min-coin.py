def min_coins(n):
    coins = [25, 10, 5, 1]
    num_coins = 0

    for coin in coins:
        num_coins += n // coin
        n %= coin

    return num_coins

# Example
n = 16
result = min_coins(n)
print(f"The minimum number of coins required to make {n} cents is: {result}")

import math
def sellStock(arr):
    if len(arr) < 2:
        return (math.inf, -math.inf, 0)  # Base case: no profit possible
    
    mid = len(arr) // 2
    left_arr = arr[:mid]
    right_arr = arr[mid:]

    # Recursively find best buy, sell, and profit in left and right halves
    (b1, s1, p1) = sellStock(left_arr)
    (b2, s2, p2) = sellStock(right_arr)

    # Find the best cross-subarray profit
    min_left = min(left_arr)  # Minimum buy price in the left half
    max_right = max(right_arr)  # Maximum sell price in the right half
    cross_profit = max_right - min_left  # Profit if we buy in left and sell in right

    # Choose the best overall profit
    best_profit = max(p1, p2, cross_profit)

    # Determine best buy/sell prices for this segment
    best_buy = min(b1, b2, min_left)
    best_sell = max(s1, s2, max_right)

    return best_buy, best_sell, best_profit

# Example usage:
prices = [7, 1, 5, 3, 6, 4]
print(sellStock(prices))  # Expected output: (1, 6, 5)

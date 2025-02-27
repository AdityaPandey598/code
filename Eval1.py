def max_crossing_profit(prices, start, mid, end):
    left_min = float('inf')
    for i in range(start, mid + 1):
        left_min = min(left_min, prices[i])
    
    right_max = float('-inf')
    for i in range(mid + 1, end + 1):
        right_max = max(right_max, prices[i])
    
    return right_max - left_min

def max_profit(prices, start, end):
    if start >= end:
        return 0
    
    mid = (start + end) // 2
    
    left_profit = max_profit(prices, start, mid)
    right_profit = max_profit(prices, mid + 1, end)
    cross_profit = max_crossing_profit(prices, start, mid, end)
    
    return max(left_profit, right_profit, cross_profit)

def find_max_profit(prices):
    if not prices:
        return 0
    
    return max_profit(prices, 0, len(prices) - 1)

# Example usage
prices = [10, 18, 26, 31, 4, 53, 69]
print("Maximum profit:", find_max_profit(prices))

def calc_sum(*nums):
    total = 0
    for num in nums:
        total += num
    print("Total da soma:", total)

# Example usage:
if __name__ == "__main__":
    calc_sum(1, 2, 3)  # Prints: Total da soma: 6
    calc_sum(10, 20)   # Prints: Total da soma: 30
    calc_sum()         # Prints: Total da soma: 0
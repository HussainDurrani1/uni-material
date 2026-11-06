def recursive_sum(numbers):
    # Base Case: Empty sequence sum is 0
    if not numbers:
        return 0

    # Recursive Step: head + recursive_sum(tail)
    return numbers[0] + recursive_sum(numbers[1:])

scores = [10, 20, 30, 40]
print("Total Sum:", recursive_sum(scores))  # Output: 100
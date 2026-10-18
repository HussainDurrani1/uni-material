# Slicing Example in Python

nums = [10, 20, 30, 40, 50, 60]

print(nums[1:4])   # [20, 30, 40] -> From index 1 to 3
print(nums[:3])    # [10, 20, 30] -> First three
print(nums[::2])   # [10, 30, 50] -> Every second element
print(nums[::-1])  # [60, 50, 40, 30, 20, 10] -> Reverse (The C++ "Aha!" moment)

nums2 = nums[::-2]
print(nums2)       # [60, 40, 20] -> Every second element in reverse order stored in another list  
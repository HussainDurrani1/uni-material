
# iterator class defnes next() function

nums = [10, 20, 30, 70]
it = iter(nums)         # returns an iterator for the list nume

print(next(it)) # 10
print(next(it)) # 20
print(next(it)) # 30
print(next(it)) # 70

print(next(it)) # Raises StopIteration
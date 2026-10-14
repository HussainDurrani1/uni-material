
# Generator
def fibonacci_gen(limit):
    a, b = 0, 1
    count = 0
    while count < limit:
        yield a
        a, b = b, a + b
        count += 1

# This does NOT store 1 million numbers in RAM
for num in fibonacci_gen(1000000):
    if num > 100: break
    print(num)
    
    
#    f(n) = f(n-1) + f(n-2)


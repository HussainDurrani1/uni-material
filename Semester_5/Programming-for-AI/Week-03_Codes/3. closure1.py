
# Closure: Datahiding /  encapsulation without using a class

def make_multiplier(n):
    
    def multiplier(x):
        return x * n    # x = 10, n = 3
    return multiplier

times3 = make_multiplier(3)

print(times3(10)) # 30 (Remembers that n was 3)

# print(type(times3))


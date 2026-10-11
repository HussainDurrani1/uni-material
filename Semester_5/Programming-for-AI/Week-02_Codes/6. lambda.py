# Standard function
def add(x, y): return x + y
print("Regular Function: ", add(5, 7))


def indirectFunction(a, b, func_name):
    val = func_name(a, b)
    return val

# Lambda equivalent
add_lambda = lambda x, y: x + y

print("Lambda Function: ", indirectFunction(5, 7, add_lambda))

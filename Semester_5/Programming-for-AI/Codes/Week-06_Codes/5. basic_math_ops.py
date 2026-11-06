
import numpy as np

# Allocates contiguous 1D memory buffers of 3 elements each (default int64 on 64-bit platforms)
a = np.array([1, 2, 3])
b = np.array([4, 5, 6])

# Vectorized element-wise addition: executes in compiled C across aligned memory buffers without a Python loop
print(a + b)  # [5, 7, 9]

# Vectorized element-wise multiplication: computes Hadamard product (a[i] * b[i]), not a linear algebra dot product
print(a * b)  # [4, 10, 18]

# Broadcasting scalar addition: expands scalar 5 across array 'a' internally without allocating extra memory
print(a + 5)

# Vectorized power operation: calculates a[i] ** 2 for every element in-place via C routines
print(a ** 2) # [1, 4, 9] (Square each element)

# Allocates a new contiguous memory array of size 4 and copies all elements; unlike Python list.append, this is an O(N) reallocation, not amortized O(1)
b = np.append(b, 10)

# Exception block to demonstrate shape mismatch in broadcasting
try:
    # Fails because shape (3,) cannot be aligned or stretched to match shape (4,) under NumPy broadcasting rules
    print(a + b)
except Exception as e:
    # Catches and prints ValueError: operands could not be broadcast together with shapes (3,) (4,)
    print(e)
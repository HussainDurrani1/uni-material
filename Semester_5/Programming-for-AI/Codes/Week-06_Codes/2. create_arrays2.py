import numpy as np

# Allocates contiguous memory for a 3x3 matrix and zeroes all bytes; defaults to float64
a1 = np.zeros((3,3))

# Allocates contiguous memory for a 2x2 matrix and initializes all elements to 1.0 (float64)
a2 = np.ones((2,2))

# Vectorized scalar multiplication: multiplies every element in the 2x2 ones array by 5 via C loops
a3 = 5 * np.ones((2,2))

# Directly creates a 2x2 array filled with value 7 without an extra multiplication step; infers int dtype from fill value
a4 = np.full((2,2), 7)

# Allocates raw memory without initializing bytes; faster than zeros/ones but contains uninitialized garbage values from RAM
a5 = np.empty((2,2))

# Prints 3x3 matrix of 0.
print(a1)

# Prints 2x2 matrix of 1.
print(a2)

# Prints 2x2 matrix of 5.
print(a3)

# Prints 2x2 matrix of integer 7s
print(a4)

# Prints 2x2 matrix containing arbitrary residual memory data
print(a5)
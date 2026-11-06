import numpy as np

# Allocates contiguous 2D memory buffer of shape (3, 4) with 12 homogeneous int64 elements stored in C-order
matrix = np.array([[1, 2, 3, 4], [4, 5, 6, 5], [7, 8, 9, 6]])

# Flattens the array conceptually and reduces all 12 elements down to a single scalar sum (1+2+...+6 = 60)
print("Sum", np.sum(matrix)) # 60

# Collapses dimension 0 (rows): iterates downwards across rows to produce column-wise sums of shape (4,): [12, 15, 18, 15]
print("Axis 0 Sum", np.sum(matrix, axis=0))

# Collapses dimension 1 (columns): iterates across columns to produce row-wise sums of shape (3,): [10, 20, 30]
print("Axis 1 Sum", np.sum(matrix, axis=1))

# Negative indexing targets the last axis (axis=1 for a 2D matrix); behaves identically to axis=1, collapsing columns to yield [10, 20, 30]
print("Axis -1 Sum", np.sum(matrix, axis=-1))
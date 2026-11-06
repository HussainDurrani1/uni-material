import numpy as np

# 1D Array: allocates a contiguous C-style buffer in memory with homogeneous int64 type
arr_1d = np.array([10, 20, 30])

# 2D Array (Matrix): flattens the nested lists into a single continuous row-major (C-order) memory block of shape (3, 2)
matrix = np.array([[1, 2], [3, 4], [5, 6]]) 

# 3D Array: allocates a contiguous block of 12 elements (2 layers/slices, 3 rows, 2 columns) initialized to 0.0 (float64 by default)
arr_3d = np.zeros((2, 3, 2))

# Print 1D array: formats as clean space-delimited elements [10 20 30] without commas
print(arr_1d)

# Print 2D array: outputs structured rows and columns reflecting its 2D grid shape
print(matrix)

# Print ND array: outputs nested dimensional blocks representing higher-dimensional slices
print(arr_3d)

# Data type inspection: .dtype is an ndarray attribute (not a standalone function) returning the underlying C data type (float64)
print(arr_3d.dtype)
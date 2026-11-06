
# ATTRIBUTES OF NUMPY ARRAY

import numpy as np

# A 2D Matrix (3 rows, 2 columns)
data = np.array([[10, 20], [30, 40], [50, 60]])

print(f"Shape: {data.shape}") # (3, 2)
print(f"Size:  {data.size}")  # 6
print(f"Dims:  {data.ndim}")  # 2
print(f"Type:  {data.dtype}") # int64 (on most systems)
print(f"Type:  {data.itemsize}") # 8 Bytes
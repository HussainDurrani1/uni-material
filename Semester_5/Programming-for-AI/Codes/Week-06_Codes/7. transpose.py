
import numpy as np

# Swap rows and columns
original = np.array([[1, 2, 3, 4], [5, 6, 7, 8]])
# original.shape is (2, 4)

print(original)

transposed = original.T 
# transposed.shape is (4, 2)

print(transposed)
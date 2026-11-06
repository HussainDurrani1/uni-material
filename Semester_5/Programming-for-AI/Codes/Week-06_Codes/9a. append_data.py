
import numpy as np

# Allocates an immutable, contiguous 1D memory buffer of 3 elements (int64) with fixed capacity
base = np.array([1, 2, 3])

# Unlike Python list.append which mutates in-place with over-allocated capacity, 
# np.append allocates a brand-new contiguous buffer of size 5 and copies all elements (O(N) cost); 'base' remains completely unmodified
new_arr = np.append(base, [4, 5])

# Prints the newly allocated 5-element array: [1 2 3 4 5]
print(new_arr)
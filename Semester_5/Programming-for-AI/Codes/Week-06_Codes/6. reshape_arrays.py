
import numpy as np

# Create a 1D array of 12 elements
raw_data = np.arange(12) # [0, 1, 2... 11]

# Reshape to 3 rows, 4 columns
grid = raw_data.reshape(3, 4)

# Reshape to 3D (2 layers, 3 rows, 2 columns)
cube = raw_data.reshape(2, 3, 2)

# The "-1" Trick: "Hey NumPy, you figure out this dimension for me"
# If I want 2 rows, NumPy calculates 6 columns automatically
auto_grid = raw_data.reshape(2, -1) 

# Flatten: Back to 1D
flat = grid.ravel()
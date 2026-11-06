import numpy as np

# Generates values from [start, stop) with fixed step 2; result is [0, 2, 4, 6, 8]
a1 = np.arange(0, 10, 2)

# Generates exactly 100 evenly spaced points from 0.0 to 1.0 (both endpoints included by default)
a2 = np.linspace(0, 1, 100)
#print(a2)

# Special cases

# NumPy casts step=0.5 to int (step=0) before running the loop, while length is computed as ceil((5-0)/0.5)=10; yields an array of 10 zeros
x1 = np.arange(0, 5, 0.5, dtype=int)
print(x1)

# Truncates toward zero during integer casting; negative steps round toward zero (-2.5 -> -2), distorting spacing
x2 = np.arange(-3, 3, 0.5, dtype=int)
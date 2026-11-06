
import numpy as np

# Signal Gain ---
def apply_gain(signal, factor):
    return signal * factor

raw_signal = np.array([0.1, 0.2, 0.5, 0.1])
amplified = apply_gain(raw_signal, 10)
print(f"Amplified: {amplified}") # [1. 2. 5. 1.]


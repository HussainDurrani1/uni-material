
class Signal:
    def __init__(self, data):
        self.data = data # List of voltages
    def __len__(self):
        return len(self.data)
    def __add__(self, other):
        return Signal([a + b for a, b in zip(self.data, other.data)])
    
    
# Create two signal objects
sig1 = Signal([1.2, 2.4, 3.6])
sig2 = Signal([0.8, 1.6, 2.4])

# Using __len__
print(f"Signal length: {len(sig1)}")  # Output: 3

# Using __add__ (Operator Overloading)
combined_sig = sig1 + sig2
print(f"Combined data: {combined_sig.data}")  # Output: [2.0, 4.0, 6.0]
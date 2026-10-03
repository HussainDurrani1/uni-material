# ==============================================================================
# Topic 4: Iteration (while vs for-in) and the range() generator
# ==============================================================================

# 1. Standard while loop (identical mechanics to C++)
counter = 3
print("=== While Loop ===")
while counter > 0:
    print(f"Countdown: {counter}")
    counter -= 1  # Note: Python does NOT have counter++ or counter--

print("\n=== For Loop: Sequence Iteration ===")
# 2. For loop iterates over collections directly (no indexing needed)
topics = ["Dynamic Typing", "Memory Binding", "Truthiness", "Iterators"]

for topic in topics:
    print(f"Covered Topic: {topic}")

print("\n=== For Loop: Counting with range() ===")
# 3. range(start, stop_exclusive, step)
# C++ equivalent: for(int i = 0; i < 5; i++)
for i in range(5):
    print(f"Iteration index: {i}")

print("\n=== Stepped range ===")
# Counting by twos from 10 to 20
for n in range(10, 21, 2):
    print(n, end="-")
print()  # Newline
# ==============================================================================
# Topic 2: Dynamic vs. Static Typing & Strong Type Enforcement
# ==============================================================================

# In C++: int data = 100; (4-byte fixed container on the stack)
# In Python: 'data' is a pointer/label pointing to a PyObject on the heap.

data = 100
print(f"Value: {data}")
print(f"Data Type: {type(data)}")
print(f"Memory Address (id): {id(data)}")

print("-" * 40)

# Rebinding to a completely different type
# In C++, 'data = "UCP";' would trigger a compilation error.
data = "UCP"
print(f"Value: {data}")
print(f"Data Type: {type(data)}")
print(f"Memory Address (id): {id(data)}")  # Notice the address has changed!
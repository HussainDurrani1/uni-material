
class Patient:
    def __init__(self, name, id):
        self.name = name
        self.id = id
    def __str__(self):
        return f"Patient: {self.name} (ID: {self.id})"
    
# Create objects
p1 = Patient("Awais", 101)
p2 = Patient("Zain", 102)

# C++ style: would require a custom print_info() method
# Python style: Uses __str__ automatically
print(p1)  # Output: Patient: Awais (ID: 101)
print(p2)  # Output: Patient: Zain (ID: 102)
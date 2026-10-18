# Creating a dictionary
student = {
    "name": "Arsalan",
    "roll_no": "L1F24BSCS0123",
    "courses": ["P4AI", "OS", "IS", "Eng3", "AI", "CybSec"]
}

# Accessing a key value
print(student["name"])    # Output: Arsalan

# Adding a new key-value pair
student["cgpa"] = 3.8

# Accessing whole record
print(student)

# Accessing each key without knowing how many keys and key names
for key, value in student.items():
    print(f"{key} is {value}")

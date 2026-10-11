# ==============================================================================
# Topic 3: Control Flow
# ==============================================================================

marks = 78

# 1. Standard branching with elif and logical keywords
if marks >= 85 and marks <= 100:
    grade = "A"
elif marks >= 70 and marks < 85:
    grade = "B"
else:
    grade = "C or below"

print(f"Marks: {marks} | Grade: {grade}")

print("-" * 40)

# In C++, you write: if (vec.empty()) or if (count == 0)
# In Python, empty objects, 0, and None evaluate directly to False.

submitted_assignments = []  # Empty list

if submitted_assignments:
    print("Assignments received.")
else:
    print("Assignments NOT received.")

# Checking a non-empty string vs empty string
my_string = ""
if not my_string:
    print("Empty string evaluated to False!")
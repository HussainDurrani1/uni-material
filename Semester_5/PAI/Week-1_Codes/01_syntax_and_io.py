# ==============================================================================
# Topic 1: Execution Model, Indentation, and Output Formatting
# ==============================================================================

# No #include <iostream>, no int main(), no return 0;
# Execution starts immediately from line 1.

course_code = "AI303"
course_title = "Programming for AI"
student_count = 45

# 1. Standard comma-separated printing (adds default space separator)
print("Course Code:", course_code)

# 2. Modern string interpolation: f-strings (evaluated at runtime)
print(f"Enrolled Students: {student_count} in {course_title}")

# 3. Inline arithmetic and logic inside f-strings
print(f"Lab Capacity Remaining: {60 - student_count} seats")

# 4. Indentation defines scope (replaces C++ curly braces)
if student_count > 40:
    print("Class Status: Large section, lab demonstrations required.")
    print("Indented line: still inside the if-block.")

print("Unindented line: back in the global scope.")
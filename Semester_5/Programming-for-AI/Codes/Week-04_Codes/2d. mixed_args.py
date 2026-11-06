
def display_profile(name, age, city="Lahore", occupation="Student"):
    print(f"{name} ({age}) from {city} is a {occupation}")

# VALID: 1st is positional, rest are named/default
display_profile("Saleem", 35, occupation="Faculty")

# VALID: All named (order doesn't matter)
display_profile(age=22, name="Sara", occupation="Researcher", city="Karachi")

# INVALID: SyntaxError (Positional follows keyword)
display_profile(name="Zain", 21)
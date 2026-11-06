
def func(a, b=2, *args, **kwargs):
    print(f"a: {a}")
    print(f"b: {b}")
    print(f"args: {args}")
    print(f"kwargs: {kwargs}")
    print("-" * 20)

# --- Scenario 1: Minimum required arguments ---
# Only 'a' is provided. 'b' uses its default.
func(10)
# Output: a: 10, b: 2, args: (), kwargs: {}

# --- Scenario 2: Standard Positional Overloading ---
# 10 goes to 'a', 20 overwrites 'b', and 30, 40 are "packed" into args.
func(10, 20, 30, 40)
# Output: a: 10, b: 20, args: (30, 40), kwargs: {}

# --- Scenario 3: Mixing Positional and Keyword ---
# Notice that 'b' is skipped in the positional order and handled by name.
func(10, 88, 99, x=1, y=2)
# Output: a: 10, b: 88, args: (99,), kwargs: {'x': 1, 'y': 2}

# --- Scenario 4: The "Catch-All" (Splat) ---
# Unpacking a list into args and a dict into kwargs.
my_list = [100, 200, 300]
my_dict = {"status": "Active", "mode": "AI"}
func(5, *my_list, **my_dict)
# Output: a: 5, b: 100, args: (200,), kwargs: {'status': 'Active', 'mode': 'AI'}
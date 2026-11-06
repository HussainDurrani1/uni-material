
def flatten(nested_list):
    flat = []
    for item in nested_list:
        if isinstance(item, list):
            flat.extend(flatten(item)) # Recursive call
        else:
            flat.append(item)
    return flat

data = [1, [2, [3, 4], 5], 6]
print(flatten(data)) # [1, 2, 3, 4, 5, 6]
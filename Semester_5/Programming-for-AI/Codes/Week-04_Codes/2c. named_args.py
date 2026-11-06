
def calculate_bmi(weight, height):
    return weight / (height ** 2)

# Order doesn't matter because we are naming them
result = calculate_bmi(height=1.75, weigt=70)
print(f"The bmi is {result:.2f}")
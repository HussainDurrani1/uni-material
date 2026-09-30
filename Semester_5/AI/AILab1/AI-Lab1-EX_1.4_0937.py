# 1:
# cube(n), which takes in a number and returns its cube. For example, cube(3) => 27.
def cube(n: int):
    return n ** 3

num = int(input("Enter a number to find its cube: "))
print(f"cube({num}) => {cube(num)}")


# factorial(n), which takes in a non-negative integer n and returns n!, 
# which is the product of the integers from 1 to n. (0! = 1 by definition.)

def factorial(n: int):
    fact = 1
    if n < 0:
        return 0
    if n == 0 or n == 1:
        return 1
    else:
        for i in range(n):
            fact *= (i+1)

    return fact

n = int(input("Enter a number to find its factorial: "))
print(f"factorial({n}) => {factorial(n)}")



# count_pattern(pattern lst), which counts the number of times a certain pattern
# of symbols appears in a list, including overlaps. So count_pattern( ('a', 'b'),
# ('a','b', 'c', 'e', 'b', 'a', 'b', 'f')) should return 2, and
# count_pattern(('a', 'b', 'a'), ('g', 'a', 'b', 'a', 'b',
# 'a','b', 'a')) should return 3.

def count_pattern(pattern, lst):
    if not pattern:
        return 0
        
    count = 0
    pattern_len = len(pattern)
    
    for i in range(len(lst) - pattern_len + 1):
        if tuple(lst[i:i + pattern_len]) == tuple(pattern):
            count += 1
            
    return count

print(f"count_pattern():  => {count_pattern(('a', 'b'), ('a', 'b', 'c', 'e', 'b', 'a', 'b', 'f'))}")
print(f"count_pattern():  => {count_pattern(('a', 'b', 'a'), ('g', 'a', 'b', 'a', 'b', 'a', 'b', 'a'))}")



#  Write a python program to print the multiplication table for the given number?

def multiplication_table(num):
    for i in range(1, 11):
        print(f"{num} x {i} = {num * i}")


n = int(input("Enter a number to find its multiplication_table: "))
multiplication_table(n)



# Write a python program to implement Simple Calculator program? (+, -, / ,*)
def simple_calculator():
    num1 = float(input("Enter first number: "))
    operator = input("Enter operator (+, -, *, /): ")
    num2 = float(input("Enter second number: "))

    if operator == '+':
        print(f"Result: {num1 + num2}")
    elif operator == '-':
        print(f"Result: {num1 - num2}")
    elif operator == '*':
        print(f"Result: {num1 * num2}")
    elif operator == '/':
        if num2 != 0:
            print(f"Result: {num1 / num2}")
        else:
            print("Error! Division by zero.")
    else:
        print("Invalid operator!")

simple_calculator()



# Write a python program to sort the sentence in alphabetical order?
def sort_sentence(sentence):
    words = sentence.split()
    words.sort(key=str.lower)
    return " ".join(words)

print(sort_sentence("Artificial Intelligence Lab at University of Central Punjab"))



# 2:
# Write a Python class to convert an integer to a roman numeral.
class IntegerToRoman:
    def convert(self, num: int) -> str:
        val = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        syb = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        roman_num = ''
        i = 0
        while num > 0:
            for _ in range(num // val[i]):
                roman_num += syb[i]
                num -= val[i]
            i += 1
        return roman_num

n = int(input("Enter a number to find its Roman value: "))
print(IntegerToRoman().convert(n))



# 3:
# Write a Python class to find a pair of elements (indices of the two numbers) from a given array
# whose sum equals a specific target number. Input: numbers= [10,20,10,40,50,60,70], target=50
# Output: 3, 4
class TwoSum:
    def find_pair(self, numbers: list, target: int):
        lookup = {}
        for index, num in enumerate(numbers):
            if target - num in lookup:
                return lookup[target - num], index
            lookup[num] = index
        return None

numbers = [10, 20, 10, 40, 50, 60, 70]
target = 50
print(TwoSum().find_pair(numbers, target))



# 4:
# Write a Python class to find the three elements that sum to zero from a set of n real numbers.
# Input array : [-25, -10, -7, -3, 2, 4, 8, 10] Output : [[-10, 2, 8], [-7, -3, 10]].
class ThreeSum:
    def find_triplets(self, nums: list):
        nums.sort()
        res = []
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            l, r = i + 1, len(nums) - 1
            while l < r:
                s = nums[i] + nums[l] + nums[r]
                if s < 0:
                    l += 1
                elif s > 0:
                    r -= 1
                else:
                    res.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    l += 1
                    r -= 1
        return res

input_arr = [-25, -10, -7, -3, 2, 4, 8, 10]
print(ThreeSum().find_triplets(input_arr))



# 5. 
# Write a Python class to reverse a string word by word. 
# Input string : 'hello world' Expected Output : 'world hello'
class StringReverse:
    def reverse_words(self, s: str) -> str:
        return ' '.join(reversed(s.split()))

print(StringReverse().reverse_words('hello world to AI'))


# 6:
# Count the numbers of characters in the string
# a. Read the string.
# b. Count the characters
# c. Display the result
def count_characters(user_str: string):
    char_count = len(user_str)
    print(f"The number of characters in the string is: {char_count}")

user_string = input("Enter a string: ")
count_characters(user_string)




# 7: 
# Addition of two square matrices.
# d. Create a lists to read matrix elements
# e. Read the elements of to matrices add the elements
# f. Store the result in third matrix.
# g. Repeat steps 2 and 3 till the addition of all elements
def add_matrices(n):
    print(f"Enter elements for Matrix A ({n}x{n}):")
    A = [[int(input(f"A[{i}][{j}]: ")) for j in range(n)] for i in range(n)]
    
    print(f"Enter elements for Matrix B ({n}x{n}):")
    B = [[int(input(f"B[{i}][{j}]: ")) for j in range(n)] for i in range(n)]
    
    result = [[A[i][j] + B[i][j] for j in range(n)] for i in range(n)]
    
    print("Resultant Matrix after Addition:")
    for row in result:
        print(row)

add_matrices(2)




# 8:
# Display the result Multiplication of two matrices
# h. Create a lists to read matrix elements
# i. Read the elements of two matrices, multiply the elements
# j. Store the result in third matrix.
# k. Repeat steps 2 and 3 till the multiplication of all elements
# l. Display the result.
def multiply_matrices(r1, c1, r2, c2):
    if c1 != r2:
        print("Matrix multiplication not possible!")
        return

    print("Enter elements for Matrix A:")
    A = [[int(input(f"A[{i}][{j}]: ")) for j in range(c1)] for i in range(r1)]
    
    print("Enter elements for Matrix B:")
    B = [[int(input(f"B[{i}][{j}]: ")) for j in range(c2)] for i in range(r2)]
    
    result = [[0 for _ in range(c2)] for _ in range(r1)]
    for i in range(r1):
        for j in range(c2):
            for k in range(c1):
                result[i][j] += A[i][k] * B[k][j]
                
    print("Resultant Matrix after Multiplication:")
    for row in result:
        print(row)

multiply_matrices(2, 2, 2, 2)




# 9: 
# Write a function called calculator. It should take the following parameters: two numbers, an
# arithmetic operation (which can be addition, subtraction, multiplication or division and is addition
# by default), and an output format (which can be integer or floating point, and is floating point by
# default). Division should be floating-point division. The function should perform the requested
# operation on the two input numbers, and return a result in the requested format (if the format is
# integer, the result should be rounded and not just truncated). Raise exceptions as appropriate if
# any of the parameters passed to the function are invalid.
def calculator(num1, num2, operation="addition", output_format="floating point"):
    if not isinstance(num1, (int, float)) or not isinstance(num2, (int, float)):
        raise TypeError("Both numbers must be numeric values.")
    
    valid_ops = ["addition", "subtraction", "multiplication", "division"]
    if operation not in valid_ops:
        raise ValueError(f"Invalid operation. Choose from {valid_ops}")
        
    valid_formats = ["integer", "floating point"]
    if output_format not in valid_formats:
        raise ValueError(f"Invalid output format. Choose from {valid_formats}")

    if operation == "addition":
        res = num1 + num2
    elif operation == "subtraction":
        res = num1 - num2
    elif operation == "multiplication":
        res = num1 * num2
    elif operation == "division":
        if num2 == 0:
            raise ZeroDivisionError("Division by zero is not allowed.")
        res = num1 / num2

    if output_format == "integer":
        return round(res)
    return float(res)

print(calculator(10, 3.6, "addition", "integer")) 
print(calculator(10, 3, "division", "floating point")) 





# 10: 
# Create a class called Numbers, which has a single class attribute called MULTIPLIER, and a
# constructor which takes the parameters x and y (these should all be numbers).
# m. Write a method called add which returns the sum of the attributes x and y.
# n. Write a class method called multiply, which takes a single number parameter a and
#   returns the product of a and MULTIPLIER.
# o. Write a static method called subtract, which takes two number parameters, b and c, and
#   returns b - c.
# p. Write a method called value which returns a tuple containing the values of x and y. Make
#   this method into a property, and write a setter and a deleter for manipulating the values
#   of x and y.
class Numbers:
    MULTIPLIER = 5

    def __init__(self, x: int | float, y: int | float):
        if not isinstance(x, (int, float)) or not isinstance(y, (int, float)):
            raise TypeError("Parameters x and y must be numbers.")
        self._x = x
        self._y = y

    def add(self):
        return self._x + self._y

    @classmethod
    def multiply(cls, a):
        return a * cls.MULTIPLIER

    @staticmethod
    def subtract(b, c):
        return b - c

    @property
    def value(self):
        return (self._x, self._y)

    @value.setter
    def value(self, val_tuple):
        if not isinstance(val_tuple, tuple) or len(val_tuple) != 2:
            raise ValueError("Value must be a tuple of two numbers.")
        if not all(isinstance(i, (int, float)) for i in val_tuple):
            raise TypeError("Both values in the tuple must be numbers.")
        self._x, self._y = val_tuple

    @value.deleter
    def value(self):
        print("Deleting attributes x and y...")
        del self._x
        del self._y

obj = Numbers(10, 20)
print("Sum:", obj.add())
print("Class Multiply:", Numbers.multiply(4))
print("Static Subtract:", Numbers.subtract(15, 5)) 
print("Property Getter:", obj.value) 

obj.value = (40, 50)        
print("Updated Values:", obj.value) 

del obj.value 


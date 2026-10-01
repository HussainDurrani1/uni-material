# Python save every variables data in heap as an object, and assigns its address to the variable.

# Mutable objects (list, dict, Set) are shallow copied, meaning if one variable pointing to it makes some change, 
# it will be changed for the other variable as well.
# But, that is not the case with immutable variables (str, int, float, frozenSet, tuple)

print("Hello, Hussain Durrani.")

x = [1, 2, 3]
y = x

y[0] = 0

print(x)
print(y)


a = "hello"
b = "bye"

print(a, b, type(a))

c = 10
d = 9

print(c, d, id(c))
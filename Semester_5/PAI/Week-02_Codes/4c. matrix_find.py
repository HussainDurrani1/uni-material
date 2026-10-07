
# Single Nested List Comprehension

matrix = [[1, 6, 2], [8, 3, 7], [4, 9, 5]]

results = [item for row in matrix for item in row if item > 5]

print ("Single Nested List Comprehension: ", results)
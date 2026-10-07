squares = [x**2 for x in range(10) if x % 2 == 0]
print(squares)

names = ['Muhammad', 'Hussain',  'Raza',  'Durrani']
name_len = [len(n) for n in names]
print(name_len)

name_firsl_letter = [n[0] for n in names]
print(name_firsl_letter)


# --------------------------------------------------

matrix = [[1, 6, 2], [8, 3, 7], [4, 9, 5]]
results = []

for i in range(len(matrix)):
    for j in range(len(matrix[i])):
        if matrix[i][j] > 5:
            results.append(matrix[i][j])

print(results)

results2 = []
for row in matrix:
    for item in row:
        if item > 5:
            results2.append(item)

print(results2)

results3 = [item for row in matrix for item in row if item> 5]
print(results3)


# --------------------------------------------------

combined = list(zip(squares, names, results))
print(combined)

for name, sq, res in zip(squares, names, results):
    print(f'Name: {name} | Square: {sq} | Result: {res}.')

# --------------------------------------------------

values_db = {
    sq: {'name': name, 'result': res}
    for name, sq, res in zip(names, squares, results)
}
print(values_db)
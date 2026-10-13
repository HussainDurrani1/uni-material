# Task 1:
def extract_high_multiples(matrix):
    return [
        {'row': i, 'col': j, 'val': matrix[i][j]}
        for i in range(len(matrix))
        for j in range(len(matrix[i]))
        if matrix[i][j] > 5 and matrix[i][j] % 3 == 0
    ]

matrix = [[1, 6, 2], [3, 8, 7], [4, 5, 9]]
print('Task 1: ', extract_high_multiples(matrix), '\n')


# Task 2:
def summerize(cities, temps, humidity):
    return [
        f"The weather in {city} is {temp}C with {hum}% humidity."
        for city, temp, hum in zip(cities, temps, humidity)
    ]

cities = ["Lahore", "Karachi", "Islamabad"]
temps = [32, 35, 28]
humidity = [60, 70, 45]

print('Task 2: ', summerize(cities, temps, humidity), '\n')


# Task 3:
def sanitize(emails):
    return [email.strip().lower() for email in emails]

emails = [" ALI@gooGle.coM", "sara@Yahoo.com ", " AHMED@uCP.EdU.PK "]
print('Task 3: ', sanitize(emails), '\n')


# Task 4:
c_temps = [0, 12, 34, 100, -5, 25]

positive = lambda x: x > 0
positive_temps = list(filter(positive, c_temps))

to_fahrenheit = lambda c: c * 9 / 5 + 32
fahrenheit = list(map(to_fahrenheit, positive_temps))

print('Task 4 (in Celsius): ', positive_temps)
print('Task 4 (in Fahrenheit): ', fahrenheit, '\n')


# Task 5:
def combine(keys, values):
    return {key: value for key, value in zip(keys, values)}

keys = ["ID", "Name", "Role"]
values = [101, "Awais", "Faculty"]

print('Task 5: ', combine(keys, values))
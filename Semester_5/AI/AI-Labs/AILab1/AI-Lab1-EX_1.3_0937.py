def triangle(row: int):
    value = 1
    rowNum = 1
    while rowNum <= row:
        column = 1
        while column <= rowNum:
            if column != rowNum:
                print(value, ' ', sep = '', end = '')
            else:
                print(value)
            value = value + 1
            column = column + 1
        rowNum += 1

rows = int(input("Enter the number of rows: "))
triangle(rows)
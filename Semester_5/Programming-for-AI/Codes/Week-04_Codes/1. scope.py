
x = "global"

def outer():
    x = "enclosing"
    def inner():
        x = "local"
        print("1: ", x) # Searches L -> E -> G -> B
        if True:
            x = "inside if"
            print("2: ", x)
        print("3: ", x)
    inner()
    print("4: ", x)

outer()
print("5: ", x)
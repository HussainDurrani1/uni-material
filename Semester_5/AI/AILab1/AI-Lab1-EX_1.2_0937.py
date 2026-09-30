def sundaes():
    flavors = ["Vanilla", "Chocolate", "Strawberry", "Pistacchio"]
    sauces = ["Caramel", "Butterscotch", "Chocolate"]
    for flavor in flavors:
        for sauce in sauces:
            print(f"{flavor} Ice Cream SUNDAE with {sauce} sauce.")

sundaes()

# Generator

def ucp_range(size):
    count = 0
    while count < size:
        print("generating: ", str(count))
        yield count
        count += 1
        

for i in ucp_range(100):
    print("yielded",i)
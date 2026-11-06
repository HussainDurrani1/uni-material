
#This code demonstrates Python's Context Manager protocol 
# using the dunder methods __enter__ and __exit__. 
# It achieves deterministic resource management similar to 
# C++ RAII (Resource Acquisition Is Initialization), 
# where setup and cleanup happen automatically around a bounded scope.

class DatabaseSession:
    def __init__(self):
        print("the constructor")
        self.data = [1, 2, 3, 4, 5]
    def __enter__(self):
        print("Connecting to Clinic DB...")
        return self
    def __exit__(self, exc_type, exc_val, exc_tb):
        print("Closing Connection.")
    def execute(self):
        print("inside execute")
        for i in self.data:
            print("processing: ", i)
        print("exiting execute")

        

# This mimics the C++ scope-based resource management
with DatabaseSession() as db:
    print("Executing AI Query on patient records...")
    db.execute()
    # Logic happens here...
# Connection closes automatically here even if an error occurs inside the block

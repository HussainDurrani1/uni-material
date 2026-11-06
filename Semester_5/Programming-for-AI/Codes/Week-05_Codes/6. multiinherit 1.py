class Person: 
    def __init__(self, n, a, **kwargs):
        print("Constructor: Person")
        self.name = n
        self.age = a
        super().__init__(**kwargs)
    def __str__(self):
        return f"Person: name = {self.name}, age = {str(self.age)}" + "\n" + super().__str__()

class Employee: 
    def __init__(self, d, e, **kwargs):
        print("Constructor: Employee")
        self.department = d
        self.experience = e
        super().__init__(**kwargs)
    def __str__(self):
        return f"Employee: Depart = {self.department}, Exp = {str(self.experience)}" + "\n" + super().__str__()

class Faculty(Employee, Person):
    def __init__(self, n, a, d, e):
        print("Constructor: Faculty")
        super().__init__(n = n, a = a, d =  d, e = e)
        
    def __str__(self):
        return super().__str__()
    
# MRO: Faculty -> Person -> Employee -> object

prof = Faculty("Awais", 40, "CS", 20)
print(prof)
# Check the Method Resolution Order (The "Search Path")
# print(Faculty.mro()) 
# Output: [<class 'Faculty'>, <class 'Person'>, <class 'Employee'>, <class 'object'>]

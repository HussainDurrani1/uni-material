
class CommonBase:
    def info(self): print("Common Base")
    
class BaseData:
    def info(self): print("Base Data")

class SQL_Source:
    def info(self): print("SQL Source")

# Dynamically creating a class. 
# We decide the MRO (SQL_Source first, then BaseData) at runtime.
DynamicModel = type("DynamicModel", (SQL_Source, BaseData, CommonBase), {"version": 1.0})

# Testing the MRO
obj = DynamicModel()
obj.info()  # Output: SQL Source
print(DynamicModel.mro()) 
# [<class 'DynamicModel'>, <class 'SQL_Source'>, <class 'BaseData'>, <class 'object'>]
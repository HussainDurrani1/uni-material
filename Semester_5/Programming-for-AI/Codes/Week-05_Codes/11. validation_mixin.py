
class ValidationMixin:
    def __setattr__(self, name, value):
        if name == "age" and value < 0:
            raise ValueError("Age cannot be negative!")
        super().__setattr__(name, value)
        
class PatientProfile(ValidationMixin):
    def __init__(self, name, age):
        self.name = name
        self.age = age # This triggers __setattr__ in the Mixin

# Valid Object
p_valid = PatientProfile("Ali", 30)

# Invalid Object - Will throw an error
try:
    p_invalid = PatientProfile("Sara", -5)
except ValueError as e:
    print(f"Caught expected error: {e}")
# PatientRecord class example covering encapsulation, access specifiers

class PatientRecord:
    # 1. The Constructor (Equivalent to C++ ClassName())
    def __init__(self, p, a, d="Normal"):
        # Member Properties (Instance Variables)
        self.patient_id = p
        self.age = a
        self.diagnosis = d
        self.is_processed = False  # Default property
        
        self.__medicine = "Panadol"     #private member
        self._doctor = "Arsalan"
    
    # 2. Member Function (Instance Method)
    def update_diagnosis(self, new_diag):
        print(f"Updating diagnosis for Patient {self.patient_id}...")
        self.diagnosis = new_diag
        self.__medicine = "Calpol"
    
    # 3. Member Function with Logic
    def get_patient_summary(self):
        status = "Processed" if self.is_processed else "Pending"
        return f"ID: {self.patient_id} | Age: {self.age} | Diag: {self.diagnosis} | Status: {status}"

    def get_medicine(self):
        return self.__medicine

# --- Using the Class ---
# Creating an instance (No 'new' keyword required)
p1 = PatientRecord("Pno-001", 65, "MI")

# Accessing properties
print(p1.get_medicine()) 
p1.update_diagnosis("Healthy")
print(p1.get_medicine()) 

print(p1._doctor)

# # Calling member functions
# p1.update_diagnosis("Recovered")
# print(p1.get_patient_summary())


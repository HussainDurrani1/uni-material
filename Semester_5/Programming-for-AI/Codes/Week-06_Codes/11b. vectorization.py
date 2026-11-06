
import numpy as np


# --- Normalization (ML Preprocessing) ---
def normalize_data(matrix):
    # Vectorized Min-Max Scaling
    return (matrix - matrix.min()) / (matrix.max() - matrix.min())

patient_vitals = np.array([[70, 120], [85, 140], [60, 110]])
norm_vitals = normalize_data(patient_vitals)
print(f"Normalized Vitals:\n{norm_vitals}")


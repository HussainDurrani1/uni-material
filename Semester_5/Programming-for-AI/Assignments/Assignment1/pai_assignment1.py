import csv
import time

# TASK 1: THE SCP DECODER
def get_mi_mapping(mapping_csv_path):
    mi_map = {}

    with open(mapping_csv_path, "r", newline="") as file:
        reader = csv.DictReader(file)

        for row in reader:
            code = list(row.keys())[0]

            if row["Statement Category"] == "Myocardial Infarction":
                mi_map[row[code]] = row["description"]

    return mi_map


# TASK 2: THE PATIENT GENERATOR
def mi_patient_streamer(database_csv_path, mi_mapping):
    with open(database_csv_path, "r", newline="") as file:
        reader = csv.DictReader(file)

        for row in reader:
            for code in mi_mapping:
                if f"'{code}'" in row["scp_codes"]:
                    patient = {
                        "patient_id": row["patient_id"],
                        "age": row["age"],
                        "sex": row["sex"],
                        "record_date": row["recording_date"],
                        "diagnosis": mi_mapping[code],
                        "filename": row["filename_hr"]
                    }

                    yield patient
                    break


# TASK 3: EXECUTION AND TIMING
def main():
    db_path = "ptbxl_database.csv"
    statements_path = "scp_statements.csv"

    print("--- Initializing MI Mapping ---")
    mi_mapping = get_mi_mapping(statements_path)
    print(f"Loaded {len(mi_mapping)} MI-related diagnostic codes.\n")

    print("--- Starting Patient Stream ---")
    start_time = time.time()

    patient_gen = mi_patient_streamer(db_path, mi_mapping)

    count = 0

    for patient in patient_gen:
        print(patient)
        count += 1

        if count == 5:
            break

    end_time = time.time()
    print(f"\nTime taken to find records: {end_time - start_time:.4f} seconds")


if __name__ == "__main__":
    main()



def report_results(model_name, *scores, threshold=0.5, **metadata):
    print(f"--- Model: {model_name} ---")
    
    # *args: Processing variable scores
    avg_score = sum(scores) / len(scores) if scores else 0
    status = "PASS" if avg_score >= threshold else "FAIL"
    print(f"Average Score: {avg_score:.2f} ({status})")
    
    # **kwargs: Printing extra details
    for key, value in metadata.items():
        print(f"{key.capitalize()}: {value}")

# Calling the function
report_results(
    "PTB-XL-Classifier",    # Position 1 (model_name)
    0.85, 0.92, 0.78,       # *args (scores)
    threshold=0.8,          # Keyword argument
    version="1.0.3",        # **kwargs (metadata)
    author="Awais"          # **kwargs (metadata)
)
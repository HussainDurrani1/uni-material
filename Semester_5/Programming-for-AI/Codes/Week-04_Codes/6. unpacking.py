
def plot_data(x, y, color="blue", linestyle="-", linewidth=1):
    print(f"Plotting with color {color}, style {linestyle}, width {linewidth}")

def custom_wrapper(*args, **kwargs):
    print("Pre-processing data...")
    # Forwarding everything exactly as received to another function
    plot_data(*args, **kwargs)

# Usage
data_x = [1, 2, 3]
data_y = [10, 20, 30]
custom_wrapper(data_x, data_y, color="red", linewidth=2, linestyle = '-.-')
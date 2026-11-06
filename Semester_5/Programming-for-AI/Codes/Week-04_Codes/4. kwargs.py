
def configure_model(name, **kwargs):
    print(f"Configuring {name}...")
    for key, value in kwargs.items():
        print(f"Setting {key} to {value}")

configure_model("NeuralNet", learning_rate=0.01, epochs=50, optimizer="Adam")
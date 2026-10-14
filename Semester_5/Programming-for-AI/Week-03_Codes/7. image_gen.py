
import random

def image_batch_generator(batch_size):
    while True:
        # Simulate loading images from disk
        batch = [f"Image_Data_{random.randint(1, 100)}" for _ in range(batch_size)]
        yield batch  # Yields a batch, then waits for the next request

# AI Training Loop
loader = image_batch_generator(32)
for i in range(3):
    print(f"Training on: {next(loader)}")
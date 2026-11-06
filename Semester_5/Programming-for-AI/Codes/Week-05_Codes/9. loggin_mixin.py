
class LoggerMixin:
    def log(self, message):
        print(f"[LOG - {self.__class__.__name__}]: {message}")

class Model(LoggerMixin):
    def train(self):
        self.log("Starting training...")
        
class MyAIModel(LoggerMixin):
    def train(self):
        self.log("Epoch 1 started")
        self.log("Loss: 0.045")

model = MyAIModel()
model.train()
# Output: [LOG - MyAIModel]: Epoch 1 started ...
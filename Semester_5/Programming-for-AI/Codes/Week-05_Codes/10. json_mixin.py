
import json
class JSONMixin:
    def to_json(self):
        return json.dumps(self.__dict__)

class ECGConfig(JSONMixin):
    def __init__(self, rate, gain):
        self.rate, self.gain = rate, gain
        
config = ECGConfig(rate=500, gain=2.5)

# The 'to_json' method was "mixed in" from the JSONMixin class
json_string = config.to_json()
print(f"Serialized Config: {json_string}")
# Output: {"rate": 500, "gain": 2.5}
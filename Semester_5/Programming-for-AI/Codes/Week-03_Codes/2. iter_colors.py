
class CycleColors:
    def __init__(self):
        self.colors = ["Red", "Yellow", "Green", "Blue", "White", "Black"]
        self.index = 0
    def __iter__(self):
        return self
    def __next__(self):
        color = self.colors[self.index % len(self.colors)]
        self.index += 1
        return color

# This will run forever without consuming extra memory
traffic_light = CycleColors()
print(next(traffic_light))      # 1st
print(next(traffic_light))      # 2nd
print(next(traffic_light))      # 3rd
print(next(traffic_light))      # 4th
print(next(traffic_light))      # 5th
print(next(traffic_light))      # 6th
print(next(traffic_light))      # 7th
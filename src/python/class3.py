class Duck:
    def __init__(self, color, age):
        self.color=color
        self.age=age
    def __str__(self):
        return f"This duck is {self.color} and"\
                f" it's {self.age} years old"
    def speak(self):
        print("quack quack")

frank=Duck("black",3)
print(frank.color)
print(frank.age)
frank.speak()
print(frank)

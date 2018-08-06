import random


for i in range(0, 1000):
  print(random.randint(-1000, 1000), random.randint(-1000, 1000), random.randint(0, 10))

print(random.randint(-1000, 0), random.randint(0, 1000))
print(random.randint(0, 1000), random.randint(-1000, 0))
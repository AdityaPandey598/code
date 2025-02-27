def create_cubes(n):
    for i in range (n):
        yield i**3

for x in create_cubes(10):
    print(x)
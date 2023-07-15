import matplotlib.pyplot as plt


def dots_from_txt(path):
    coords = []
    dots = []
    with open(path, 'r') as file:
        coords = file.readlines()
    for coord in coords:
        dots.append(tuple(map(float, coord.split('; '))))
    return dots


def draw(dots, h):
    plt.plot(*zip(*dots), label=h)
    plt.grid(True)


h = 0.1
for i in range(1, 5):
    dots = dots_from_txt(f'y(x){i}.txt')
    draw(dots, str(h))
    h /= 10
plt.legend()
plt.show()

h = 0.1
for i in range(1, 5):
    dots = dots_from_txt(f'u(y){i}.txt')
    draw(dots, str(h))
    h /= 10
plt.legend()
plt.show()



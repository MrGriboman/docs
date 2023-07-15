import numpy as np
import matplotlib.pyplot as plt

def derivative(x, y):
    return (np.arcsin(1 + np.tan(x*y)) - np.log(x**2 + y**2 + 1 / np.cos(x*y))) / np.exp(2*x)

y_0 = -np.pi / 3
x_0 = 0
x_n = 1
h = 0.001

xs = [x_0,]
ys = [y_0,]
while x_0 <= x_n:
    y_0 = derivative(x_0, y_0) * h + y_0
    x_0 += h   
    xs.append(x_0)
    ys.append(y_0)

print(f'y(1) {y_0}')
plt.plot(xs, ys)
plt.grid(True)
plt.show()
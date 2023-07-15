#include <fstream>
#include <string>
#include <vector>
#include <cmath>

double der_y(double u) {
    return u;
}

double der_u(double y, double u, double mu) {
    return mu * (1 - std::pow(y, 2)) * u - y;
}

std::vector<std::vector<double>>
euler(double x_0, double y_0, double u_0, double h, double x_n, double mu) {
    std::vector<double> xs = {x_0};
    std::vector<double> ys = {y_0};
    std::vector<double> us = {u_0};

    while (x_0 < x_n) {
        double y = y_0 + h*der_y(u_0);
        double u = u_0 + h*der_u(y_0, u_0, mu);
        x_0 += h;
        y_0 = y;
        u_0 = u;
        xs.push_back(x_0);
        ys.push_back(y_0);
        us.push_back(u_0);
    }
    return std::vector<std::vector<double>> {xs, ys, us};
}

int main() {
    const double MU = 1.49;
    double x_0 = 0;
    double y_0 = 0.56;
    double u_0 = 0.22;
    double h = 0.1;
    std::ofstream fout1;
    std::ofstream fout2;
    
    for (int i = 1; i < 5; ++i) {
        auto result = euler(x_0, y_0, u_0, h, 10, MU);
        fout1.open("y(x)" + std::to_string(i) + ".txt");
        fout2.open("u(y)" + std::to_string(i) + ".txt");
        for (size_t i = 0; i < result[0].size(); ++i) {
            fout1 << result[0][i] << "; " << result[1][i] << std::endl;
            fout2 << result[1][i] << "; " << result[2][i] << std::endl;
        }
        fout1.close();
        fout2.close();
        h /= 10;
    }

    return 0;
}
#include <iostream>
#include <ctime>
#include <cmath>
#include <locale>


double f(double x) {
	return -cos(0.5 * x) - 1;
}

double g(double x) {
	return f(x) * sin(5 * x);
}

double x_rand(double xMin, double xMax) {
	double x = (double)rand() / RAND_MAX;
	return xMin + x * (xMax - xMin);
}

int main() {
	setlocale(LC_ALL, "Russian");
	std::cout.imbue(std::locale("Russian"));
	srand(time(0));
	const double a = -2;
	const double b = 4;
	const double Tmax = 10000;
	const double Tmin = 0.1;
	double N = 1;
	double xi = 0;
	double xmin = x_rand(a, b);
	double p = 0;
	double Ti = Tmax;
	while (Ti > Tmin) {
		xi = x_rand(a, b);
		if ((f(xi) - f(xmin)) <= 0) {
			xmin = xi;
		}
		else {
			p = exp(-(f(xi) - f(xmin)) / Ti);
			if ((rand() % 100 / 100.) <= p) {
				xmin = xi;
			}
		}
		std::cout << "N = " << N << " T = " << Ti << 
			" Xmin = "<< xmin <<" F(Xmin) = " << f(xmin)<< std::endl;
		Ti = Ti * 0.95;
		N++;
	}
	std::cout << "Xmin = "<<  xmin << std::endl;
	std::cout << "F(Xmin) = " << f(xmin) << std::endl;

	N = 1;
	xmin = x_rand(a, b);
	Ti = Tmax;
	while (Ti > Tmin) {
		xi = x_rand(a, b);
		if ((g(xi) - g(xmin)) <= 0) {
			xmin = xi;
		}
		else {
			p = exp(-(g(xi) - g(xmin)) / Ti);
			if ((rand() % 100 / 100.) <= p) {
				xmin = xi;
			}
		}
		std::cout << "N = " << N << " T = " << Ti <<
			" Xmin = " << xmin << " G(Xmin) = " << g(xmin) << std::endl;
		Ti = Ti * 0.95;
		N++;
	}
	std::cout << "Xmin = " << xmin << std::endl;
	std::cout << "G(Xmin) = "<< g(xmin);
}

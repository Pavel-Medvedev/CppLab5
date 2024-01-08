#include <iostream>
import Math;

using namespace Math;

Complex f(const Complex& z);
Rational f(const Rational& r);
double f(double x);

int main() {
	double temp1, temp2;
	std::cout << "Input Complex number by inputing it's real and imagine parts" << std::endl;
	std::cin >> temp1 >> temp2;
	Complex complexNum = { temp1, temp2 };
	std::cout << "Input Complex number by inputing it's nominator and denominator parts" << std::endl;
	std::cin >> temp1 >> temp2;
	Rational rationalNum = { (int)temp1, (int)temp2 };
	std::cout << "f(const Complex& z) = " << f(complexNum) << std::endl;
	std::cout << "f(const Rational& r) = " << f(rationalNum) << std::endl;
	std::cout << "f(double x) = " << f((double)rationalNum) << std::endl;
	return 0;
}

Complex f(const Complex& z)
{
	return 3 / 7 + 5 / 11 * z - 2 + 5i / z;
}
Rational f(const Rational& r)
{
	return (Rational)3 / 7 + (Rational)5 / 11 * r - (Rational)5 / 2 / r;
}
double f(double x)
{
	return 3.0 / 7.0 + 5.0 / 11.0 * x - 2.5 / x;
}

/*
1 1 1 1
*/

module;
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <compare>
export module Math;
export namespace Math {
	// Exponental for of complex number
	class Complex
	{
	public:
		// Create complex 0
		Complex() noexcept;
		// Take real and imaginarye part of complex number and transform them to argument and module
		Complex(double, double) noexcept;
		// Convert double to complex
		Complex(double num) noexcept;
		// Take mod and arg to construct Complex number
		static Complex FromExponentialForm(double, double) noexcept;
		// Take real and imaginarye to construct Complex number
		static Complex FromAlgebraicForm(double, double) noexcept;
		// Return real part of complex number
		double Re() const noexcept;
		// Return real part of complex number
		double Im() const noexcept;
		// Return real part of complex number
		double Mod() const noexcept;
		// Return real part of complex number
		double Arg() const noexcept;
		// Convert Complex to double returns only real part
		explicit operator double() const noexcept;
		// Returns Complex number with iverted real and imaginary parts
		Complex operator-();
		// Returns ref to Complex number after incrementing its real part
		Complex& operator++();
		// Increase real part of Complex number and retuens its previous value
		Complex operator++(int);
		// Returns ref to Complex number after decrementing its real part
		Complex& operator--();
		// Decrease real part of Complex number and retuens its previous value
		Complex operator--(int);
		// Increase this complex number by the right number
		Complex& operator+=(const Complex&);
		// Decrease this complex number by the right number
		Complex& operator-=(const Complex&);
		// Increase this complex number by multiplying it by the right number
		Complex& operator*=(const Complex&);
		// Decrease this complex number by dividing it by the right number
		Complex& operator/=(const Complex&);
	private:
		// Module of complex number
		double mod;
		// Argument of complex number
		double arg;
	};

	// Define user's literal to convert num.i to copmlex number with imaginary part equals num
	Complex operator"" i(long double);
	// Define user's literal to convert num.i to copmlex number with imaginary part equals num
	Complex operator"" i(unsigned long long);
	// Define type of complex printing
	std::ostream& operator<<(std::ostream&, Complex);

	class Rational
	{
	public:
		// Construct rational number with 0 nominator and 1 denominator
		Rational();
		// Construct rational number with nominator and denominator
		Rational(int, int);
		// Construct rational number with nominator and 1 denominator
		Rational(int);
		// Returns rationals nominator
		int Nominator() const noexcept;
		// Returns rationals denominator
		int Denominator() const noexcept;
		// Convert rational number to double by division its nomynator to denominator
		explicit operator double();
		// Returns inverted rational number
		Rational operator-();
		// Returns increased rational number
		Rational& operator++();
		// Increase rational number and returns its previous version
		Rational operator++(int);
		// Returns decreased rational number
		Rational& operator--();
		// Increase rational number and returns its previous version
		Rational operator--(int);
		// Returns inverted rational number
		Rational& operator-=(const Rational& rhs);
		// Returns inverted rational number
		Rational& operator+=(const Rational& rhs);
		// Returns inverted rational number
		Rational& operator*=(const Rational& rhs);
		// Returns inverted rational number
		Rational& operator/=(const Rational& rhs);

	private:
		// Nominator
		int nominator;
		// Denominator
		int denominator;
	};

	// Returns the greatest common divisor of two numbers
	int FindGreatestCommonDivisor(int, int);
	// Returns the leastest common multiple of two numbers
	int FindLeastCommonMultiple(int, int);

	Complex::Complex() noexcept
		: arg(0), mod(0)
	{
	}

	Complex::Complex(double re, double im) noexcept
		: mod(std::sqrt(re* re + im * im)), arg(0)
	{
		if (re > 0)
			arg = std::atan(im / re);
		else if (re == 0 || im < 0)
			arg = M_PI / 2;
		else if (re == 0 || im < 0)
			arg = -M_PI / 2;
		else if (im < 0)
			arg = -M_PI + std::atan(im / re);
		else
			arg = M_PI + std::atan(im / re);
	}

	Complex::Complex(double num) noexcept
		: mod(num), arg(0)
	{
	}

	Complex Complex::FromExponentialForm(double mod, double arg) noexcept
	{
		return Complex(mod * std::cos(arg), mod * std::sin(arg));
	}

	Complex Complex::FromAlgebraicForm(double re, double im) noexcept
	{
		return Complex(re, im);
	}

	double Complex::Re() const noexcept
	{
		return mod * std::cos(arg);
	}

	double Complex::Im() const noexcept
	{
		return mod * std::sin(arg);
	}

	double Complex::Mod() const noexcept
	{
		return mod;
	}

	double Complex::Arg() const noexcept
	{
		return arg;
	}

	Complex::operator double() const noexcept
	{
		return Re();
	}

	Complex Complex::operator-()
	{
		return Complex(-Re(), Im());
	}

	Complex& Complex::operator++()
	{
		return *this = Complex(Re() + 1, Im());
	}

	Complex Complex::operator++(int)
	{
		++(*this);
		return Complex(Re() - 1, Im());
	}

	Complex& Complex::operator--()
	{
		return *this = Complex(Re() - 1, Im());
	}

	Complex Complex::operator--(int)
	{
		--(*this);
		return Complex(Re() + 1, Im());
	}

	Complex& Complex::operator+=(const Complex& rhs)
	{
		return *(this) = Complex(Re() + rhs.Re(), Im() + rhs.Im());
	}

	Complex& Complex::operator-=(const Complex& rhs)
	{
		return *(this) = Complex(Re() - rhs.Re(), Im() - rhs.Im());
	}

	Complex& Complex::operator*=(const Complex& rhs)
	{
		return *(this) = Complex
		(Re() * rhs.Re() - Im() * rhs.Im(),
			Im() * rhs.Re() + rhs.Im() * Re());
	}

	Complex& Complex::operator/=(const Complex& rhs)
	{
		return *(this) = Complex
		((Re() * rhs.Re() + Im() * rhs.Im()) / (rhs.Re() * rhs.Re() + rhs.Im() * rhs.Im()),
			(Im() * rhs.Re() - Re() * rhs.Im()) / (rhs.Re() * rhs.Re() + rhs.Im() * rhs.Im()));
	}

	Complex operator+(Complex lhs, Complex rhs) {
		return Complex(lhs.Re(), lhs.Im()) += rhs;
	}

	Complex operator-(Complex lhs, Complex rhs) {
		return Complex(lhs.Re(), lhs.Im()) -= rhs;
	}

	Complex operator*(Complex lhs, Complex rhs) {
		return Complex(lhs.Re(), lhs.Im()) *= rhs;
	}

	Complex operator/(Complex lhs, Complex rhs) {
		return Complex(lhs.Re(), lhs.Im()) /= rhs;
	}
	Complex operator"" i(long double im) {
		return Complex(0, im);
	}
	Complex operator"" i(unsigned long long im) {
		return Complex(0, im);
	}
	std::ostream& operator<<(std::ostream& os, Complex rhs)
	{
		return os << rhs.Re() << " + " << rhs.Im() << "i";
	}

	Rational::Rational()
		: nominator(0), denominator(1)
	{
	}

	Rational::Rational(int nominator, int denominator)
		: nominator(nominator / FindGreatestCommonDivisor(nominator, denominator) * (denominator / std::abs(denominator))),
		denominator(denominator / FindGreatestCommonDivisor(nominator, denominator) * (denominator / std::abs(denominator)))
	{
	}

	Rational::Rational(int nominator)
		: nominator(nominator), denominator(1)
	{
	}

	int Rational::Nominator() const noexcept
	{
		return nominator;
	}

	int Rational::Denominator() const noexcept
	{
		return denominator;
	}

	Rational::operator double()
	{
		return (double)nominator / denominator;
	}

	Rational Rational::operator-()
	{
		return Rational(-Nominator(), Denominator());
	}

	Rational& Rational::operator++()
	{
		return (*this) = Rational(Nominator() + Denominator(), Denominator());
	}

	Rational Rational::operator++(int)
	{
		++(*this);
		return Rational(Nominator() - Denominator(), Denominator());
	}

	Rational& Rational::operator--()
	{
		return (*this) = Rational(Nominator() - Denominator(), Denominator());
	}

	Rational Rational::operator--(int)
	{
		--(*this);
		return Rational(Nominator() + Denominator(), Denominator());
	}

	Rational& Rational::operator-=(const Rational& rhs)
	{
		return (*this) = Rational(Nominator() * rhs.Denominator() - rhs.Nominator() * Denominator(), Denominator() * rhs.Denominator());
	}

	Rational& Rational::operator+=(const Rational& rhs)
	{
		return (*this) = Rational(Nominator() * rhs.Denominator() + rhs.Nominator() * Denominator(), Denominator() * rhs.Denominator());
	}

	Rational& Rational::operator*=(const Rational& rhs)
	{
		return (*this) = Rational(Nominator() * rhs.Nominator(), Denominator() * rhs.Denominator());
	}

	Rational& Rational::operator/=(const Rational& rhs)
	{
		return (*this) = Rational(Nominator() * rhs.Denominator(), Denominator() * rhs.Nominator());
	}

	Rational operator+(const Rational& lhs, const Rational& rhs);
	Rational operator-(const Rational& lhs, const Rational& rhs);
	Rational operator*(const Rational& lhs, const Rational& rhs);
	Rational operator/(const Rational& lhs, const Rational& rhs);
	bool operator==(const Rational& lhs, const Rational& rhs);
	//auto operator<=>(const Rational& lhs, const Rational& rhs);
	std::ostream& operator<<(std::ostream&, const Rational&);

	int FindGreatestCommonDivisor(int lhs, int rhs)
	{
		lhs = std::abs(lhs);
		rhs = std::abs(rhs);
		while (lhs && rhs)
			if (lhs > rhs)
				lhs %= rhs;
			else
				rhs %= lhs;
		return rhs + lhs;
	}

	int FindLeastCommonMultiple(int rhs, int lhs)
	{
		return (int)(std::abs(rhs * lhs) / FindGreatestCommonDivisor(rhs, lhs));
	}

	Rational operator+(const Rational& lhs, const Rational& rhs)
	{
		return Rational(lhs.Nominator(), lhs.Denominator()) += rhs;
	}

	Rational operator-(const Rational& lhs, const Rational& rhs)
	{
		return Rational(lhs.Nominator(), lhs.Denominator()) -= rhs;
	}

	Rational operator*(const Rational& lhs, const Rational& rhs)
	{
		return Rational(lhs.Nominator(), lhs.Denominator()) *= rhs;
	}

	Rational operator/(const Rational& lhs, const Rational& rhs)
	{
		return Rational(lhs.Nominator(), lhs.Denominator()) /= rhs;
	}

	bool operator==(const Rational& lhs, const Rational& rhs)
	{
		return (double) lhs.Nominator() / lhs.Denominator() == (double) rhs.Nominator() / rhs.Denominator();
	}

	bool operator>(const Rational& lhs, const Rational& rhs)
	{
		return (double) lhs.Nominator() / lhs.Denominator() > (double) rhs.Nominator() / rhs.Denominator();
	}

	bool operator<(const Rational& lhs, const Rational& rhs)
	{
		return (double) lhs.Nominator() / lhs.Denominator() < (double) rhs.Nominator() / rhs.Denominator();
	}

	bool operator>=(const Rational& lhs, const Rational& rhs)
	{
		return !(lhs < rhs);
	}

	bool operator<=(const Rational& lhs, const Rational& rhs)
	{
		return !(lhs > rhs);
	}

	//// three-way compare operator
	//std::strong_ordering operator<=> (const Rational& lhs, const Rational& rhs);

	std::ostream& operator<<(std::ostream& os, const Rational& rhs)
	{
		return os << rhs.Nominator() << "/" << rhs.Denominator();
	}

}

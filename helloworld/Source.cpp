#include <iostream>

void input(int& month, int& day, int& year);
void process(int month, int day, int year, int& a, int& b, int& c, int& d, int& jdn, float& dow);
void output(int jdn, int a, int b, int c, int d, float dow);

int main()
{
	int month;
	int day;
	int year;
	int a;
	int b;
	int c;
	int d;
	int jdn;
	float dow;

	input(month, day, year);
	process(month, day, year, a, b, c, d, jdn, dow);
	output(jdn, a, b, c, d, dow);
}

void input(int& month, int& day, int& year) {
	std::cout << "Enter Month: ";
	std::cin >> month;
	std::cout << "Enter Day: ";
	std::cin >> day;
	std::cout << "Enter Year: ";
	std::cin >> year;
}

void process(int month, int day, int year, int& a, int& b, int& c, int& d, int& jdn, float& dow)
{
	a = (14 - month) / 12;
	b = (month - 3) + (12 * a);
	c = 4800 + year - a;
	d = (c / 4) - (c / 100) + (c / 400);
	jdn = day + (((153 * b) + 2) / 5) + (365 * c) + d - 32045;
	dow = (jdn + 1) % 7;
}

void output(int jdn, int a, int b, int c, int d, float dow) {
	std::cout << "JDN: " << jdn << std::endl
		<< "DOW: " << dow << std::endl
		<< "a: " << a << std::endl
		<< "b: " << b << std::endl
		<< "c: " << c << std::endl
		<< "d: " << d << std::endl;
}
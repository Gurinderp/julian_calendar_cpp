#include <iostream>

void input(int& month, int& day, int& year);
void process(int month, int day, int year, 
	int& a, int& b, int& c, 
	int& d, int& jdn, float& dow);
void output(int month, int day, int year, 
	int jdn, int a, int b, int c, int d, float dow);

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
	output(month, day, year, jdn, a, b, c, d, dow);
}

// Input module that gathers input from the user to
// provide data needed for process module calculations
void input(int& month, int& day, int& year) {
	// Asks for month
	std::cout << "Enter Month: ";
	std::cin >> month;
	// Asks for day
	std::cout << "Enter Day: ";
	std::cin >> day;
	// Asks for year
	std::cout << "Enter Year: ";
	std::cin >> year;
}

// Process module that takes in month, day, and year to 
// calculate each step
void process(int month, int day, int year, 
	int& a, int& b, int& c, 
	int& d, int& jdn, float& dow)
{
	a = (14 - month) / 12;
	b = (month - 3) + (12 * a);
	c = 4800 + year - a;
	d = (c / 4) - (c / 100) + (c / 400);
	jdn = day + (((153 * b) + 2) / 5) + (365 * c) + d - 32045;
	dow = (jdn + 1) % 7;
}

// Outputs calculations by process function showing 
// the results of a, b, c, d, DOW, and JDN
void output(int month, int day, int year, 
	int jdn, int a, int b, int c, int d, float dow) {
	std::cout << "The JDN for " << month 
		<< "/" << day 
		<< "/" << year 
		<< "is: " << jdn << std::endl
		<< "DOW: " << dow << std::endl
		<< "a: " << a << std::endl
		<< "b: " << b << std::endl
		<< "c: " << c << std::endl
		<< "d: " << d << std::endl;
}
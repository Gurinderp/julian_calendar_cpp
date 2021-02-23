#include <iostream>

void input(int& month, int& day, int& year);
void process(int month, int day, int year, int& jdn);
void output(int month, int day, int year, int jdn);

int main()
{
	int month; // Month input by user
	int day; // Day input by user
	int year; // Year input by user
	int jdn; // JDN calculation output by process module

	input(month, day, year);
	process(month, day, year, jdn);
	output(month, day, year, jdn);
}

// Input module that gathers input from the user to
// provide data needed for process module calculations
void input(int& month, int& day, int& year) 
{
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
void process(int month, int day, int year, int& jdn)
{
	// First step calculation
	int a = (14 - month) / 12;
	// Second step calculation
	int b = (month - 3) + (12 * a);
	// Third step calculation
	int c = 4800 + year - a;
	// Fourth step calculation
	int d = (c / 4) - (c / 100) + (c / 400);
	// Final calculation for JDN
	jdn = day + (((153 * b) + 2) / 5) + (365 * c) + d - 32045;
}

// Outputs calculations by process function showing 
// the results of a, b, c, d, DOW, and JDN
void output(int month, int day, int year, int jdn) 
{
	std::cout << "The JDN for " << month
		<< "/" << day
		<< "/" << year
		<< " is: " << jdn 
		<< std::endl;
}
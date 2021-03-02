#include <iostream>

void get_date(int& today_year, int& today_month, int& today_day);
void get_date(int& birthday_year, int& birthday_month, int& birthday_day);
void compute_jdn(int today_year, int today_month, int today_day, int& today_jdn);
void compute_jdn(int birthday_year, int birthday_month, int birthday_day, int& birthday_jdn);
void compute_dow(int birthday_year, int birthday_month, int birthday_day, int& birthday_dow);
void compute_days(int today_jdn, int birthday_jdn, int& days_between);
void display_results(int today_year, int today_month, int today_day, int today_jdn,
	int birthday_year, int birthday_month, int birthday_day, int birthday_jdn, int birthday_dow,
	int days_between);

int main()
{
	int today_year, today_month, today_day, today_jdn; // 
	int birthday_year, birthday_month, birthday_day, birthday_jdn; // 
	int birthday_dow, days_between; // 
	
	std::cout << "For today's date...";
	get_date(today_year, today_month, today_day);
	
	std::cout << "For your next birthday...";
	get_date(birthday_year, birthday_month, birthday_day);
	compute_jdn(today_year, today_month, today_day, today_jdn);
	compute_jdn(birthday_year, birthday_month, birthday_day, birthday_jdn);
	compute_dow(birthday_year, birthday_month, birthday_day, birthday_dow);
	compute_days(today_jdn, birthday_jdn, days_between);
	display_results(today_year, today_month, today_day, today_jdn,
		birthday_year, birthday_month, birthday_day, birthday_jdn, birthday_dow,
		days_between);
}


void get_date(int& year, int& month, int& day) 
{
	std::cout << "Enter month number (Jan=1, Feb=2, etc.): ";
	std::cin >> month;
	std::cout << "Enter day number: ";
	std::cin >> day;
	std::cout << "Enter year using four digits: ";
	std::cin >> year;
};

void compute_jdn(int year, int month, int day, int& jdn)
{
	int a, b, c, d;
	a = (14 - month) / 12;
	b = (month - 3) + (12 * a);
	c = 4800 + year - a;
	d = (c / 4) - (c / 100) + (c / 400);
	jdn = day + (((153 * b) + 2) / 5) + (365 * c) + d - 32045;
}

void compute_dow(int year, int month, int day, int& dow)
{
	int jdn;
	compute_jdn(year, month, day, jdn);
	dow = (jdn + 1) % 7;
}

void compute_days(int jdn1, int jdn2, int& days_between)
{
	days_between = jdn2 - jdn1;
}

void display_date(int year, int month, int day)
{
	std::cout << month
		<< "-"
		<< day
		<< "-"
		<< year;
}

void display_results(int today_year, int today_month, int today_day,
	int today_jdn, int birthday_year, int birthday_month, int birthday_day,
	int birthday_jdn, int birthday_dow, int days_between)
{
	std::cout << "The JDN for ";
	display_date(today_year, today_month, today_day);
	std::cout << " is " 
		<< today_jdn
		<< std::endl;
	std::cout << "The JDN for your next birthday on ";
	display_date(birthday_year, birthday_month, birthday_day);
	std::cout << " is " 
		<< birthday_jdn
		<< std::endl;
	std::cout << "The DOW on your next birthday will be "
		<< birthday_dow
		<< " (0=Sun, 1=Mon, etc.)"
		<< std::endl;
	std::cout << "Only "
		<< days_between
		<< " day(s) until your next birthday!";
}
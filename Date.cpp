using namespace std;

#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"

Date::Date()
{
  d = 1;
  m = 1;
  y = 2000;
}


Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
	// year conditional formatting, default year 2000 if invalid
	if (year >=1000 && year <= 9999) y = year;
	else
	{
		cout << "Incorrect year given " << year << ", using default value 2000."
		<< endl;
		y = 2000;
	}
	// month conditional formatting, default month Jan if invalid
	if (month > 0 && month < 13) m = month;
	else
	{
		cout << "Incorrect month given " << month << ", using default value 1."
		<< endl;
		m = 1;
	}
	bool stateLeap = isLeapYear();
	// February conditional formatting, only month where day differs per year
	if (month == 2)
	{
		if (!stateLeap)
		{
			if (day <= 0 || day > 28)
			{
				cout << "Incorrect day given "
			<< day << ", using default value 1." << endl;
				d = 1;
			}
			else d = day;
		}
		else
		{
			if(day == 0 || day > 29)
			{
				cout << "Incorrect day given "
			<< day << ", using default value 1." << endl;
				d = 1;
			}
			else d = day;
		}
	}
	// day conditional formatting for any other month
	else
	{
		if (day > validMonthDays[m-1])
		{
			cout << "Incorrect day given "
			<< day << ", using default value 1." << endl;
			d = 1;
		}
		else d = day;
	}
}

bool Date::isLeapYear() const
{
	return y%4 != 0? false: y%100 != 0? true: y%400 != 0? false: true;
}

Date& Date::operator++()
{
	// February day increment
	if (isLeapYear() && m == 2)
	{
		if (d == 29)
		{
			m += 1;
			d = 1;
			return *this;
		}
		d += 1;
	}
	// every other month increment
	else
	{
		if (d == validMonthDays[m - 1])
		{
			// year increase condition
			if (m == 12)
			{
				if (y == 9999)
				{
					cout << "Maximum year reached, resetting to default date 01/01/2000."
					<< endl;
					y = 2000;
					m = 1;
					d = 1;
					return *this;
				}
				y += 1;
				m = 1;
				d = 1;
			}
			// month increase
			else
			{
				m += 1;
				d = 1;
			}
		}
		// day increase
		else
		{
			d += 1;
		}
	}
	return *this;
}


Date Date::operator++(int n)
{
	Date dCopy(*this);
	++(*this);
	return dCopy;
}

Date& Date::operator--()
{
	// Decrementing day into february leap year condition
	if (isLeapYear() && m == 3)
	{
		if (d == 1)
		{
			m -= 1;
			d = 29;
			return *this;
		}
		d -= 1;
	}
	else
	{
		// where day is minimum value and month needs decrementing
		if (d == 1)
		{
			// where year needs decrementing
			if (m == 1)
			{
				if (y == 1000)
				{
					cout << "Minimum year reached, resetting to default date 01/01/2000."
					<< endl;
					y = 2000;
					m = 1;
					d = 1;
					return *this;
				}
				y -= 1;
				m = 12;
				d = validMonthDays[11];
			}
			// decrement month
			else
			{
				m -= 1;
				d = validMonthDays[m-2];
			}
		}
		// decrement day
		else
		{
			d -= 1;
		}
	}
	return *this;
}

Date Date::operator--(int n)
{
	Date dCopy(*this);
	--(*this);
	return dCopy;
}

bool Date::operator<(const Date& other) const
{
	// compares the values of both objects, year first, month, then day
	return this->y < other.y? true : this->y > other.y? false:
	this->m < other.m ? true: this->m > other.m? false:
	this->d < other.d? true: false;
}

bool Date::operator==(const Date& other) const
{
	return this->y == other.y && this->m == other.m && this->d == other.d?
	true:	false;
}

Date::operator string() const
{
	// adds day to output string with correct suffix
	string output = std::to_string(d);
	if (d < 10 || d > 20)
	{
		output += d%10 == 1? "st ": d%10 == 2? "nd ": d%10 == 3? "rd ": "th ";
	}
	else
	{
		output += "th ";
	}
	// adds month and year
	output += month[m-1] + " ";
	output += to_string(y);
	return output;
}

ostream &operator<<(ostream& o, const Date& d)
{
	// sets desired field width's/fills and outputs desired format
	o << setfill('0') << setw(2) << d.d << "/" << setw(2) << d.m << "/" << setw(4)
	<< d.y;
	return o;
}

bool operator>(const Date& d1, const Date& d2)
{
	return !(d1<d2 || d1 == d2);
}

bool operator<=(const Date& d1, const Date& d2)
{
	return !(d1>d2);
}

bool operator!=(const Date& d1, const Date& d2)
{
	return !(d1 == d2);
}

bool operator>=(const Date& d1, const Date& d2)
{
	return !(d1<d2);
}

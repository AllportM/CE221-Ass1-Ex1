/**
 * Date class for CE221 Assignment 1 - ex 1
 * created by msands, editted by mal
 */

#ifndef _DATE_H_
#define _DATE_H_

using namespace std;

#include <iostream>
#include <string>


/**
 * Date class provides the ability to create date objects of valid day for any given
 * year, making checks against leap years and providing functionalty of incrementing/
 * decrementing the date by 1 day and implementing comparison operators for the class
 *
 */
class Date
{ private:
    unsigned int d; // 1-31
    unsigned int m; // 1-12
    unsigned int y; // 1000-9999 (must be a 4-digit year)
    const string month[12]  = {"January", "February", "March", "April", "May",
    "June", "July", "August", "September", "October", "November", "December"};
                                                    // month title string array
    const int validMonthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31,
       30, 31}; // valid days in each month i.e ele 0 = january 31 days


  public:
    /*
     * Default no argument constructor, default date 1st January 2000 (leap year)
     */
    Date();

    /**
	 * Constructor given day, month, and year arguments. Does conditional formatting
	 * and if dates supplied are incorrect for said month/year then default values
	 * are used and error messages outputted.
	 *
	 * @param:
	 *	day - unsigned int,
	 *	month - unsigned int,
	 *	year - unsigned it
 	 */
    Date(unsigned int day, unsigned int month, unsigned int year);

	/**
	 * Member function to check if given year is a leap year
 	 *
 	 * @return bool, true if leap year
 	 */
    bool isLeapYear() const;

	/**
 	 * Overloading prefix increment operator to increase date by 1 day, whilst
 	 * checking if month/year requires increasing if day is last day in month
 	 *
 	 * @return &Date reference to instance object
 	 */
    Date& operator++();

    /**
	 * Overloading suffix increment operator, using prefix version to increment
	 *
	 * @return Date instance object with values prior to increment
 	 */
    Date operator++(int);

    /**
	 * Overloading prefix decrement operator to decrease date by 1 day, while
	 * ensuring month/year is decremented too if required
	 *
	 * @return &Date reference to instance object
 	 */
    Date& operator--();

    /**
	 * Overloading suffix decrement operator, using prefix version to decrement
	 *
	 * @return Date instance object
 	 */
    Date operator--(int);

	/**
	 * Overloading less than comparison operator
	 *
	 * @return bool, true if les than
	 */
    bool operator<(const Date& other) const;


	/*
	 * Overloading exactly equals operator
	 *
	 * @return bool, true if les than
 	 */
    bool operator==(const Date& other) const;

	/*
	 * Overloading string operator to return format in form "1st January 2000"
	 *
	 * @return string, required output
	 */
    operator string() const;


  /*
   * Overloading ostream's << operator to output date in form "01/01/2000"
   *
   * @params:
   *	o - ostream object reference
   *	d - Date object reference
   * @return:
   *	 ostream
   */
  friend ostream& operator<<(ostream& o, const Date& d);
};



/*
 * Overloading less than or equals comparison operator
 *
 * @args:
 *	d1 - Date onject reference
 *	d2 - Date object reference
 * @return bool
 */
bool operator<=(const Date& d1, const Date& d2);

/*
 * Overloading greater than comparison operator
 *
 * @params:
 *	d1 - Date onject reference
 *	d2 - Date object reference
 * @return bool
 */
bool operator>(const Date& d1, const Date& d2);

/*
 * Overloading not equals comparison operator
 *
 * @args:
 *	d1 - Date onject reference
 *	d2 - Date object reference
 * @return bool
 */
bool operator!=(const Date& d1, const Date& d2);


/*
 * Overloading greater than or equals to comparison operator
 *
 * @args:
 *	d1 - Date onject reference
 *	d2 - Date object reference
 * @return bool
 */
bool operator>=(const Date& d1, const Date& d2);

#endif

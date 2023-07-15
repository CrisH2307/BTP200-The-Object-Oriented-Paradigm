// Final Project Milestone 3 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////
/*
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
....
07/03: Beginning the MS1
07/05: Debugging Error
07/08: I'm confused whether create the default construcor or just need to create custom constructor
07/09: Segmentation Fault (Solved by Professor Jeevan Pant)
07/12: Menu Debugging Error, the problem is viewMenu and viewTitle, I separated them out because
it was easy to call the ostream helper function (Helper: Sean Muniz and Sukhman Hara)
07/13: Date Debugging Error, read and write function. cin failed didn't even print out.
I tried many times until I put os << displayTitle(os); (Initial I didnt put os) (Helper: Sean Muniz)
07/13: Small display error, and finished the MS1
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
namespace sdds {

    // Add the following global variable (for testing purposes) to the top of the sdds namespace in Date.cpp.
    bool sdds_test = false;
    int sdds_year = 2021;
    int sdds_mon = 12;
    int sdds_day = 25;



    bool Date::validate() {
        errCode(NO_ERROR);
        if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
            errCode(YEAR_ERROR);
        }
        else if (m_mon < 1 || m_mon > 12) {
            errCode(MON_ERROR);
        }
        else if (m_day < 1 || m_day > mdays()) {
            errCode(DAY_ERROR);
        }
        return !bad();
    }
    int Date::mdays()const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
    }
    int Date::systemYear()const {
        int theYear = sdds_year;
        if (!sdds_test) {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            theYear = lt.tm_year + 1900;
        }
        return theYear;
    }
    void Date::setToToday() {
        if (sdds_test) {
            m_day = sdds_day;
            m_mon = sdds_mon;
            m_year = sdds_year;
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            m_day = lt.tm_mday;
            m_mon = lt.tm_mon + 1;
            m_year = lt.tm_year + 1900;
        }
        errCode(NO_ERROR);
    }
    int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01 
        int ty = m_year;
        int tm = m_mon;
        if (tm < 3) {
            ty--;
            tm += 12;
        }
        return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
    }
    Date::Date() :m_CUR_YEAR(systemYear()) {
        setToToday();
    }
    Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
        m_year = year;
        m_mon = mon;
        m_day = day;
        validate();
    }
    const char* Date::dateStatus()const {
        return DATE_ERROR[errCode()];
    }
    int Date::currentYear()const {
        return m_CUR_YEAR;
    }

    void Date::errCode(int readErrorCode) {
        m_ErrorCode = readErrorCode;
    }
    int Date::errCode()const {
        return m_ErrorCode;
    }
    bool Date::bad()const {
        return m_ErrorCode != 0;
    }

    std::istream& Date::read(std::istream& is)
    {
        //todo: In Date::read() method: remove "flushing the keyboard" (i.e. cin.ignore(1000,'\n')) at the end of your read function. 
        //      The read function should not flush the keyboard when the reading process is done.

        // Clearing the error code
        errCode(NO_ERROR);

        // Ignores a single character after the year and the month values to bypass the Slashes.
        is >> m_year;
        is.ignore();
        is >> m_mon;
        is.ignore();
        is >> m_day;

        // Checks if istream has failed.
        // If it did fail, it will set the error code to CIN_FAILED and clears the istream.
        if (!is)
        {
            is.clear();
            errCode(CIN_FAILED);
        }
        // If not, it will validate the values entered.
        else
        {
            validate();
            is.clear();
        }

        is.ignore(1000, '\n');
        return is;
    }
    std::ostream& Date::write(std::ostream& os) const
    {

        if (bad())
        {
            os << dateStatus();
        }
        else
        {
            char fuck = os.fill();
            os << this->m_year;
            os << '/';

            // Prints the month in two spaces, padding the left digit with zero if the month is a single - digit number
            os.setf(ios::right);
            os.fill('0');
            os.width(2);
            os << this->m_mon;
            os << '/';

            // Prints the day in two spaces, padding the left digit with zero if the day is a single - digit number
            os.fill('0');
            os.width(2);
            os << this->m_day;
            os.unsetf(ios::right);

            os.fill(fuck);
        }
        return os;
    }

    bool Date::operator==(const Date& that) const
    {
        return (this->daysSince0001_1_1() == that.daysSince0001_1_1()); // Compares the number of days since January 1, 0001 for both dates
    }

    bool Date::operator!=(const Date& that) const
    {
        return (this->daysSince0001_1_1() != that.daysSince0001_1_1()); // Compares the number of days since January 1, 0001 for both dates
    }

    bool Date::operator>=(const Date& that) const
    {
        return (this->daysSince0001_1_1() >= that.daysSince0001_1_1()); // Compares the number of days since January 1, 0001 for both dates
    }

    bool Date::operator<=(const Date& that) const
    {
        return (this->daysSince0001_1_1() <= that.daysSince0001_1_1()); // Compares the number of days since January 1, 0001 for both dates
    }

    bool Date::operator<(const Date& that) const
    {
        return (this->daysSince0001_1_1() < that.daysSince0001_1_1()); // Compares the number of days since January 1, 0001 for both dates
    }

    bool Date::operator>(const Date& that) const
    {
        return (this->daysSince0001_1_1() > that.daysSince0001_1_1()); // Compares the number of days since January 1, 0001 for both dates
    }

    Date::operator bool() const
    {
        return !bad();
    }

    int Date::operator-(const Date& that) const
    {
        return daysSince0001_1_1() - that.daysSince0001_1_1();
    }

    ostream& operator<<(ostream& os, const Date& RO) 
    {
        return RO.write(os);
    }
    istream& operator>>(istream& is, Date& RO) 
    {
        return RO.read(is);
    }

}

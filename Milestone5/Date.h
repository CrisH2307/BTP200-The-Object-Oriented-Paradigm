// Final Project Milestone 5
// Date Module
// File	Date.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////
/*
ID: 105444228
Author:	Cris Huynh
Revision History
-----------------------------------------------------------
Date        Reason
2023/07/02  Preliminary release
2023/?/?    Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
MILESTONE JOURNAL:

MS1:
07/03: Beginning the MS1
07/05: Debugging Error
07/08: I'm confused whether create the default construcor or just need to create custom constructor
07/09: Segmentation Fault (Solved by Professor Jeevan Pant)
07/12: Menu Debugging Error, the problem is viewMenu and viewTitle, I separated them out because
it was easy to call the ostream helper function (Helper: Sean Muniz and Sukhman Hara)
07/13: Date Debugging Error, read and write function. cin failed didn't even print out.
I tried many times until I put os << displayTitle(os); (Initial I didnt put os) (Helper: Sean Muniz)
07/13: Small display error, and finished the MS1

MS2:
07/10: Start working on MS2, set attributes and implement LibApp.cpp
07/13: Start debugging on MS2, i didnt know how to implement the confirm when i need to
add Yes. Until my friend help me for using the attribute << "Yes". (Helper: Preet Patel)
07/14: Run function's errors because my loop was infinite until I saw that the issue
that I got is i made a wrong bool value when inside the loop (true ==> false, Helper: Mandhav and Preet Patel)
07/14: Finished

MS3:
07/21: Started MS3
07/22: Debug errors (Segmentation Fault)
07/24: I was stuck with copy assignment and copy constructor(Helper: Sean Muniz, Kabir Nalula)
07/25: Stuck with write and read function (Helper: Preet Patel, Nand Patel, Sukhman Hara)
07/28: Fix some format error and fill char, finished


MS4:
07/25: Started declare and implement the function
07/31: Finished the implementation, but memory leaks and segmentation fault
08/01: Debug the error, the memory leaks on Publication and Book, also
istream error that didnt print 220 lines of book (Helper: Sean Muniz)
08/01: Finised MS4


MS5:
07/19: Started MS5
07/20: Working on method, attributes and functions 
07/23: Implement the cpp file, add PublicSelector modules
07/28: Fixing compiler errors from publication because the format error
07/31: Fixing logic error from the menu, LibApp for the publication selector
08/01: Finished fixing Publication and Menu. Debug error starts with leaks segmentation fault
08/02: Adding Python auto input files, finished the compilation but logic error
08/03: Debug Problem 1: New Publication function, Load function
+ When I tried to input the publication, it didnt ignore the new line and kept me a blank space, 
I was helped my Sean Muniz and Madhav Rajpall for get rid of cin.lcear and cin.ignore() on Publication
beacuse I had already called the ignore on LilApp, and I need to delete one on Publication
+ Load and save function gave me memory leaks, Sean Muniz helped me fixing by passing the dereference instead of
local variable
08/03: Debug Problem 2: Remove and Search function
+ Remove Publication gave me too much ignore line, I decided to get rid of the getline and ignore on the LibApp function
+ Search is the most difficult fuction that I have done for MS5. I couldn't understand what should I return the function(int or void).
Sean Muniz and Sukhman Hara gave me advices and fix the return function so that when I call search for Publication fucntions, I can
call the argument and then it will return the number that it can pass the logic on every Publication function.
08/04: Debug Problem 3: Memory leaks
+ Today, I haven't even test any milestone test beacuse it gave me too much memory leaks.
+ Sean Muniz and Madhav Rajpall helped me to fix the leak by making Destructor, the instruction didnt say anything about it.
Also I just got rid of Default Constructor because the tester calls with argument, so I just needed to create only one 
constructor with a parameter.
08/05: Tested, compilation and endl
+ I just got some formatting error, I forgot endl, forgot to unsetf
+ However the all program was successful
+ Finished MS5 with 6 tests

Milestone form 1 to 5 Helper:
+ Sean Muniz
+ Preet Patel
+ Madhav Rajpall
+ Kabir Narula
+ Nand Patel
+ Joseph Chu
+ Sukhman Hara

-----------------------------------------------------------
*/

#ifndef _SDDS_DATE_H__
#define _SDDS_DATE_H__
#include <iostream>
namespace sdds
{
    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int YEAR_ERROR = 2;
    const int MON_ERROR = 3;
    const int  DAY_ERROR = 4;
    const char DATE_ERROR[5][16] = {
       "No Error",
       "cin Failed",
       "Bad Year Value",
       "Bad Month Value",
       "Bad Day Value"
    };
    const int  MIN_YEAR = 1500;
    class Date {
    private:
        int m_year;
        int m_mon;
        int m_day;
        int m_ErrorCode;
        int m_CUR_YEAR;
        int daysSince0001_1_1()const; // returns number of days passed since the date 0001/1/1
        bool validate();             /* validates the date setting the error code and then returning the result
                                      true, if valid, and false if invalid.*/
        void errCode(int);           // sets the error code
        int systemYear()const;       // returns the current system year
        bool bad()const;             // return true if
        int mdays()const;            // returns the number of days in current month
        void setToToday();           // sets the date to the current date (system date)

    public:
        //   void setToToday();           // sets the date to the current date (system date)
        Date();                      // creates a date with current date
        Date(int year, int mon, int day); /* create a date with assigned values
                                           then validates the date and sets the
                                           error code accordingly */
        int errCode()const;         // returns the error code or zero if date is valid
        const char* dateStatus()const;  // returns a string corresponding the current status of the date
        int currentYear()const;         // returns the m_CUR_YEAR value;

        std::istream& read(std::istream& is = std::cin);

        std::ostream& write(std::ostream& os = std::cout)const;


        //! Comparison operator overload methods
        bool operator!=(const Date& that)const;
        bool operator>=(const Date& that)const;
        bool operator==(const Date& that)const;
        bool operator<=(const Date& that)const;
        bool operator<(const Date& that)const;
        bool operator>(const Date& that)const;

        //!  bool type conversion operator
        operator bool() const;

        //! Returns the difference between two Dates in days.
        int operator-(const Date& other) const;
    };
    std::ostream& operator<<(std::ostream& os, const Date& RO);
    std::istream& operator>>(std::istream& is, Date& RO);


    // Add the following to the bottom of the sdds namespace; 
    // This will make the global variables added to Date.cpp, truly global for any code including "Date.h".
    extern bool sdds_test;
    extern int sdds_year;
    extern int sdds_mon;
    extern int sdds_day;
}
#endif




/*
Final Project Milestone 5
Filename: LibApp.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include "Menu.h"
#include "Utils.h"
#include "LibApp.h"
#include "Date.h"
#include "Publication.h"
#include "Lib.h"
#include "Streamable.h"
#include "PublicationSelector.h"
#include "Book.h"

using namespace std;
namespace sdds
{
    

    LibApp::LibApp(const char* filename) 
    : 
    m_mainMenu("Seneca Library Application"), 
    m_exitMenu("Changes have been made to the data, what would you like to do?"), 
    m_nolp(0), 
    m_pubTypeMenu("Choose the type of publication:")

    {
        this->m_changed = false;

        if (filename)
        {
            strcpy(this->m_filename, filename);
        }

        this->m_mainMenu << "Add New Publication" ;
        this->m_mainMenu << "Remove Publication";
        this->m_mainMenu << "Checkout publication from library";
        this->m_mainMenu << "Return publication to library";

        this->m_exitMenu << "Save changes and exit";
        this->m_exitMenu << "Cancel and go back to the main menu";

        this->m_pubTypeMenu << "Book";
        this->m_pubTypeMenu << "Publication";

        load();
    }

    bool LibApp::confirm(const char* message)
    {
        Menu confirmMenu(message);
        confirmMenu << "Yes";
        return confirmMenu.run() == 1;
    }

    void LibApp::load()
    {
        //Todo
        /*
        First print "Loading Data" and then open the data file for reading and read all the 
        publications in dynamic instances pointed by the PPA Array.
        Do this by first reading a single character for the type of publication and then dynamically instantiating
        the corresponding object into the next available PPA element. Then extract the object from the file stream and add one to the NOLP.
        Since the extraction operator calls the proper read function virtually, the object will be properly read from the file.
        Continue this until the ifstream reading fails.
        At the end set the LLRN to the reference number of the last publication read.
        See the pubSel_Tester.cpp that uses a similar logic to load the publications for example...
        */

        cout << "Loading Data";
        cout << endl;
        ifstream f(m_filename);

        char type;
        for (int i = 0; i < SDDS_LIBRARY_CAPACITY and f; i++) 
        {
            f >> type;
            f.ignore();
            if (f) 
            {
                if (type == 'B') 
                {
                    m_ppa[i] = new Book;
                }
                else if (type == 'P') 
                {
                    m_ppa[i] = new Publication;
                }


                if (m_ppa[i]) 
                {
                    f >> *m_ppa[i];
                    m_nolp++;
                    m_llrn = m_ppa[i]->getRef();
                }

            }

        }

    }

    void LibApp::save()
    {
        //TODO
        /*
        First print "Saving Data" and then open the data file stream for overwriting. 
        (ofstream) Go through the elements of PPA up to the N0LP. Insert all elements into the ofstream 
        object except those with 0 (zero) as Library Reference Number. (return value of getRef() method)
        Publications that have the reference number of 0 (zero) are deleted by the user (removed from the library)
        and therefore should not be saved back into the data file. We refer to these publications as deleted ones.
        */

        cout << "Saving Data" << endl;
        ofstream f(m_filename);

        for (int i = 0; i < m_nolp; i++) 
        {
            if (m_ppa[i]->getRef() != 0) 
            {
                f << *m_ppa[i] << endl;
            }
        }
    }

    int LibApp::search(int mode)
    {
        //todo
        /*
        Add needed arguments so the search function can be called in three different modes:

        1. Search all
        2. Search Checkout Items Search only those publications which are on loan by library members
        3. Search Available Items Search only those publications which are not on loan

        Search will use an instance of PublicationSelector class to collect the search matches and user selection. 
        The prompt of the PublicSelector should be: "Select one of the following found matches:
        *" The page size for the selector menu should be 15" (the default value)
        First, get the type of publication to search for from the user. (user the type selection Menu of the class)
        Then print "Publication Title: " and get the title to search the PPA for. (up to 256 characters)
        Go through all the publications in the PPA and base on the method of search (all the items, on loan items or available ones) check each element and if the publication 
        (pointed by the PPA element) is not deleted and type matches the selection of the user and the title contains the title the user entered, insert it into the PublicationSelector object.
        If matches are found, sort the result and get the user's selection and return the library reference number. If not print "No matches found!"
        If the user aborts at any stage print "Aborted!"

        *Abort Scenarios (searching all)
        Choose the type of publication:
        1- Book
        2- Publication
        0- Exit
        > 0
        Aborted!
        -------------------------------------------------------
        Choose the type of publication:
        1- Book
        2- Publication
        0- Exit
        > 1
        Publication Title: Harry
        Select one of the following found matches:
          Row  |LocID | Title                          |Mem ID | Date       | Author          |
        ------+------+--------------------------------+-------+------------+-----------------|
        1- | T343 | Harry Potter.................. | 65205 | 2023/07/19 | J. K. Rowling   |
        2- | F861 | Harry Potter and the Chamber o |  N/A  | 2023/07/24 | J. K. Rowling   |
        3- | C872 | Harry Potter and the Deathly H | 64984 | 2023/07/17 | J. K. Rowling   |
        4- | C945 | Harry Potter and the Goblet of |  N/A  | 2023/07/14 | J. K. Rowling   |
        5- | C332 | Harry Potter and the Half/Bloo | 85952 | 2023/07/22 | J. K. Rowling   |
        6- | L290 | Harry Potter and the Order of  |  N/A  | 2023/07/11 | J. K. Rowling   |
        7- | D208 | Harry Potter and the Philosoph | 72685 | 2023/07/19 | J. K. Rowling   |
        8- | R856 | Harry Potter and the Prisoner  |  N/A  | 2023/07/10 | J. K. Rowling   |
        > X (to Exit)
        > Row Number(select publication)
        > x
        Aborted!

        *Search on loan
        Choose the type of publication:
        1- Book
        2- Publication
        0- Exit
        > 1
        Publication Title: Harry
        Select one of the following found matches:
          Row  |LocID | Title                          |Mem ID | Date       | Author          |
        ------+------+--------------------------------+-------+------------+-----------------|
        1- | T343 | Harry Potter.................. | 65205 | 2023/07/19 | J. K. Rowling   |
        2- | C872 | Harry Potter and the Deathly H | 64984 | 2023/07/17 | J. K. Rowling   |
        3- | C332 | Harry Potter and the Half/Bloo | 85952 | 2023/07/22 | J. K. Rowling   |
        4- | D208 | Harry Potter and the Philosoph | 72685 | 2023/07/19 | J. K. Rowling   |
        > X (to Exit)
        > Row Number(select publication)
        >

        *Search available publications
        Choose the type of publication:
        1- Book
        2- Publication
        0- Exit
        > 1
        Publication Title: Harry
        Select one of the following found matches:
        Row  |LocID | Title                          |Mem ID | Date       | Author          |
        ------+------+--------------------------------+-------+------------+-----------------|
        1- | F861 | Harry Potter and the Chamber o |  N/A  | 2023/07/24 | J. K. Rowling   |
        2- | C945 | Harry Potter and the Goblet of |  N/A  | 2023/07/14 | J. K. Rowling   |
        3- | L290 | Harry Potter and the Order of  |  N/A  | 2023/07/11 | J. K. Rowling   |
        4- | R856 | Harry Potter and the Prisoner  |  N/A  | 2023/07/10 | J. K. Rowling   |
        > X (to Exit)
        > Row Number(select publication)
        >

        */
       
        PublicationSelector that("Select one of the following found matches:");
        int selectedType = m_pubTypeMenu.run();
        char t;

            if (selectedType == 1) 
            {
                t = 'B';
            }
            else if (selectedType == 2) 
            {
                t = 'P';
            }
            else 
            {
                cout << "Aborted!" << endl;
            }   
        
        cout << "Publication Title: ";
        char title[256]{};
        cin.getline(title, 256);

        if (mode == 1) 
        {
            for (int i = 0; i < m_nolp; i++) 
            {
                if (m_ppa[i]->getRef() != 0 and 
                    m_ppa[i]->operator==(title) and 
                    m_ppa[i]->type() == t) 
                {
                    that << m_ppa[i];
                }
            }
        }

        if (mode == 2) 
        {
            for (int i = 0; i < m_nolp; i++) 
            {
                if (m_ppa[i]->getRef() != 0 and 
                    m_ppa[i]->operator==(title) and 
                    m_ppa[i]->type() == t and 
                    m_ppa[i]->onLoan()) 
                {
                    that << m_ppa[i];
                }
            }
        }

        if (mode == 3) 
        {
            for (int i = 0; i < m_nolp; i++) 
            {
                if (m_ppa[i]->getRef() != 0 and 
                    m_ppa[i]->operator==(title) and 
                    m_ppa[i]->type() == t and 
                    !m_ppa[i]->onLoan()) 
                {
                    that << m_ppa[i];
                }
            }
        }

        int libRef = 0;

        if (that) 
        {
            that.sort();
            libRef = that.run();
            if (libRef > 0)
            {
                cout << *getPub(libRef) << endl;
            }
            else 
            {
                cout << "Aborted!" << endl;;
            }
        }
        else 
        {
            cout << "No matches found!" << endl;
        }

        return libRef;
    }

    Publication* LibApp::getPub(int libRef)
    {
        //todo
        // Create a method to return the address of a Publication object 
        // in the PPA that has the library reference number matching the "libRef" argument.

        Publication* pub = nullptr;

        for (int i = 0; i < m_nolp; ++i)
        {
            if (m_ppa[i]->getRef() == libRef) 
            {
                pub = m_ppa[i];
            }
        }
        return pub;
    }

    void LibApp::returnPub()
    {
        //todo:
        /*
        Print: "Return publication to the library"
        Search for "on loan" publications only
        If the user selects a publication and confirms the return using the prompt: "Return Publication?"
        If the publication is more than 15 days on loan, a 50 cents per day penalty will be calculated for the number of days exceeding the 15 days.
        Following message is printed: Please pay $9.99 penalty for being X days late!, 9.99 is replaced with the penalty value and X is replaced with the number of late days.
        set the membership number of the publication to 0 (zero)
        set the "changed" flag to true
        print: "Publication returned"

        *Returning publication to library

        Seneca Library Application
        1- Add New Publication
        2- Remove Publication
        3- Checkout publication from library
        4- Return publication to library
        0- Exit
        > 4
        Return publication to the library
        Choose the type of publication:
        1- Book
        2- Publication
        0- Exit
        > 1
        Publication Title: Harry
        Select one of the following found matches:
        Row  |LocID | Title                          |Mem ID | Date       | Author          |
        ------+------+--------------------------------+-------+------------+-----------------|
        1- | T343 | Harry Potter.................. | 65205 | 2023/07/19 | J. K. Rowling   |
        2- | C872 | Harry Potter and the Deathly H | 64984 | 2023/07/17 | J. K. Rowling   |
        3- | C332 | Harry Potter and the Half/Bloo | 85952 | 2023/07/22 | J. K. Rowling   |
        4- | D208 | Harry Potter and the Philosoph | 72685 | 2023/07/19 | J. K. Rowling   |
        > X (to Exit)
        > Row Number(select publication)
        > 2
        | C872 | Harry Potter and the Deathly H | 64984 | 2023/07/17 | J. K. Rowling   |
        Return Publication?
        1- Yes
        0- Exit
        > 1
        Please pay $4.00 penalty for being 8 days late!
        Publication returned
        */   

        cout << "Return publication to the library" << endl;
        int libRef = search(2);

        if (libRef > 0) 
        {
            if (confirm("Return Publication?")) 
            {
                int days = Date() - getPub(libRef)->checkoutDate();

                if (days > SDDS_MAX_LOAN_DAYS) 
                {
                    double penalty = (days - SDDS_MAX_LOAN_DAYS) * 0.5;
                    cout << fixed << setprecision(2) << "Please pay $" << penalty << " penalty for being " << (days - SDDS_MAX_LOAN_DAYS) << " days late!" << endl;
                }

                getPub(libRef)->set(0);
                m_changed = true;
            }

            cout << "Publication returned" << endl;
        }

        cout << endl;
    }

    void LibApp::newPublication()
    {
        //todo
        /*
        If the NOLP is equal to the SDDS_LIBRARY_CAPACITY, print: "Library is at its maximum capacity!" and exit.

        Otherwise,

        print: "Adding new publication to the library"
        get the publication type from the user.
        in a publication pointer, instantiate a dynamic "Publication" or "Book" based on the user's choice.
        Read the instantiated object from the cin object.
        If the cin fails, flush the keyboard, print "Aborted!" and exit.
        If the cin is ok, then confirm that the user wants to add the publication to the library using this prompt:
        * "Add this publication to the library?". 
        If the user did not confirm, print "Aborted!" and exit.
        After the user confirms, if the publication object is valid
        Add one to the LLRN and set the library reference number to the value
        Add the publication object's address to the end of the PPA and add one to the NOLP.
        set the "changed" flag to true
        print: "Publication added"
        If the publication object is not valid print: "Failed to add publication!" and delete the allocated memory.

        *Adding a new publication to the library:

        Seneca Library Application
        1- Add New Publication
        2- Remove Publication
        3- Checkout publication from library
        4- Return publication to library
        0- Exit
        > 1
        Adding new publication to the library
        Choose the type of publication:
        1- Book
        2- Publication
        0- Exit
        > 2
        Shelf No: S001
        Title: Seneca Student Handbook
        Date: 2022/1/5
        Add this publication to the library?
        1- Yes
        0- Exit
        > 1
        Publication added

        */

        bool ok = false;
        if (m_nolp == SDDS_LIBRARY_CAPACITY) 
        {
            cout << "Library is at its maximum capacity!" << endl;
            ok = true;
        }
        
        if (!ok) 
        {
            cout << "Adding new publication to the library" << endl;
            int those = m_pubTypeMenu.run();
            Publication* that = nullptr;

            if (those == 0) 
            {
                cout << "Aborted!" << endl;
                ok = true;
            }
            else if (those == 1) 
            {
                that = new Book;
                cin >> *that;
            }
            else if (those == 2) 
            {
                that = new Publication;
                cin >> *that;
            }

            if (cin.fail()) 
            {
                cin.ignore(1000, '\n');
                cin.clear();
                cout << "Aborted!" << endl;
                ok = true;
            }
            else 
            {
                if (!ok and confirm("Add this publication to the library?")) 
                {
                    if (*that) 
                    {
                        m_llrn++;
                        that->setRef(m_llrn);
                        m_ppa[m_nolp] = that;
                        m_nolp++;
                        m_changed = true;
                        cout << "Publication added" << endl;
                    }
                    else 
                    {
                        cout << "Failed to add publication!" << endl;
                        delete that;
                    }
                }
            }
        }
        cout << endl;
    }

    void LibApp::removePublication()
    {
        //todo:
        /*
        print: "Removing publication from the library"
        Search all the publications
        If the user selects a publication and confirms to remove the publication using the prompt: 
        * "Remove this publication from the library?"
        Set the library reference of the selected publication to 0 (zero)
        set the "changed" flag to true
        print: "Publication removed"

        *removing a publication from the library

        Seneca Library Application
        1- Add New Publication
        2- Remove Publication
        3- Checkout publication from library
        4- Return publication to library
        0- Exit
        > 2
        Removing publication from the library
        Choose the type of publication:
        1- Book
        2- Publication
        0- Exit
        > 2
        Publication Title: Sen
        Select one of the following found matches:
        Row  |LocID | Title                          |Mem ID | Date       | Author          |
        ------+------+--------------------------------+-------+------------+-----------------|
          1- | P008 | MoneySense Magazine........... |  N/A  | 2023/07/11 |
          2- | P008 | MoneySense Magazine........... | 72614 | 2023/07/16 |
          3- | P008 | MoneySense Magazine........... | 48096 | 2023/07/17 |
          4- | P008 | MoneySense Magazine........... | 89325 | 2023/07/17 |
          5- | P008 | MoneySense Magazine........... | 33074 | 2023/07/17 |
          6- | P008 | MoneySense Magazine........... |  N/A  | 2023/07/18 |
          7- | P008 | MoneySense Magazine........... | 70451 | 2023/07/24 |
          8- | S001 | Seneca Student Handbook....... |  N/A  | 2022/01/05 |
        > X (to Exit)
        > Row Number(select publication)
        > 8
        | S001 | Seneca Student Handbook....... |  N/A  | 2022/01/05 |
        Remove this publication from the library?
        1- Yes
        0- Exit
        > 1
        Publication removed
        */


        cout << "Removing publication from the library" << endl;
        int libRef = search(1);
        if (libRef) 
        {
            if (confirm("Remove this publication from the library?")) 
            {
                getPub(libRef)->setRef(0);
                m_changed = true;
                cout << "Publication removed" << endl;
            }
        }
        cout << endl;
    }

    void LibApp::checkOutPub()
    {
        //todo:
        /*
        print: "Checkout publication from the library"
        Search in available publications only
        If the user selects a publication and confirms to checkout using the prompt: "Check out publication?"
        read a 5 digit number from the console, if invalid print: "Invalid membership number, try again: " and read again
        set the membership number of the selected publication the integer value.
        set the changed flag to true
        print: "Publication checked out"

        *Checking out a publication

        Seneca Library Application
        1- Add New Publication
        2- Remove Publication
        3- Checkout publication from library
        4- Return publication to library
        0- Exit
        > 3
        Checkout publication from the library
        Choose the type of publication:
        1- Book
        2- Publication
        0- Exit
        > 2
        Publication Title: Sen
        Select one of the following found matches:
        Row  |LocID | Title                          |Mem ID | Date       | Author          |
        ------+------+--------------------------------+-------+------------+-----------------|
        1- | P008 | MoneySense Magazine........... |  N/A  | 2023/07/11 |
        2- | P008 | MoneySense Magazine........... |  N/A  | 2023/07/18 |
        3- | S001 | Seneca Student Handbook....... |  N/A  | 2024/01/05 |
        > X (to Exit)
        > Row Number(select publication)
        > 3
        | S001 | Seneca Student Handbook....... |  N/A  | 2022/01/05 |
        Check out publication?
        1- Yes
        0- Exit
        > 1
        Enter Membership number: 12345
        Publication checked out

        */

        cout << "Checkout publication from the library" << endl;
        int libRef = search(3);
        if (libRef) 
        {
            if (confirm("Check out publication?")) 
            {
                cout << "Enter Membership number: ";
                bool ok = false;
                int memNumber;

                while (!ok) 
                {
                    cin >> memNumber;
                    if (!cin or memNumber < 10000 or memNumber > 99999) 
                    {
                        cout << "Invalid membership number, try again: ";
                        cin.clear();
                        cin.ignore(3000, '\n');
                        ok = false;
                    }
                    else 
                    {
                        ok = true;
                    }
                }

                getPub(libRef)->set(memNumber);
                m_changed = true;
                cout << "Publication checked out" <<  endl;
            }
        }
        cout << endl;  
    }

    LibApp::~LibApp()
    {
        for (int i = 0; i < m_nolp; ++i) 
        {
            delete m_ppa[i];
        }
    }

    void LibApp::run()
    {
        bool done = false;
        while (!done)
        {
            // Display the main menu
            int choice = this->m_mainMenu.run();

            // Call the corresponding private method based on the user's selection
            switch (choice)
            {
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            case 0:
                // User selected exit, check if changes were made
                if (m_changed)
                {
                    // Display exit menu
                    int exitChoice = this->m_exitMenu.run();
                    if (exitChoice == 1)
                    {
                        save();
                        done = true;
                    }
                    else if (exitChoice == 2)
                    {
                        cout << endl;
                    }
                    else
                    {
                        int confirmed = confirm("This will discard all the changes are you sure?");
                        if (confirmed)
                        {
                            done = true;
                        }
                        else
                        {
                            cout << endl;
                        }
                    }
                }
                else
                {
                    // No changes made, exit program
                    done = true;
                }
                break;
            default:
                cout << "Invalid selection. Please try again." << endl;
                break;
            }
        }
        // Print termination message
        cout << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }
}

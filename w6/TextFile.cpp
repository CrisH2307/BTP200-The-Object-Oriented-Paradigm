/*
*****************************************************************************
                              TextFile.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds 
{
    //! Line class
    Line::operator const char* () const 
    {
        return (const char*)m_value;
    }

    Line& Line::operator=(const char* lineValue) 
    {
        delete[] m_value;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }

    Line::~Line()
    {
        delete[] m_value;
    }

    //! TextFile class

    void TextFile::setFilename(const char* fname, bool isCopy)
    {
  
        //todo: If the isCopy argument is false, dynamically allocates a Cstring in m_filename and copies the content of the fname argument into it.
        //      If the isCopy argument is true, dynamically allocates a Cstring in m_filename and copies the content of the
        //      fname argument with a prefix of "C_" attached to it.
        if (isCopy == false)
        {
            m_filename = new char[strLen(fname) + 1];

            strCpy(m_filename, fname);
        }
        if (isCopy == true)
        {
            int newSize = strLen(fname);

            newSize += strLen("C_");

            m_filename = new char[newSize + 1];

            strCpy(m_filename, "C_");

            strCat(m_filename, fname);
        }

    }

    void TextFile::setNoOfLines()
    {
        //todo: Counts the number of lines in the file:
        //      Creates a local ifstream object to open the file with the name held in m_filename.
        //      Then it will read the file, character by character, and accumulates the number of newlines in the m_noOfLines attribute.
        //      In the end, it will increase m_noOfLines by one, just in case, the last line does not have a new line at the end.
        //      If the number of lines is zero, it will delete the m_filename and set it to nullptr. (Setting the TextFile to a safe empty state)


        char i;

        ifstream f(m_filename);

        if (f.is_open())
        {
            while (f) 
            {
                f.get(i);
                if (i == '\n')
                {
                    this->m_noOfLines++;
                }
            }
            this->m_noOfLines++;
        }
        if (this->m_noOfLines == 0)
        {
            delete[] this->m_filename;

            this->m_filename = nullptr;
        }
    }

    void TextFile::loadText()
    {
        //todo: Loads the text file m_filename into the dynamic array of Lines pointed by m_textLines :
        //      If the m_filename is null, this function does nothing.
        //      If the m_filename is not null(TextFile is not in a safe empty state), loadText() will dynamically allocate 
        //      an array of Lines pointed by m_textLines with the size kept in m_noOfLines.
        //!     Make sure m_textLine is deleted before this to prevent memory leak.
        //      Create a local instance of ifstream using the file name m_filename to read the lines of the text file.
        //      Since the length of each line is unknown, read the line using a local C++ string object and the getline helper function. 
        //      (note: this is the HELPER getline function and not a method of istream).
        //      In a loop reads each line into the string object and then sets the m_textLines array elements to the values returned by the c_str() 
        //      method of the string object until the reading fails(end of file reached).
        //      After all the lines are read, make sure to update the value of m_noOfline to the actual number of lines read
        //      (This covers the possibility of one extra empty line at the end of the file)

        //if (m_filename != nullptr)
        //{
        //    delete[]this->m_textLines;

        //    this->m_textLines = new Line[m_noOfLines];

        //    ifstream f(m_filename);
        //    if (f.is_open())
        //    {
        //        const int bufSize = 256;  // Adjust the buffer size as needed
        //        char buf[bufSize];

        //        int lineIndex = 0;
        //        while (f.getline(buf, bufSize))
        //        {
        //            // Determine the length of the line
        //            int lineLength = 0;
        //            while (buf[lineLength] != '\0' && buf[lineLength] != '\n')
        //            {
        //                lineLength++;
        //            }

        //            // Store the line in the m_textLines array
        //            char* lineBuffer = new char[lineLength + 1];
        //            strncpy(lineBuffer, buf, lineLength);
        //            lineBuffer[lineLength] = '\0';
        //            this->m_textLines[lineIndex] = Line(lineBuffer);

        //            delete[] lineBuffer;

        //            lineIndex++;
        //        }

        //        f.close();  // Close the file after reading

        //        // Update m_noOfLines to the actual number of lines read
        //        m_noOfLines = lineIndex;
        //    }
        //}

        if (m_filename != nullptr) 
        {
            // Make sure m_textLine is deleted before this to prevent memory leak
            if (m_textLines != nullptr) 
            {
                delete[] m_textLines;
                m_textLines = nullptr;
            }

            // dynamically allocate an array of Lines with the size kept in m_noOfLines
            m_textLines = new Line[m_noOfLines];

            // ifstream using the file name m_filename to read the lines of the text file
            ifstream readfile(m_filename);
            string each;
            int count = 0;

            if (readfile.is_open()) 
            {
                // In a loop reads each line into the string object
                while (getline(readfile, each)) 
                {
                    m_textLines[count].m_value = new char[strLen(each.c_str()) + 1];
                    strCpy(m_textLines[count].m_value, each.c_str());
                    count++;
                }
            }

            // make sure to update the value of m_noOfline to the actual number of lines read
            m_noOfLines = count;
        }
    }

    void TextFile::saveAs(const char* fileName) const
    {
        //todo: Saves the content of the TextFile under a new name.
        //      Use a local ofstream object to open a new file using the name kept in the argument filename(fileName).
        //      Then loop through the elements of the m_textLines array and write them in the opened 
        //      file adding a new line to the end of each line.

        ofstream o(fileName);
            for (unsigned i = 0; i < m_noOfLines; ++i)
            {
                o << m_textLines[i] << endl;
            }
            o.close();
    }

    void TextFile::setEmpty()
    {
        //todo: deletes the m_textLines dynamic array and sets is to nullptr
        //      deletes the m_filename dynamic Cstring and sets is to nullptr sets m_noOfLines attribute to zero.

        delete[] m_textLines;
        m_textLines = nullptr;

        delete[] m_filename;
        m_filename = nullptr;

        m_noOfLines = 0;
    }

    //! Public
    TextFile::TextFile(unsigned pageSize) 
    {
        m_textLines= nullptr;
        m_filename = nullptr;
        //todo: Creates an empty TextFile and initializes the m_pageSize attribute using the pageSize argument.
        m_pageSize = pageSize;
        m_noOfLines = 0; 
    }

    TextFile::TextFile(const char* filename, unsigned pageSize) : TextFile::TextFile()
    {
        //todo: Initializes the m_pageSize attribute using the pageSize argument and all the other attributes to nullptr and zero. 
        //      Then if the filename is not null, it will set the filename, set the number of Lines and load the Text 
        //      (using the corresponding private methods.)

        if (filename != nullptr)
        {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }

    //! Rule of three implementations for classes with resource
    //! Implement The Copy Constructor, Copy assignment and destructor.
    TextFile::TextFile(const TextFile& that)
    {
        //! Copy Constructor
        //todo: Initializes the m_pageSize attribute using the m_pageSize of the incoming TextFile object and all the other attributes to nullptr and zero.
        //      If the incoming Text object is in a valid State, performs the following tasks to copy the textfile and the content safely :
        //      + Sets the file - name to the name of the incoming TextFile object(isCopy set to true) See setFilename()
        //      + Saves the content of the incoming TextFile under the file name of the current TextFile
        //      + Set the number of lines
        //      + Loads the Text

        this->m_pageSize = that.m_pageSize; //initialize m_pagesize to incoming page size from object (shallow copy)

        this->m_noOfLines = that.m_noOfLines;//shallow copy the number of lines. 

        if (that.m_textLines != nullptr)
        {
            setFilename(that.m_filename, true);
            m_textLines = new Line[that.m_noOfLines];

            for (unsigned i = 0; i < m_noOfLines; i++)
            {
                m_textLines[i].m_value = new char[strLen(that.m_textLines[i].m_value) + 1];
                strCpy(m_textLines[i].m_value, that.m_textLines[i].m_value);
            }
            saveAs(m_filename);
        }
        else
        {
            m_textLines = nullptr;
        }
    
    }

    TextFile& TextFile::operator=(const TextFile& that)
    {
        //! Copy Assignment
        // TODO: insert return statement here
        //       If the current and the incoming TextFiles are valid it will first delete the current text and then overwrites
        //       the current file and data by the content of the incoming TextFile.
        // 
        //    + deallocate the dynamic array of Text and sets the pointer to null
        //    + Saves the content of the incoming TextFile under the current filename
        //    + Sets the number of lines
        //    + loads the Text

       // Check if the current and the incoming TextFiles are valid
       if (this and that)
        {
            delete[]this->m_textLines;

            this->m_textLines = nullptr;

            that.saveAs(m_filename);

            setNoOfLines();

            loadText();
        }

        // Return a reference to the class type
        return *this;
    }

    TextFile::~TextFile()
    {
        //todo: Deletes all the dynamic data.
        delete[] m_textLines;
        m_textLines = nullptr;

        delete[] m_filename;
        m_filename = nullptr;
    }

    ostream& TextFile::view(ostream& ostr) const
    {
        //todo: Prints the filename and then the content of the file m_pageSize lines at a time.
        //      print the file name
        //      underline the file name with = character
        //      loops through the lines and print them one by line
        //      pauses after printing m_pageSize lines and prompts the user Hit ENTER to continue... 
        //      and waits for the user to press enter and repeats until all lines are printed.
        //      The function performs no action if the TextFile is in an empty state.
        //      This function receives and returns an instance of istream and uses the instance for printouts.

        if (m_filename != nullptr && m_filename[0] != '\0')
        {
            ostr << m_filename << endl;
            int ul = strLen(m_filename);
            for (int i = 0; i < ul; i++)
            {
                ostr << "=";
            }
            ostr << "\n";
            for (unsigned i = 0; i < m_noOfLines; i++)
            {
                ostr << m_textLines[i] << endl;

                if ((i + 1) % m_pageSize == 0)
                {
                    ostr << "Hit ENTER to continue...";

                    cin.ignore();
                }
            }
        }

        return ostr;
    }

    std::istream& TextFile::getFile(std::istream& istr)
    {
        // TODO: Receives a filename from istr to set the file name of the TextFile. 
        //       Then sets the number of lines and loads the Text. When done it will return the istr;

        string filename;
        getline(istr, filename);


        m_filename = new char[strLen(filename.c_str()) + 1];
        strCpy (m_filename, filename.c_str());


        setNoOfLines();
        loadText();

        return istr;


        /*getline(istr, filename);
         
        setFilename(filename);

        ifstream i(filename);

        if (!i.is_open())
        {
            return istr;
        }
        
        string line;
        int numLine = 0;
        while (getline(istr, filename));
        {
            numLine++;
        }
        
        i.close();

        this->m_noOfLines = numLine;

        loadText();*/
        

    }

    TextFile::operator bool() const
    {
        //todo: Returns true if the TextFile is not in an empty state and returns false if it is.
        bool ok = false;

        if (m_textLines != nullptr)
            ok = true;

        return ok;
    }

    unsigned TextFile::lines() const
    {
        //todo: returns m_noOfLines
        return this->m_noOfLines;
    }

    const char* TextFile::name() const
    {
        //todo: Returns the filename.
        return this->m_filename;
    }

    const char* TextFile::operator[](unsigned index) const
    {
        //todo: Returns the element in the m_textLine array corresponding to the index argument. 
        //      If the TextFile is in an empty state, it will return null. 
        //      If the index exceeds the size of the array it should loop back to the beginning.
        //      For example, if the number of lines is 10, the last index should be 9 and index 10 should 
        //      return the first element and index 11 should return the second element.
        
        if (*this)
        {
            if (index >= this->m_noOfLines)
            {
                index -= this->m_noOfLines;
            }
        }
        return m_textLines[index].m_value;

          
    }


    //! Insertion and extraction helper operator overloads
    //! To print and read on and from istream and ostream overload operator<<`` and operator>>`:

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
    {
        // TODO: uses the `view()`` method to print the TextFile
        text.view(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, TextFile& text)
    {
        // TODO: uses the `getFile()`` method to get the file name from console and load the content from the file
        text.getFile(istr);
        return istr;
    }

}
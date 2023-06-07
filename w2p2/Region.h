/*
*****************************************************************************
                              Region.h
Full Name  : Xuan Khang Huynh (Cris Huynh)
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_REGION_H
#define SDDS_REGION_H

namespace sdds
{

    /// <summary>
    /// A custom type storing information about a single region.
    /// </summary>
    struct Region
    {
        char m_postal[3+1];
        int m_pop;
    };	
    void sort();


    /// <summary>
    /// Prints to screen the collection of regions loaded from a file.
    /// </summary>
    /// <param name="areaName">the name of administrative area where those regions
    ///    are located (i.e., the city, province, country, etc.)</param>
    /// <param name="sorted">optional parameter to specify if the regions should
    ///   be sorted based on the population or not. The default value is `false`.</param>
    bool load(const char* filename);

    /// <summary>
    /// Prints to screen the collection of regions loaded from a file.
    /// </summary>
    /// <param name="areaName">the name of administrative area where those regions
    ///    are located (i.e., the city, province, country, etc.)</param>
    /// <param name="sorted">optional parameter to specify if the regions should
    ///   be sorted based on the population or not. The default value is `false`.</param>
    void display(const char* areaName, bool sorted = false);

 
    void display(const Region& region);

    /// <summary>
    /// Prints to screen the collection of regions loaded from a file.
    /// </summary>
    /// <param name="areaName">the name of administrative area where those regions
    ///    are located (i.e., the city, province, country, etc.)</param>
    /// <param name="sorted">optional parameter to specify if the regions should
    ///   be sorted based on the population or not. The default value is `false`.</param>
 
    bool load(Region& reg);


    /// <summary>
    /// Deallocated all the dynamic memory used by the program.
    /// </summary>
    void cleanUp();

}


#endif
/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

/**
* @file date.hpp
* @author Pritom Gomes (pgomes10@umd.edu)
* @author Khuzema Habib (khabib@umd.edu)
* @author Daniel Zinobile (zinobile@umd.edu)
* @brief Date class to represent day, month, and year.
* @version 0.1
* @date 11-12-2024
*
* @copyright Copyright (c) 2024
*
*/

#pragma once

#include <iostream>

class Date {
public:
    Date(unsigned short day, unsigned short month, unsigned short year)
        : day_(day), month_(month), year_(year) {}

    bool is_valid_date() const;
    bool is_leap_year() const;
    unsigned short get_days_in_month() const;
    void print_date() const;

private:
    unsigned short day_, month_, year_;
};
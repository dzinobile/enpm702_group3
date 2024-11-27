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
#include <stdexcept>
#include <sstream>

/**
 * @brief Date Class
 *
 */
class Date
{
    /**
     * @brief Public Attributes: Date Object, Valid Date Method, Leap Year Method, Get Days in the Month Method, Print Date Method
     *
     */
public:
    /**
     * @brief Construct a new Date object
     *
     * @param day
     * @param month
     * @param year
     */
    Date(unsigned short day, unsigned short month, unsigned short year)
        : day_(day), month_(month), year_(year)
    {
        if (!is_valid_date())
        {
            std::ostringstream oss;
            oss << "Invalid Date: " << day << "/" << month << "/" << year;
            throw std::invalid_argument(oss.str());
        }
    }
    /**
     * @brief Check if Date is Valid
     *
     * @return true
     * @return false
     */
    bool is_valid_date() const;
    /**
     * @brief Check if it is a Leap Year
     *
     * @return true
     * @return false
     */
    bool is_leap_year() const;
    /**
     * @brief Get the days in month object
     *
     * @return unsigned short
     */
    unsigned short get_days_in_month() const;
    /**
     * @brief Print Date Function
     *
     */
    void print_date() const;
    /**
     * @brief Private Attributes: unsigned short day_, month_, year_;
     *
     */
private:
    unsigned short day_, month_, year_;
};
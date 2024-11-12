

/// ENPM702 Assignment - 3
/// Name: Pritom Gomes

/**
* @file date.hpp
* @author Pritom Gomes (pgomes10@umd.edu)
* @author Khuzema Habib (khabib@umd.edu)
* @author Daniel Zinobile (zinobile@umd.edu)
* @brief IDBadge class to represent an employee's badge information.
* @version 0.1
* @date 11-12-2024
*
* @copyright Copyright (c) 2024
*
*/

#pragma once

#include <iostream>
#include <string>
#include "date.hpp"

/**
 * @brief 
 * 
 */
class IDBadge {
    /**
     * @brief 
     * 
     */
public:
/**
 * @brief Construct a new IDBadge object
 * 
 * @param badge_number 
 * @param issue_date 
 */
    IDBadge(const std::string& badge_number, const Date& issue_date);
/**
 * @brief 
 * 
 */
    void display_badge_info() const;
/**
 * @brief 
 * 
 */
private:
    std::string badge_number_;
    /**
     * @brief 
     * 
     */
    Date issue_date_;
};
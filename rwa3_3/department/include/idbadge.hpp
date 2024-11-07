

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

class IDBadge {
public:
    IDBadge(const std::string& badge_number, const Date& issue_date);

    void display_badge_info() const;

private:
    std::string badge_number_;
    Date issue_date_;
};

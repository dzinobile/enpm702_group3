/// ENPM702 Assignment - 3
/// Name: Pritom Gomes

/**
* @file date.hpp
* @author Pritom Gomes (pgomes10@umd.edu)
* @author Khuzema Habib (khabib@umd.edu)
* @author Daniel Zinobile (zinobile@umd.edu)
* @brief Department class that aggregates multiple Employee objects.
* @version 0.1
* @date 11-12-2024
*
* @copyright Copyright (c) 2024
*
*/

#pragma once

#include <iostream>
#include <unordered_set>
#include <memory>
#include "employee.hpp"

class Department {
public:
    void add_employee(const std::shared_ptr<Employee>& employee);
    void display_employees() const;

private:
    std::unordered_set<std::shared_ptr<Employee>> employees_;
};
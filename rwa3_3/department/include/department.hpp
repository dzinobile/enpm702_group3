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
/**
 * @brief Department Class
 *
 */
class Department
{
    /**
     * @brief Public Attributes: Add employee method, display employee method
     *
     */
public:
    /**
     * @brief Add Employee Method
     *
     * @param employee
     */
    void add_employee(const std::shared_ptr<Employee> &employee);
    /**
     * @brief Display List of employees
     *
     */
    void display_employees() const;
    /**
     * @brief Private Attributes: Unordered Set of Employees(To avoid repeated entries)
     *
     */
private:
    std::unordered_set<std::shared_ptr<Employee>> employees_;
};
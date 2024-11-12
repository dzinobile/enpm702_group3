/// ENPM702 Assignment - 3
/// Name: Pritom Gomes

/**
 * @file date.hpp
 * @author Pritom Gomes (pgomes10@umd.edu)
 * @author Khuzema Habib (khabib@umd.edu)
 * @author Daniel Zinobile (zinobile@umd.edu)
 * @brief Base class Employee with virtual functions for polymorphism.
 * @version 0.1
 * @date 11-12-2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include <iostream>
#include <string>
#include "idbadge.hpp"
/**
 * @brief Employee Class
 *
 */
class Employee
{
    /**
     * @brief Public Attributes: Employee Object, Destructor, Virtual Methods: Perform Task, Attend Meeting, Receive Salary, Return Badge Info, Return Name
     *
     */
public:
    /**
     * @brief Construct a new Employee object
     *
     * @param name
     * @param salary
     * @param idbadge
     */
    Employee(const std::string &name, int salary, const IDBadge &idbadge);
    /**
     * @brief Destroy the Employee object
     *
     */
    virtual ~Employee() = default;
    /**
     * @brief Perform Task
     *
     */
    virtual void perform_task() = 0;
    /**
     * @brief Attend Meeting
     *
     */
    virtual void attend_meeting();
    /**
     * @brief Receive Salary
     *
     */
    virtual void receive_salary();
    /**
     * @brief Return Badge info
     *
     */
    void return_badge_info() const;
    /**
     * @brief Return Name
     *
     * @return std::string
     */
    std::string return_name() const;
    /**
     * @brief Protected Attributes: Name, Salary, ID Badge
     *
     */
protected:
    std::string name_;
    int salary_;
    IDBadge idbadge_;
};
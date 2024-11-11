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

class Employee
{
public:
    Employee(const std::string &name, int salary, const IDBadge &idbadge);
    virtual ~Employee() = default;

    virtual void perform_task() = 0;
    virtual void attend_meeting();
    virtual void receive_salary();
    void return_name() const;

protected:
    std::string name_;
    int salary_;
    IDBadge idbadge_;
};
/// ENPM702 Assignment - 3
/// Name: Pritom Gomes

/**
* @file date.hpp
* @author Pritom Gomes (pgomes10@umd.edu)
* @author Khuzema Habib (khabib@umd.edu)
* @author Daniel Zinobile (zinobile@umd.edu)
* @brief Derived class Developer inheriting from Employee.
* @version 0.1
* @date 11-12-2024
*
* @copyright Copyright (c) 2024
*
*/

#pragma once

#include <unordered_set>
#include "employee.hpp"

class Developer : public Employee {
public:
    Developer(const std::string& name, int salary, const IDBadge& idbadge);

    void perform_task() override;
    void attend_meeting() override;
    void receive_salary() override;
    void write_code(const std::string& language);
    void add_programming_language(const std::string& language);
    void set_current_project(const std::string& project);

private:
    std::unordered_set<std::string> programming_languages_;
    std::string current_project_;
};
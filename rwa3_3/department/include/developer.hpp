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
/**
 * @brief Developer Class Inherits Public Attributes from Employee Class
 *
 */
class Developer : public Employee
{
    /**
     * @brief Public Attributes: Developer Object, Methods: Perform Task, Attend Meeting, Recieve Salary, Write Code, Add Programming Language, Set current Project
     *
     */
public:
    /**
     * @brief Construct a new Developer object
     *
     * @param name Employee Name
     * @param salary
     * @param idbadge
     */
    Developer(const std::string &name, int salary, const IDBadge &idbadge);
    /**
     * @brief Perform Task Method (Overriden)
     *
     */
    void perform_task() override;
    /**
     * @brief Attend Meeting Method (Overriden)
     *
     */
    void attend_meeting() override;
    /**
     * @brief Receive Salary Method (Overriden)
     *
     */
    void receive_salary() override;
    /**
     * @brief Write Code Method
     *
     * @param language programming language
     */
    void write_code(const std::string &language);
    /**
     * @brief Add Programming Language
     *
     * @param language
     */
    void add_programming_language(const std::string &language);
    /**
     * @brief Set the current project object
     *
     * @param project
     */
    void set_current_project(const std::string &project);
    /**
     * @brief Private Attributes: Unordered Set of Programming Languages, Current Project
     *
     */
private:
    std::unordered_set<std::string> programming_languages_;
    std::string current_project_;
};
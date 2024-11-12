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
 * @brief 
 * 
 */
class Developer : public Employee {
public:
/**
 * @brief Construct a new Developer object
 * 
 * @param name 
 * @param salary 
 * @param idbadge 
 */
    Developer(const std::string& name, int salary, const IDBadge& idbadge);
/**
 * @brief 
 * 
 */
    void perform_task() override;
    /**
     * @brief 
     * 
     */
    void attend_meeting() override;
    /**
     * @brief 
     * 
     */
    void receive_salary() override;
    /**
     * @brief 
     * 
     * @param language 
     */
    void write_code(const std::string& language);
    /**
     * @brief 
     * 
     * @param language 
     */
    void add_programming_language(const std::string& language);
    /**
     * @brief Set the current project object
     * 
     * @param project 
     */
    void set_current_project(const std::string& project);

private:
/**
 * @brief 
 * 
 */
    std::unordered_set<std::string> programming_languages_;
    /**
     * @brief 
     * 
     */
    std::string current_project_;
};
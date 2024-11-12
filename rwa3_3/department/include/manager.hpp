/// ENPM702 Assignment - 3
/// Name: Pritom Gomes

/**
* @file date.hpp
* @author Pritom Gomes (pgomes10@umd.edu)
* @author Khuzema Habib (khabib@umd.edu)
* @author Daniel Zinobile (zinobile@umd.edu)
* @brief Derived class Manager inheriting from Employee.
* @version 0.1
* @date 11-12-2024
*
* @copyright Copyright (c) 2024
*
*/

#pragma once

#include "employee.hpp"
#include "developer.hpp"
/**
 * @brief 
 * 
 */
class Manager : public Employee {
    /**
     * @brief 
     * 
     */
public:
/**
 * @brief Construct a new Manager object
 * 
 * @param name 
 * @param salary 
 * @param idbadge 
 * @param team_size 
 * @param number_of_projects 
 */
    Manager(const std::string& name, int salary, const IDBadge& idbadge,
            unsigned short team_size, unsigned short number_of_projects);
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
     * @param developer 
     */
    void conduct_performance_review(Developer& developer);
/**
 * @brief 
 * 
 */
private:
    unsigned short team_size_;
    unsigned short number_of_projects_;
};
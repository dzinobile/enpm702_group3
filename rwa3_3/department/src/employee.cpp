/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include "employee.hpp"
#include <iostream>
/**
 * @brief Construct a new Employee:: Employee object
 *
 * @param name
 * @param salary
 * @param idbadge
 */
Employee::Employee(const std::string &name, int salary, const IDBadge &idbadge)
    : name_(name), salary_(salary), idbadge_(idbadge) {}
/**
 * @brief Attend Meeting derived from Employee Class
 *
 */
void Employee::attend_meeting()
{
    std::cout << "Employee: attend_meeting called" << std::endl;
}
/**
 * @brief Recieve Salary derived from Employee Class
 *
 */
void Employee::receive_salary()
{
    std::cout << "Employee: receive_salary called" << std::endl;
}

/**
 * @brief Return Badge Info derived from Employee Class
 *
 */
void Employee::return_badge_info() const
{
    idbadge_.display_badge_info();
}
/**
 * @brief Return Name derived from Employee Class
 *
 * @return std::string
 */
std::string Employee::return_name() const
{
    return name_;
}
/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include "employee.hpp"
/**
 * @brief Construct a new Employee:: Employee object
 * 
 * @param name 
 * @param salary 
 * @param idbadge 
 */
Employee::Employee(const std::string& name, int salary, const IDBadge& idbadge)
    : name_(name), salary_(salary), idbadge_(idbadge) {}
/**
 * @brief 
 * 
 */
void Employee::attend_meeting() {
    std::cout << "Employee: attend_meeting called" << std::endl;
}
/**
 * @brief 
 * 
 */
void Employee::receive_salary() {
    std::cout << "Employee: receive_salary called" << std::endl;
}
/**
 * @brief 
 * 
 */
void Employee::return_name() const {
    std::cout << "Employee name: " << name_ << std::endl;
}
/**
 * @brief 
 * 
 */
void Employee::return_badge_info() const {
    idbadge_.display_badge_info();
}
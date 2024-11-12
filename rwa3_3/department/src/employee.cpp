/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include "employee.hpp"
#include <iostream>

Employee::Employee(const std::string& name, int salary, const IDBadge& idbadge)
    : name_(name), salary_(salary), idbadge_(idbadge) {}

void Employee::attend_meeting() {
    std::cout << "Employee: attend_meeting called" << std::endl;
}

void Employee::receive_salary() {
    std::cout << "Employee: receive_salary called" << std::endl;
}

void Employee::return_name() const {
    std::cout << "Employee name: " << name_ << std::endl;
}

void Employee::return_badge_info() const {
    idbadge_.display_badge_info();
}

std::string Employee::return_name_string() const{
    return name_;
}
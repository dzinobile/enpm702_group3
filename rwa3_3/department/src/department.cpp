/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include "department.hpp"

void Department::add_employee(const std::shared_ptr<Employee>& employee) {
    employees_.insert(employee);
}

void Department::display_employees() const {
    for (const auto& employee : employees_) {
        employee->return_name();
        employee->return_badge_info();
    }
}

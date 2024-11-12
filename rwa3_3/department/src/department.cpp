/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include "department.hpp"
#include "developer.hpp"
/**
 * @brief 
 * 
 * @param employee 
 */
void Department::add_employee(const std::shared_ptr<Employee>& employee) {
    employees_.insert(employee);
}
/**
 * @brief 
 * 
 */
void Department::display_employees() const {
    /**
     * @brief Construct a new for object
     * 
     * @param employees_ 
     */
    for (const auto& employee : employees_) {
        /**
         * @brief 
         * 
         */
        employee->return_name();
        employee->return_badge_info();
        
    }
}
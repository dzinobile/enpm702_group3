/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include "department.hpp"
/**
 * @brief Add Employee Function derived from Department Class
 *
 * @param employee
 */
void Department::add_employee(const std::shared_ptr<Employee> &employee)
{
    employees_.insert(employee);
}
/**
 * @brief Display Employee function derived from Department Class
 *
 */
void Department::display_employees() const
{
    std::cout << "\nEmployees: \n";
    for (const auto &employee : employees_)
    {
        std::cout << "Employee name: " << employee->return_name() << " ";
        employee->return_badge_info();
        std::cout << "\n";
    }
}

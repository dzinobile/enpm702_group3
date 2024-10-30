#include "department.hpp"
#include "employee.hpp"

#include <iostream>
#include <unordered_set>

void Department::display_employees()
{
    for (const auto &element : employees_)
    {
        std::cout << element << "\n";
    }
    std::cout << std::endl;
}

void Department::add_employee(Employee new_employee)
{
    employees_.insert(new_employee.return_name());
}
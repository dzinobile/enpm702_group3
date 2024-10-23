#include "department.hpp"
#include "employee.hpp"

#include <iostream>

void MyNamespace::Department::display_employees() {
    for (const auto& element: employees_) {
        std::cout << element << "\n";
    }
    std::cout << std::endl;
}

void MyNamespace::Department::add_employee() {
    auto new_employee_name = MyNamespace::Employee::return_name;
    

    
}




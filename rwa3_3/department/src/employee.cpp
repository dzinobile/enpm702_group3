#include "employee.hpp"
#include <iostream>

void MyNamespace::Employee::perform_task() {
    std::cout << "employee performing task\n";
}

void MyNamespace::Employee::attend_meeting() {
    std::cout << "employee attending meeting\n";
}

void MyNamespace::Employee::recieve_salary() {
    std::cout << "employee recieving salary\n";
}

std::string MyNamespace::Employee::return_name() {
    return name_;
}

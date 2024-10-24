#include "department.hpp"
#include "employee.hpp"
#include <iostream>
#include <unordered_set>
#include <set>
#include <string>
#include <array>

int main() {
    MyNamespace::Employee employee_1("Jim", 500, "1234");
    MyNamespace::Employee employee_2("Pam", 500, "4321");
    
    std::unordered_set<std::string> dept_1_employees{employee_1.return_name(), employee_2.return_name()}

   


    //MyNamespace::Department dept_1(dept_1_employees);
    //dept_1.display_employees();
    





}
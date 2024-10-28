#include "department.hpp"
#include "employee.hpp"
#include "date.hpp"
#include <iostream>
#include <unordered_set>
#include <set>
#include <string>
#include <array>

int main() {
   

   unsigned short day{28};
   unsigned short month{10};
   unsigned short year{2024};

   std::unordered_set<std::string> jim_languages{"cpp", "python"};
   std::unordered_set<std::string> pam_languages{"java", "python"};
   std::string jim_project{"project1"};
   std::string pam_project{"project1"};


   MyNamespace::Date monday(day, month, year);
   MyNamespace::IDBadge badge1("5555", monday);
   MyNamespace::IDBadge badge2("6666", monday);
   
    MyNamespace::Developer employee_1("Jim", 500, badge1, jim_languages, jim_project);
    MyNamespace::Developer employee_2("Pam", 500, badge2, pam_languages, pam_project);

    std::unordered_set<std::string> dept_1_employees{employee_1.return_name(), employee_2.return_name()};

    MyNamespace::Department dept_1(dept_1_employees);

    dept_1.display_employees();

    MyNamespace::IDBadge badge3("7777", monday);
    MyNamespace::Manager employee_3("Dwight", 80000, badge3, 5, 1);

    dept_1.add_employee(employee_3);

    dept_1.display_employees();

    employee_3.attend_meeting();

    badge1.display_badge_info();


    





}
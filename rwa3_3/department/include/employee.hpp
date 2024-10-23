#pragma once
#include <iostream>
#include <string>
//#include "idbadge.hpp"

namespace MyNamespace
{
 class Employee {
    
    
    public:
    Employee(const std::string& name, const int& salary, const std::string& idbadge): name_{name}, salary_{salary}, idbadge_{idbadge} {

    }
    void perform_task();
    void attend_meeting();
    void recieve_salary();
    std::string return_name();



    private:
    std::string name_;
    int salary_;
    std::string idbadge_;
    //MyNamespace::IDBadge idbadge_;


 };  // class Employee
} // namespace MyNamespace

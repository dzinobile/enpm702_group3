#pragma once
#include <iostream>
#include <string>
#include <unordered_set>
#include "employee.hpp"

namespace MyNamespace
{
    class Department {
        public:
        Department(std::unordered_set<std::string> employees):employees_{employees}{

        }
        void display_employees();
        
        //void add_employee();

        private:
        std::unordered_set<std::string> employees_;
    };
} // namespace MyNamespace

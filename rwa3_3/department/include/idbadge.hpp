#pragma once
#include <iostream>
#include "date.hpp"

namespace MyNamespace
{
    class IDBadge {
        public:
        IDBadge(const std::string& badge_number, const Date& issue_date) : badge_number_{badge_number}, issue_date_{issue_date}{}
        void display_badge_info();



        private:
        std::string badge_number_;
        Date issue_date_;
        
        

    }; // class IDBadge
} // namespace MyNamespace
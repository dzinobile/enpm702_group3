#pragma once
#include <iostream>

using ushort = unsigned short;

namespace MyNamespace

{
    

    class Date {
        
        public:
        Date(ushort day, ushort month, ushort year): day_{day}, month_{month}, year_{year}  {}
        bool is_valid_date();
        const ushort get_days_in_month();
        bool is_leap_year();
        const void print_date();
        const ushort return_day();
        const ushort return_month();
        const ushort return_year();




        private:
        ushort day_;
        ushort month_;
        ushort year_;


    };//class Date
} // namespace MyNamespace

#pragma once
#include <iostream>


namespace MyNamespace

{
    class Date {
        
        public:
        Date(unsigned short& day, unsigned short& month, unsigned short& year): day_{day}, month_{month}, year_{year}  {}
        bool is_valid_date();
        const unsigned short get_days_in_month();
        bool is_leap_year();
        const void print_date();
        unsigned short return_day();
        unsigned short return_month();
        unsigned short return_year();




        private:
        unsigned short day_;
        unsigned short month_;
        unsigned short year_;


    };//class Date
} // namespace MyNamespace

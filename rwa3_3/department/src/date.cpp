#include <iostream>
#include "date.hpp"

using ushort = unsigned short;

bool MyNamespace::Date::is_valid_date(){
    if (day_ <= this->get_days_in_month()) {
        return true;
    }

    else {
        return false;
    }

}

const ushort MyNamespace::Date::get_days_in_month(){
    switch (month_) {
        case 1:
            return 31;
            break;
        case 2:
            if (this->is_leap_year() == true) {
                return 29;
            }
            else {
                return 28;
            }
            break;
        case 3:
            return 31;
            break;
        case 4:
            return 30;
            break;
        case 5:
            return 31;
            break;
        case 6:
            return 30;
            break;
        case 7:
            return 31;
            break;
        case 8:
            return 31;
            break;
        case 9:
            return 30;
            break;
        case 10:
            return 31;
            break;
        case 11:
            return 30;
            break;
        case 12:
            return 31;
            break;
    }

}

bool MyNamespace::Date::is_leap_year(){
    int mod = year_%4;
    if (mod == 0) {
        return true;
    }
    else {
        return false;
    }

}

const void MyNamespace::Date::print_date(){
    
    
}

const ushort MyNamespace::Date::return_day(){
    return day_;
}

const ushort MyNamespace::Date::return_month(){
    return month_;
}

const ushort MyNamespace::Date::return_year(){
    return year_;
}
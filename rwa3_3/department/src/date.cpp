/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include "date.hpp"
/**
 * @brief Check if Valid Date derived from Date Class
 *
 * @return true
 * @return false
 */
bool Date::is_valid_date() const
{
    return day_ > 0 && day_ <= get_days_in_month() && month_ > 0 && month_ <= 12;
}
/**
 * @brief Check if Leap Year derived from Date Class
 *
 * @return true
 * @return false
 */
bool Date::is_leap_year() const
{
    return (year_ % 4 == 0 && year_ % 100 != 0) || (year_ % 400 == 0);
}
/**
 * @brief Get days in month derived from Date Class
 *
 * @return unsigned short days_in_month
 */
unsigned short Date::get_days_in_month() const
{
    static const unsigned short days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (month_ == 2 && is_leap_year()) ? 29 : days_in_month[month_ - 1];
}
/**
 * @brief Print Date derived from Date Class
 *
 */
void Date::print_date() const
{
    std::cout << day_ << "/" << month_ << "/" << year_ << std::endl;
}

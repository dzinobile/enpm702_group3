#include <iostream>
#include "idbadge.hpp"
#include "date.hpp"

void MyNamespace::IDBadge::display_badge_info() {
    std::cout << "Badge Number: " << badge_number_ << '\n';
    std::cout << "Issue Date: " << issue_date_.return_day()<< issue_date_.return_month() << issue_date_.return_year() <<'\n';
}
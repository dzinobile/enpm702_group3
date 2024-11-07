/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include "idbadge.hpp"

IDBadge::IDBadge(const std::string& badge_number, const Date& issue_date)
    : badge_number_(badge_number), issue_date_(issue_date) {}

void IDBadge::display_badge_info() const {
    std::cout << "Badge " << badge_number_ << " was issued on ";
    issue_date_.print_date();
}
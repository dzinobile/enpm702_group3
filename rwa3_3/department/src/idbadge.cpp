/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include "idbadge.hpp"
/**
 * @brief Construct a new IDBadge::IDBadge object
 * 
 * @param badge_number 
 * @param issue_date 
 */
IDBadge::IDBadge(const std::string& badge_number, const Date& issue_date)
    : badge_number_(badge_number), issue_date_(issue_date) {}
/**
 * @brief 
 * 
 */
void IDBadge::display_badge_info() const {
    std::cout << "Badge " << badge_number_ << " was issued on ";
    issue_date_.print_date();
}
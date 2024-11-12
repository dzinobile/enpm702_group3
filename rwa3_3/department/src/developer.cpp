/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include "developer.hpp"

/**
 * @brief Construct a new Developer:: Developer object
 * 
 * @param name 
 * @param salary 
 * @param idbadge 
 */
Developer::Developer(const std::string& name, int salary, const IDBadge& idbadge)
    : Employee(name, salary, idbadge) {}
/**
 * @brief 
 * 
 */
void Developer::perform_task() {
    std::cout << "Developer: perform_task called" << std::endl;
}
/**
 * @brief 
 * 
 */
void Developer::attend_meeting() {
    std::cout << "Developer: attend_meeting called" << std::endl;
}
/**
 * @brief 
 * 
 */
void Developer::receive_salary() {
    std::cout << "Developer: receive_salary called" << std::endl;
}
/**
 * @brief 
 * 
 * @param language 
 */
void Developer::write_code(const std::string& language) {
    if (programming_languages_.count(language)) {
        std::cout << "Developer: writing code in " << language << std::endl;
    } else {
        std::cout << "Developer: language " << language << " not known" << std::endl;
    }
}
/**
 * @brief 
 * 
 * @param language 
 */
void Developer::add_programming_language(const std::string& language) {
    programming_languages_.insert(language);
}
/**
 * @brief 
 * 
 * @param project 
 */
void Developer::set_current_project(const std::string& project) {
    current_project_ = project;
}
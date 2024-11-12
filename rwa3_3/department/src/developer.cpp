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
Developer::Developer(const std::string &name, int salary, const IDBadge &idbadge)
    : Employee(name, salary, idbadge) {}
/**
 * @brief Perform Task derived from Developer Class
 *
 */
void Developer::perform_task()
{
    std::cout << "Developer " << name_ << ": perform_task called" << std::endl;
}
/**
 * @brief Attend Meeting derived from Developer Class
 *
 */
void Developer::attend_meeting()
{
    std::cout << "Developer " << name_ << ": attend_meeting called" << std::endl;
}
/**
 * @brief Receive Salary derived from Developer Class
 *
 */
void Developer::receive_salary()
{
    std::cout << "Developer " << name_ << ": receive_salary called" << std::endl;
}
/**
 * @brief Write Code derived from Developer Class
 *
 * @param language
 */
void Developer::write_code(const std::string &language)
{
    if (programming_languages_.count(language))
    {
        std::cout << "Developer " << name_ << ": writing code in " << language << std::endl;
    }
    else
    {
        std::cout << "Developer " << name_ << ": language " << language << " not known" << std::endl;
    }
}
/**
 * @brief Add Programming Language derived from Developer Class
 *
 * @param language
 */
void Developer::add_programming_language(const std::string &language)
{
    if (programming_languages_.count(language))
    {
        std::cout << "Developer " << name_ << " already knows " << language << std::endl;
    }
    else
    {
        programming_languages_.insert(language);
    }
}
/**
 * @brief Set Current Project derived from Developer Class
 *
 * @param project
 */
void Developer::set_current_project(const std::string &project)
{
    current_project_ = project;
}

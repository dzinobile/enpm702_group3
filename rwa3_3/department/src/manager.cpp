/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include "manager.hpp"
#include <memory>
/**
 * @brief Construct a new Manager:: Manager object
 *
 * @param name
 * @param salary
 * @param idbadge
 * @param team_size
 * @param number_of_projects
 */
Manager::Manager(const std::string &name, int salary, const IDBadge &idbadge,
                 unsigned short team_size, unsigned short number_of_projects)
    : Employee(name, salary, idbadge), team_size_(team_size), number_of_projects_(number_of_projects) {}
/**
 * @brief Perform Task derived from Manager Class
 *
 */
void Manager::perform_task()
{
    std::cout << "Manager " << name_ << ": perform_task called" << std::endl;
}
/**
 * @brief Attend Meeting derived from Manager Class
 *
 */
void Manager::attend_meeting()
{
    std::cout << "Manager " << name_ << ": attend_meeting called" << std::endl;
}
/**
 * @brief Recieve Salary derived from Manager Class
 *
 */
void Manager::receive_salary()
{
    std::cout << "Manager " << name_ << ": receive_salary called" << std::endl;
}
/**
 * @brief Conduct Performance Review derived from Manager Class
 *
 * @param developer
 */
void Manager::conduct_performance_review(std::shared_ptr<Developer> developer)
{
    std::cout << "Manager " << name_ << ": Conducting performance review of " << developer->return_name() << std::endl;
}

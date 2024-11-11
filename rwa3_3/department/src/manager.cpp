/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include "manager.hpp"

Manager::Manager(const std::string& name, int salary, const IDBadge& idbadge,
                 unsigned short team_size, unsigned short number_of_projects)
    : Employee(name, salary, idbadge), team_size_(team_size), number_of_projects_(number_of_projects) {}

void Manager::perform_task() {
    std::cout << "Manager: perform_task called" << std::endl;
}

void Manager::attend_meeting() {
    std::cout << "Manager: attend_meeting called" << std::endl;
}

void Manager::receive_salary() {
    std::cout << "Manager: receive_salary called" << std::endl;
}

void Manager::conduct_performance_review(Developer& developer) {
    std::cout << "Manager: conducting performance review" << std::endl;
}
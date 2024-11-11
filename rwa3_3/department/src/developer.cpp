/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include "developer.hpp"

Developer::Developer(const std::string& name, int salary, const IDBadge& idbadge)
    : Employee(name, salary, idbadge) {}

void Developer::perform_task() {
    std::cout << "Developer: perform_task called" << std::endl;
}

void Developer::attend_meeting() {
    std::cout << "Developer: attend_meeting called" << std::endl;
}

void Developer::receive_salary() {
    std::cout << "Developer: receive_salary called" << std::endl;
}

void Developer::write_code(const std::string& language) {
    if (programming_languages_.count(language)) {
        std::cout << "Developer: writing code in " << language << std::endl;
    } else {
        std::cout << "Developer: language " << language << " not known" << std::endl;
    }
}

void Developer::add_programming_language(const std::string& language) {
    programming_languages_.insert(language);
}

void Developer::set_current_project(const std::string& project) {
    current_project_ = project;
}
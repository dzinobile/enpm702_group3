#include "employee.hpp"
#include <iostream>
#include <unordered_set>
#include <string>

void Employee::perform_task()
{
    std::cout << name_ << " performing task\n";
}

void Employee::attend_meeting()
{
    std::cout << name_ << " attending meeting\n";
}

void Employee::recieve_salary()
{
    std::cout << name_ << " recieving salary\n";
}

std::string Employee::return_name()
{
    return name_;
}

void Manager::conduct_performance_review()
{
    std::cout << name_ << " conducting performance review\n";
}

void Developer::write_code(const std::string &language)
{
    std::cout << name_ << " writing code in " << language << '\n';
}

void Developer::add_programming_language(const std::string new_language)
{
    programming_languages_.insert(new_language);
}

void Developer::set_current_project(const std::string new_project)
{
    current_project_ = new_project;
}

void Developer::return_languages()
{
    for (const std::string &element : programming_languages_)
    {
        std::cout << element << '\n';
    }
}
/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include <iostream>
#include <memory>
#include <vector>
#include "date.hpp"
#include "idbadge.hpp"
#include "manager.hpp"
#include "developer.hpp"
#include "department.hpp"

int main()
{
    /**
     * @brief Create New issue date objects to set the dates to be added in the IDBadge for Each employee
     *
     */
    Date issue_date1(10, 6, 2020);
    Date issue_date2(12, 5, 2024);
    /**
     * @brief Create Manager Badge and developer Badge as new IDBadge Objects
     *
     */
    IDBadge manager_badge("123DF33", issue_date1);
    IDBadge developer_badge("456GH56", issue_date2);
    /**
     * @brief Create Employees as Shared Pointers with their Respective Attributes i.e, Name, Salary, IDBadge and Team Size and Number of Projects for Managers
     *
     */
    auto manager = std::make_shared<Manager>("David Brent", 90000, manager_badge, 5, 3);
    auto developer = std::make_shared<Developer>("Gareth Keenan", 70000, developer_badge);
    /**
     * @brief Call Methods for the Developer to Perform
     *
     */
    developer->add_programming_language("C++");
    developer->add_programming_language("Python");
    developer->add_programming_language("Python");
    developer->set_current_project("ENPM702 RWA3");
    developer->write_code("Python");
    developer->write_code("Java");
    /**
     * @brief Perform Tasks for all Employees to perform
     *
     */
    std::vector<std::shared_ptr<Employee>> employees = {manager, developer};
    for (const auto &employee : employees)
    {
        employee->perform_task();
        employee->attend_meeting();
        employee->receive_salary();
    }
    /**
     * @brief Create a new Department object and perform methods
     *
     */
    Department wernham_hogg;
    wernham_hogg.add_employee(manager);
    wernham_hogg.add_employee(developer);
    wernham_hogg.display_employees();

    manager->conduct_performance_review(developer);

    return 0;
}

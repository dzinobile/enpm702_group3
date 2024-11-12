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

int main() {
    Date issue_date1(10, 6, 2020);
    Date issue_date2(12, 5, 2024);
    IDBadge manager_badge("123DF33", issue_date1);
    IDBadge developer_badge("456GH56", issue_date2);

    auto manager = std::make_shared<Manager>("David Brent", 90000, manager_badge, 5, 3);
    auto developer = std::make_shared<Developer>("Gareth Keenan", 70000, developer_badge);

    developer->add_programming_language("C++");
    developer->add_programming_language("Python");
    developer->add_programming_language("Python");
    developer->set_current_project("ENPM702 RWA3");

    std::vector<std::shared_ptr<Employee>> employees = { manager, developer };
    for (const auto& employee : employees) {
        employee->perform_task();
        employee->attend_meeting();
        employee->receive_salary();
    }

    Department wernham_hogg;
    wernham_hogg.add_employee(manager);
    wernham_hogg.add_employee(developer);
    wernham_hogg.display_employees();

    manager->conduct_performance_review(developer);

    return 0;
}

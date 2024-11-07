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
    Date issue_date(15, 8, 2024);
    IDBadge manager_badge("123DF33", issue_date);
    IDBadge developer_badge("456GH56", issue_date);

    auto manager = std::make_shared<Manager>("Alice", 90000, manager_badge, 5, 3);
    auto developer = std::make_shared<Developer>("Bob", 70000, developer_badge);

    developer->add_programming_language("C++");
    developer->add_programming_language("Python");
    developer->set_current_project("ENPM702 RWA3");

    std::vector<std::shared_ptr<Employee>> employees = { manager, developer };
    for (const auto& employee : employees) {
        employee->perform_task();
        employee->attend_meeting();
        employee->receive_salary();
    }

    Department department;
    department.add_employee(manager);
    department.add_employee(developer);
    department.display_employees();

    return 0;
}

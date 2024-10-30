#pragma once
#include <iostream>
#include <string>
#include "idbadge.hpp"
#include "date.hpp"
#include <unordered_set>

class Employee
{

public:
  Employee(const std::string &name, const int &salary, const IDBadge &idbadge) : name_{name}, salary_{salary}, idbadge_{idbadge} {}
  void perform_task();
  void attend_meeting();
  void recieve_salary();
  std::string return_name();

protected:
  std::string name_;
  int salary_;
  IDBadge idbadge_;

private:
}; // class Employee

class Manager : public Employee
{
public:
  Manager(const std::string &name, const int &salary, const IDBadge &idbadge, const int &team_size, const int &number_of_projects) : Employee(name, salary, idbadge), team_size_{team_size}, number_of_projects_{number_of_projects} {}
  void conduct_performance_review();

private:
  int team_size_;
  int number_of_projects_;
}; // class Manager

class Developer : public Employee
{
public:
  Developer(const std::string &name, const int &salary, const IDBadge &idbadge, std::unordered_set<std::string> &programming_languages, std::string &current_project) : Employee(name, salary, idbadge), programming_languages_{programming_languages}, current_project_{current_project} {}
  void write_code(const std::string &language);
  void add_programming_language(const std::string);
  void set_current_project(const std::string);
  void return_languages();

private:
  std::unordered_set<std::string> programming_languages_;
  std::string current_project_;

}; // class Developer

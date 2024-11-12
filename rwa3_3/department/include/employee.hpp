/// ENPM702 Assignment - 3
/// Name: Pritom Gomes

/**
* @file date.hpp
* @author Pritom Gomes (pgomes10@umd.edu)
* @author Khuzema Habib (khabib@umd.edu)
* @author Daniel Zinobile (zinobile@umd.edu)
* @brief Base class Employee with virtual functions for polymorphism.
* @version 0.1
* @date 11-12-2024
*
* @copyright Copyright (c) 2024
*
*/

#pragma once

#include <iostream>
#include <string>
#include "idbadge.hpp"
/**
 * @brief 
 * 
 */
class Employee {
public:
/**
 * @brief Construct a new Employee object
 * 
 * @param name 
 * @param salary 
 * @param idbadge 
 */
    Employee(const std::string& name, int salary, const IDBadge& idbadge);
    /**
     * @brief Destroy the Employee object
     * 
     */
    virtual ~Employee() = default;
/**
 * @brief 
 * 
 */
    virtual void perform_task() = 0;
    /**
     * @brief 
     * 
     */
    virtual void attend_meeting();
    /**
     * @brief 
     * 
     */
    virtual void receive_salary();
    /**
     * @brief 
     * 
     */
    void return_name() const;
    /**
     * @brief 
     * 
     */
    void return_badge_info() const;
/**
 * @brief 
 * 
 */
protected:
    std::string name_;
    int salary_;
    /**
     * @brief 
     * 
     */
    IDBadge idbadge_;
};
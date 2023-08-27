//
// Created by SRI VISHNU JSB on 2023/08/26
//
/*
An IT company named as Cloudo_Tech is maintaining the records of its employees using a linked list where the following details of employees are maintained:

Name
Employee ID
Salary
The company management is looking for an interface where they can search the details of any employee using the Employee ID. You have to implement the solution for the same in the following function:

void search_employee(int emp_id)

Input Format

First line must take the number of employees N as input Next N lines will accept the details of N employees Last line will accept the Employee ID to be searched

Example:

3
Andrew 119 34000
Robert 72 56000
Williams 210 29500
72

Constraints

N > 0 where N is the Number of employees

Employee Id is Unique.

Output Format

Output should display the name and salary of the employee:

Robert 56000

If Employee ID is not found then display

Employee does not exist

Sample Input 0

3
Ravi 16920 15000
Arvind 16921 18000
Priyanka 21427 16500
16920
Sample Output 0

Ravi 15000
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Employee
{
    string emp_name;
    int salary;
    int emp_id;
    Employee *next;
};

Employee *Cloudo_Tech = NULL;

void add_employee()
{
    // Creating Employee
    Employee *emp = new Employee;
    cin >> emp->emp_name;
    cin >> emp->emp_id;
    cin >> emp->salary;

    // Inserting Employee in the beginning of the list
    emp->next = Cloudo_Tech;
    Cloudo_Tech = emp;
}

void search_employee(int emp_id)
{
    Employee *current = Cloudo_Tech;

    while (current != NULL)
    {
        if (current->emp_id == emp_id)
        {
            cout << current->emp_name << " " << current->salary << endl;
            return;
        }
        current = current->next;
    }

    cout << "Employee does not exist" << endl;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n;
    cin >> n; // Reading number of employees

    for (int i = 0; i < n; i++) // adding employees in the list
        add_employee();

    int empToSearch;
    cin >> empToSearch;

    search_employee(empToSearch);

    return 0;
}

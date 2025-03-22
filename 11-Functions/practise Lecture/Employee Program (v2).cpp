#include <iostream>
using namespace std;
/*
            Employee Program (v2)

    ● Help our factory in managing his employees. Create a program that does the following:
        ○ Display the following choices:
            ■ Enter your choice:
            ■ 1) Add new employee
            ■ 2) Print all employees
            ■ 3) Delete by age
            ■ 4) Update Salary by name
        ○ You will keep the program running forever. Display the choices and user input from 1 to 4
    ● For choice 1: Allow the manager to enter information of an employee
        ○ Ask user to input: Name, Age, Salary and Gender letter
        ○ Add the information to your database
    ● For choice 2: Print all employees. Line per employee
    ● For choice 3: User enter to values, start age and end age
        ○ Find all employees with: start_age <= age <= end_age and remove them
    ● For choice 4: User enter name, then salary
        ○ Find the employee and update his salary
    ● See screenshots

*/

#define EMPLOYEE_NUMBERS 5
#define EMPLOYEE_INFO 4 // name , age , salary , gender

void add_employee(int& index, string info_declare[], string info[][EMPLOYEE_INFO])
{
    ++index;
    if (index > EMPLOYEE_NUMBERS - 1)
    {
        cout << "no space" << endl;
        return;
    }
    for (int j = 0; j < EMPLOYEE_INFO; ++j)
    {
        cout << "Enter " << info_declare[j] << " : ";
        cin >> info[index][j];
    }
}

void print_employees(int index, string info[][EMPLOYEE_INFO])
{
    cout << "**************" << endl;
    for (int i = 0; i <= index; ++i)
    {
        for (int j = 0; j < EMPLOYEE_INFO; ++j) {
            cout << info[i][j];
            if (j < EMPLOYEE_INFO - 1)
                cout << " ";
        }
        cout << endl;
    }
}

void delete_by_age(int& index, string info[][EMPLOYEE_INFO], int start, int end)
{
    for (int i = index; i >= 0; i--)
    {
        if (stoi(info[i][1]) >= start && stoi(info[i][1]) <= end)
        {
            // Move all employees after this one up by one position
            for (int j = i; j < index; j++)
            {
                for (int k = 0; k < EMPLOYEE_INFO; k++)
                {
                    info[j][k] = info[j + 1][k];
                }
            }
            index--;
        }
    }
}

void update_salary(int index, string info[][EMPLOYEE_INFO], string name, string salary)
{
    for (int i = 0; i <= index; ++i)
    {
        if (info[i][0] == name)
            info[i][2] = salary;
    }
}

int main() {
    int index = -1;
    string info_declare[] = { "name" , "age" , "salary" , "gender (M/F)" };
    string info[EMPLOYEE_NUMBERS][EMPLOYEE_INFO];
    while (true)
    {
        cout << "Enter your choice: " << endl;
        cout << "1) Add new employee " << endl;
        cout << "2) Print all employees " << endl;
        cout << "3) Delete by age " << endl;
        cout << "4) Update salary by name " << endl;

        int input;
        cin >> input;

        switch (input)
        {
        case 1:
            add_employee(index, info_declare, info);
            break;

        case 2:
            print_employees(index, info);
            break;

        case 3:
        {
            int start, end;
            cout << "Enter start and end age: ";
            cin >> start >> end;
            delete_by_age(index, info, start, end);
            break;
        }

        case 4:
        {
            string name , salary;
            cout << "Enter the name and the salary : ";
            cin >> name >> salary;
            update_salary(index, info, name , salary);
            break;
        }

        default:
            cout << "Enter a valid number " << endl; 
            break;
        }
    }
    return 0;
}

#include <iostream>
using namespace std;

/*
                       Employee Program (v1)

    ● Help our factory in managing his employees. Create a program that does the
        following:
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

*/

#define SIZE 5

int main() {
    int choice;
    string name[SIZE];
    int age[SIZE];
    double salary[SIZE];
    char gender[SIZE];

    int i = 0;
    while (true) {
        cout << "Enter your choice: " << endl;
        cout << "1) Add new employee" << endl;
        cout << "2) Print all employees" << endl;
        cout << "3) Delete by age" << endl;
        cout << "4) Update salary by name" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            if (i < SIZE) {
                cout << "Enter name: " << endl;
                cin >> name[i];
                cout << "Enter age: " << endl;
                cin >> age[i];
                cout << "Enter salary: " << endl;
                cin >> salary[i];
                cout << "Enter gender (M/F): " << endl;
                cin >> gender[i++];
            }
            else cout << "No space" << endl;
            break;

            case 2:
                for( int j = 0; j < i; ++j){
                    if(age[j] == -1)
                        continue;
                    cout << name[j] << " " << age[j] << " " << salary[j] << " " << gender[j] << endl;
                }
            break;

            case 3: 
                int start , end;
                cin >> start >> end;
                for( int j = 0; j < i; ++j){
                    if(age[j] >= start && age[j] <= end)
                        age[j] = -1;
                }
            break;

            case 4:
                cout << "Enter the name and salary: ";
                string employee_name;
                int update_salary;

                cin >> employee_name >> update_salary;

                for( int j = 0; j < i; ++j){
                    if(name[j] == employee_name && age[j] != -1)
                        salary[j] = update_salary;
                }
                break;

            default:
                cout << "Enter a valid number" << endl;
        }
    }

    return 0;
}

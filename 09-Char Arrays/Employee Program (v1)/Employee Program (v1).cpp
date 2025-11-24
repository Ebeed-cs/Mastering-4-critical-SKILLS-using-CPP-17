#include <iostream>
using namespace std;

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

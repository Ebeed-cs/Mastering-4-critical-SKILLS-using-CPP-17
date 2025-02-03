#include <iostream>
using namespace std;
/*

A teacher want a program that reads 2 students information about math exam
	Read per student: name, id and grade
	Then print them. See the picture in the slides


Be a good software engineer
	Think deeply in your selected data types
	The teacher gives us this dialogue to guide us
	Be careful from your assumptions?
	Is exam’s grade an integer?


*/
int main() {
    string st_name1,st_name2 ;
    int st_id1,st_id2;
    double st_grade1 , st_grade2;
    cout << "What is student 1 name: ";
    cin >> st_name1;
    cout << "His id: ";
    cin >> st_id1;
    cout << "His math exam grade: ";
    cin >> st_grade1;

    cout << "What is student 2 name: ";
    cin >> st_name2;
    cout << "His id: ";
    cin >> st_id2;
    cout << "His math exam grade: ";
    cin >> st_grade2;

    cout << endl;
    cout << "Students grades in math" <<endl;
    cout << st_name1 << " (with id " << st_id1 << ")";
    cout << " got grade: " << st_grade1 << endl;
     
    cout << st_name2 << " (with id " << st_id1 << ")";
    cout << " got grade: " << st_grade2 << endl;

    cout << "Average grade is " << (st_grade1 + st_grade2) / 2 << endl;
    return 0;
}


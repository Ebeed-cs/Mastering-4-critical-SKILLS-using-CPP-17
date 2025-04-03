#include <iostream>
using namespace std;

/*
				Hospital System
*/
#define SPECIALIZATION_NUM 20
#define SPOTS_NUM 5
string spec[100][50];
int index_element[100] = {0};

void menu() {
    cout << "1) Add new patient." << endl;
    cout << "2) Print all patients." << endl;
    cout << "3) Get next patient." << endl;
    cout << "4) Exit." << endl;
}

void add_new(){
    int spec_num, status;
    string name;
    cout << "Enter specialization , num , status: " << endl;
    cin >> spec_num >> name >> status;
    if(index_element[--spec_num] >= SPOTS_NUM)
        cout << "Sorry we can't add new patients for this specialization" << endl;
    else if(!status)
        spec[spec_num][index_element[spec_num]++] = name + " regular";
    else{
        for(int i = index_element[spec_num] ; i > 0 ; --i)
            spec[spec_num][i] = spec[spec_num][i - 1];
        spec[spec_num][0] = name + " urgent";
        index_element[spec_num] ++;
    }
}

void print_all(){
    cout << "***********************" << endl;
    for(int i = 0; i < SPECIALIZATION_NUM; ++i){
        if(! index_element[i]) continue;
        cout << "There are " << index_element[i];
        cout << " Patients in specialization " << i + 1 << endl;
        for(int j = 0; j < index_element[i]; ++j)
            cout << spec[i][j] << endl;
    }
}

void get_nex(){
    int spec_num;
    cout << "Enter specialization :";
    cin >> spec_num;
    int i = 0;
    if(index_element[--spec_num]){
        cout << spec[spec_num][0].substr(0, spec[spec_num][0].find(' '));
        cout << " please go with the DR " << endl;
        for(int i = 0; i < index_element[spec_num] - 1; ++i)
            spec[spec_num][i] = spec[spec_num][i + 1];
        index_element[spec_num]--;
    }
    else
        cout << "No patients at the moment. Have rest , DR " << endl;
}

int main() {
    int choice;
    bool loop = true;
    while(loop){
        menu();
        cin >> choice;
        switch(choice){
            case 1:
            add_new();
            break;
            case 2:
            print_all();
            break;
            case 3:
            get_nex();
            break;
            case 4:
            loop = false;
            break;
            default:
            cout << "Enter a valid choice" << endl;
        }
    }
    return 0;
}

#include <iostream>
#include<list>
#include <string>
#include <iomanip>
#include<iterator>
using namespace std;

struct Employee{
    int empNum;
    string firstName;
    string lastName;
    int age;
};

void displayEmployee(list <Employee> &emps){
    if(emps.empty()){
        cout << "There is nothing in the list\n\n";
    } else {
        list<Employee> :: iterator it;
        for(it = emps.begin(); it != emps.end(); it++){
            cout << "ID: " << it->empNum << endl;
            cout << "Name: " << it->firstName << " " << it->lastName << endl;
            cout << "Age: " << it->age << endl;
            cout << endl;
        }
    }
}

Employee addEmployee(list <Employee> &emps){
    int age = 15, empID = 100;
    string first, last;
    Employee temp;

    while(empID < 101){
        cout << "\nEnter ID: ";
        cin >> empID;
        if(empID < 101){
            cout << "Try again...\n";
        }
    }

    cin.ignore();
    cout << "Enter first name: ";
    getline(cin, first);

    cout << "Enter last name: ";
    getline(cin, last);

    while(age < 16){
        cout << "Enter age: ";
        cin >> age;
        if(age < 16){
            cout << "Try again...\n";
        }
    }
    cout << endl;

    temp.age = age;
    temp.empNum = empID;
    temp.firstName = first;
    temp.lastName = last;

    return temp;
}


bool editEmployee(list<Employee> &emps, int id){
    list<Employee> :: iterator it;
    for(it = emps.begin(); it != emps.end(); it++){
        if(it->empNum == id){
            cout << "Found user. Preparing to change the data...";
            Employee temp = addEmployee(emps);
            
            it->empNum = temp.empNum;
            it->firstName = temp.firstName;
            it->lastName = temp.lastName;
            it->age = temp.age;

            return true;
        }
    }

    return false;
}


bool deleteEmployee(list<Employee> &emps, int id){
    list <Employee> :: iterator it;
    for(it = emps.begin(); it != emps.end(); ++id){
        if(it->empNum == id){
            cout << "Found user. Preparing to delete them...\n";
            emps.erase(it);
            return true;
        }
    }

    return false;
}

void countEmployee(list<Employee> &emps){
    list<Employee> :: iterator it;
    int count = 0;

    for(it = emps.begin(); it != emps.end(); ++it){
        count++;
    }

    cout << "\nThere are " << count << " employees\n\n";
}

int main(){
    list<Employee> employees;
    int choice, id;
    bool result;

    cout << "Hello, and welcome to Employee List compiler!\n\n";
    while(choice != 6){
        cout << "1. Add Emplyee \n2. Edit Employee \n3. Delete Employee \n4. Display Employees \n5. Count Employees \n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1: {
                Employee temp = addEmployee(employees);
                employees.push_back(temp);
                break;
            } case 2: {
                cout << "\nEnter the ID to edit: ";
                cin >> id;
                result = editEmployee(employees, id);
                if(!result){
                    cout << "The ID you entered does not exist in the list...\n\n";
                }
                break;
            } case 3: { 
                cout << "\nEnter the ID to delete: ";
                cin >> id;
                result = deleteEmployee(employees, id);
                if(!result){
                    cout << "The ID you entered does not exist in the list...\n\n";
                } else {
                    cout << "The employee with the specified ID has been deleted\n\n";
                }
                break;
            } case 4:{
                cout << endl;
                displayEmployee(employees);
                break;
            }case 5:{
                countEmployee(employees);
                break;
            }
        }
    }
    
    cout << "\nThanks for using me!\n";
    return 0;
}
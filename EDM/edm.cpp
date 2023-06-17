#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;
enum Department {Sales, Marketing, Finance, IT};
typedef struct Employee {
    string Name;
    int eID;
    Department department;
    union Salary {
        int package;
        float total;
    }salary;
} ep;

int main(){
    int MAX_EMPLOYEES = 100;
    ep employees[MAX_EMPLOYEES];
    int employee_no = 0;
    while(true){
        cout<<"Employee Database Management"<<endl;
        cout<<"     Select an option"<<endl;
        cout<<"     a)Add a new employee "<<endl;
        cout<<"     b)Display employee record"<<endl;
        cout<<"     c)Exit"<<endl;
        char option;
        cin>>option;
        cin.ignore();
        if(option=='a'){
        while(employee_no<MAX_EMPLOYEES){
            ep newEmployee;
            cout<<"Employee no."<<employee_no + 1<<endl;
            cout<<"Name: ";
            getline(cin, newEmployee.Name);
            cout<<"Employee ID: ";
            cin>>newEmployee.eID;
            cout << "Choose Department:" << endl;
            cout << "1) Sales" << endl;
            cout << "2) Marketing" << endl;
            cout << "3) Finance" << endl;
            cout << "4) IT" << endl;
            int Dep;
            cin>>Dep;
            cin.ignore();
            switch (Dep)
            {
            case 1:
                newEmployee.department = Sales;

                break;
            case 2:
                newEmployee.department = Marketing;
                
                break;
            case 3:
                newEmployee.department = Finance;
                
                break;
            case 4:
                newEmployee.department = IT;
                
                break;
            
            default:
                cout<<"Invalid department choice. "<<endl;
                continue;
            }
            cout<<"Set salary: "<<endl;
            int salarytype;
            cout<<"1) Monthly"<<endl;
            cout<<"2) Daily"<<endl;
            cin>>salarytype;
            cin.ignore();
            if (salarytype==1){
                cout<<"Enter Salary: ";
                cin>>newEmployee.salary.package;
            }
            else if (salarytype==2){
                cout<<"Enter Salary ";
                cin>>newEmployee.salary.total;
            
            }
            else {
                cout<<"Invlaid";
                continue;
            }


            employees[employee_no] = newEmployee;
            employee_no++;
            cout<<"Add another employee?(y/n)"<<endl;
            char yn;
            cin>>yn;
            cin.ignore();
            if (yn != 'y' && yn != 'Y'){
                break;
            }
        }
    }
    else if (option=='b'){
        cout<<"Employee details:"<<endl<<endl;
        for(int i=0; i<employee_no;i++){
            cout<<"Employee no."<<i+1<<endl;
            cout<<"Name: "<<employees[i].Name<<endl;
            cout<<"Employee ID: "<<employees[i].eID<<endl;
            cout<<"Department: "<<employees[i].department<<endl;
            cout<<"Salary: "<<employees[i].salary.total<<endl;
            cout<<endl;
        }
    }
    else if (option=='c'){
        return 0;
    }
    else{
        cout<<"Invalid option try again!"<<endl;
        return 0;;
    }
    
    }
    

    return 0;
}
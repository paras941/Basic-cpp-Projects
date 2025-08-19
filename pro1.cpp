//    Student management System 

#include <iostream>
using namespace std;

class student
{
public:
    int rollnumber;
    string name;
    int marks;

    void set() {    
    cout << "Enter Roll No: ";
        cin >> rollnumber;
        cin.ignore(); 
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display()
    {
        cout << " Name of the student :" << name << ", Rollnumber : " << rollnumber << ", Marks :  " << marks;
    }
};

int main(){
    student students[100];
    int count = 0;
    int choice;

    do
    {
        cout << "\n==== Student Record System ====\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice){
        case 1:
            students[count].set();
            count++;                                      // this case is for the addition of the marks of  the student 
            cout<<" Students successfully added ";
            break;

            case 2:                                        
            if (count==0){
                cout<<" No Record added ";
            }else{
                cout<<" Here the Details"<<endl;             // This checks the previous addition of the student 
                for( int i=0;i<count;i++){
                    students[i].display();
                    
                  }
                }
                break;
                
                  case 3:
                  if(count==0){
                    cout<<" No Record added";
                 }else{
                    int searchroll;
                    cout << " Enter the roll number";           // This case search the required rollnumber 
                    cin>>searchroll;

                    bool found ;
                    for(int i = 0; i < count; i++) {
                        if(students[i].rollnumber== searchroll) {
                            cout << "Record Found:\n";
                            students[i].display();
                            found = true;
                            break;
                        }
                        if(!found){
                            cout<<" Not found";
                            break;
                        }
                    }
                 
                 case 4:
                 cout<<" exiting program";                          // exit the program
                 break;


            }
        
        default:
        cout<<"Invalid choice";                         //Invalid  choice 
        }
    } while (choice !=4);                                // This loop run until the choice is 4 
    
    
return 0;
}
//  Calcualtor 


#include<iostream>
using namespace std;

int main (){
    char choice ;
    int num1,num2,result;
    cout<<" --Simple calculator --"<<endl;

    do
    {
        cout << "Choose operation :" << endl;
        cout << "+ for Addition" << endl;
        cout << "- for Subtraction" << endl;
        cout << "* for Multiplication" << endl;
        cout << "/ for Division" << endl;
        cout << "q to Quit" << endl;

        cout<<" Enter your choice";
        cin>> choice;

        if (choice == 'q' || choice == 'Q')
        {
            cout << " The program is Quiting ";
            break;
        }
        

        cout<< " Enter the num1 :";
        cin>>num1;
        cout<<" Enter the num2 :";
        cin>>num2;

        if( choice =='+')
        {
            result= num1+num2;
            cout<<" result of the addition is :"<< result;
            break;
        }else if( choice == '-'){
             result= num1-num2;
            cout<<" result of the substraction is :"<< result;
            break;
        }else if ( choice == '*'){
            result= num1*num2;
            cout<<" result of the Multlication is :"<< result;
            break;
        }else if ( choice == '/'){
            if (num2==0)
            {
                cout<<" Invalid choice";
            }else{
                result= num1/num2;
                cout<<" result of the division is :"<< result;
                break;
            }
        }else{
                cout<<" Invalid operator selected";
            }
            
        }
        while(true);
    


return 0;
}
#include<iostream>
using namespace std;

int main(){
    double num1, num2;
    char op;

    cout<<"Enter the operator (+ - * / ): ";
    cin>>op;

    cout<<"Enter the two number : ";
    cin>>num1>>num2;

    switch( op ){
        case '+':
            cout<<num1<< op <<num2<<"="<<num1+num2<<endl;
            break;
        case '-':
            cout<<num1<< op << num2<<"="<<num1-num2<<endl;
            break;
        case '*':
            cout<<num1<< op <<num2<<"="<<num1*num2<<endl;
            break;
        case '/':
            if(num2 == 0.0){
                cout<<"Divide by Zero Situation"<<endl;
            }
            else{
            cout<<num1<< op << num2<<"="<<num1/num2<<endl;
            }
            break;

        default:
            cout<<"Invalid operator: "<<endl;
    }
    return 0;
}
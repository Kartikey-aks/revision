#include<iostream>
using namespace std;

int main() {
    int f , s , o;
    cout<<"first no ? ";
    cin>>f;
    cout<<"second no ? ";
    cin>>s;
    cout<<"select the operation"<<endl<<"1. Addition    2. Subtraction    3. Multiplication    4. Division    5. Modulus"<<endl;
    // using goto statement - here selectoperation is a LABEL for the statement 
    // using goto statement is a bad practice as it increases code complexity . It can be removed using break and continue statements.
    // using goto statement as a loop for taking input from the user on giving wrong operation
    selectoperation : cin>>o;
    switch(o) {
        case (1) : cout<<f<<" + "<<s<<" = "<<f+s<<endl;
            break;
        case (2) : cout<<f<<" - "<<s<<" = "<<f-s<<endl;
            break;
        case (3) : cout<<f<<" * "<<s<<" = "<<f*s<<endl;
            break;
        case (4) : cout<<f<<" / "<<s<<" = "<<f/s<<endl;
            break;
        case (5) : cout<<f<<" % "<<s<<" = "<<f%s<<endl;
            break;
        default : cout<<"please select a valid operation . ";
            goto selectoperation;
    }
    return 0;
}
#include<iostream>
using namespace std;

int main() {
    char input;
    cout<<"enter anything . ";
    cin>>input;
    if(input >= 'A' && input <='Z')
        cout<<input<<" is upper case alphabet ";
    else if(input >= 'a' && input <='z')
        cout<<input<<" is lower case alphabet .";
    else if(input >= 48 && input <= 57)
        cout<<input<<" is numeric . ";
    else
        cout<<input<<" is symbol .";
    return 0;
}
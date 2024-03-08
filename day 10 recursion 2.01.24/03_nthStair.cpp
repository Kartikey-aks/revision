//count the different possible ways to climb the n'th stair with different steps
#include<iostream>
using namespace std;

int diffPossibleWaysToClimbNthStair(int stairs , int s1 , int s2) {
    // base cases
    if(stairs < 0) // NOT POSSIBLE to climb
        return 0;  // no more stairs are present
    if(stairs == 0) // POSSIBLE to climb
        return 1;   // jump and return to the same place
    return diffPossibleWaysToClimbNthStair(stairs - s1 , s1 , s2) + diffPossibleWaysToClimbNthStair(stairs - s2 , s1 , s2);
}

int main() {
    int stairs , step1 , step2;
    cout<<"please enter total stairs ";
    cin>>stairs;
    cout<<"enter step1 and step2 ";
    cin>>step1>>step2;
    cout<<"total different possible ways to climb the "<<stairs<<" stairs with steps "<<step1<<" and "<<step2<<" are = "<<diffPossibleWaysToClimbNthStair(stairs , step1 , step2);
    return 0;
}
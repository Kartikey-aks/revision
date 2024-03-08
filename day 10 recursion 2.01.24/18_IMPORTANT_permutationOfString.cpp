#include<iostream>
#include<vector>
using namespace std;

void permutationOfString(string str , int index , string combination , vector<string>& permutation) {
    //base case
    if(index >= str.length()) {
        if(combination.length() == str.length())
            permutation.push_back(combination);
        return;
    }
    //calculation
    //case 1 : excluded
    permutationOfString(str , index+1 , combination , permutation);
    //case 2 : included
    combination.push_back(str[index]);
    permutationOfString(str , index+1 , combination , permutation);
    combination.push_back(str[index-1]);
    permutation.push_back(combination);
}

int main() {
    string str;
    cout<<"please enter any string . ";
    cin>>str;
    string combination;
    vector<string> permutation;
    permutationOfString(str , 0 , combination , permutation);
    for(int i = 0 ; i < permutation.size() ; i++) {
        cout<<"{";
        for(int j = 0 ; j < permutation[i].length() ; j++)
            cout<<permutation[i][j];
        cout<<"} ";
    }
    return 0;
}
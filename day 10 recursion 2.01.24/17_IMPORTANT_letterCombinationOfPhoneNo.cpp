#include<bits/stdc++.h>
using namespace std;

void letterCombination(string n , int index , string combination , vector<string>& ans , vector<string> mapping) {
    // base case
    if(index >= n.length()) {
        //if(combination.length() > 0)
        ans.push_back(combination);
        return;
    }
    // calculation
    char a = n[index];
    for(int i = 0 ; i < mapping[a-'0'].length() ; i++) {
        //including the first alphabet of that particular no.
        combination.push_back(mapping[a-'0'][i]);
        //recursive call
        letterCombination(n , index+1 , combination , ans , mapping);
        //popping out the included alphabet
        combination.pop_back();
    }
}

int main() {
    vector<string> mapping {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
    cout<<endl<<"phone keypade be like : "<<endl;
    cout<<"1{}       ";
    for(int i = 2 ; i < 10 ; i++) {
        cout<<i<<"{"<<mapping[i]<<"}"<<"    ";
        if((i) % 3 == 0)
            cout<<endl;
    }
    cout<<"             0{}"<<endl;
    string n;
    cout<<"please enter no.'s ";
    cin>>n;
    vector<string> ans;
    string combination;
    letterCombination(n , 0 , combination , ans , mapping);
    cout<<"{ ";
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<"{";
        for(int j = 0 ; j < ans[i].length() ; j++)
            cout<<ans[i][j];
        cout<<"} ";
    }
    cout<<"}";
    return 0;
}
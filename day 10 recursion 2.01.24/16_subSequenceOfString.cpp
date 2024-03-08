#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

void Subsequence(string str , int index , string subset , vector<string>& subSequence) {
    // base case
    if(index >= str.length()) {
        if(subset.length() > 0) // non-empty string are required
            subSequence.push_back(subset);
        return;
    }
    // calculation
    // case 1: EXCUSION
    Subsequence(str , index+1 , subset , subSequence);
    // case 2: INCLUSION
    subset.push_back(str[index]);
    Subsequence(str , index+1 , subset , subSequence);
}

int main() {
    string str = "abc";
    vector<string> subSequence;
    string subset;
    Subsequence(str , 0 , subset , subSequence);
    cout<<"non-empty Subsequences of the provided string '"<<str<<"' are as follows :"<<endl;
    sort(subSequence.begin() , subSequence.end());
    for(int i = 1 ; i < subSequence.size() ; i++) {
        for(int j = 0 ; j < subSequence.size() ; j++) {
            if(subSequence[j+1].size() < subSequence[j].size())
                swap(subSequence[j+1] , subSequence[j]);
        }
    }
    cout<<"{";
    for(int i = 0 ; i < subSequence.size() ; i++) {
        cout<<"{";
        for(int j = 0 ; j < subSequence[i].size() ; j++)
            cout<<subSequence[i][j];
        cout<<"}";
    }
    cout<<"}";
    return 0;
}
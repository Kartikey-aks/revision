#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

void PowerSet(vector<int> nums , int index , vector<int> subSet , vector<vector<int>>& powerSet) {
    //base case
    if(index >= nums.size()) {
        powerSet.push_back(subSet);
        return;
    }
    //calculation
    //case 1 : EXCLUSION
    PowerSet(nums , index+1 , subSet , powerSet);
    //case 2: INCLUSION
    subSet.push_back(nums[index]);
    PowerSet(nums , index+1 , subSet , powerSet);
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> powerSet;
    vector<int> subSet;
    PowerSet(nums , 0 , subSet , powerSet);
    sort(powerSet.begin() , powerSet.end());
    for(int i = 0 ; i < powerSet.size() ; i++) {
        cout<<"{";
        for(int j = 0 ; j < powerSet[i].size() ; j++)
            cout<<powerSet[i][j];
        cout<<"}";
    }
}
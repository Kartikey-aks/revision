#include<iostream>
using namespace std;

bool AllocationPossible(int arr[] , int size , int mid , int students) {
    int PageSum = 0 , CountStudents = 1;
    for(int i = 0 ; i < size ; i++) {
        if(PageSum + arr[i] <= mid)
            PageSum += arr[i];
        else {
            CountStudents++;
            cout<<"student "<<CountStudents-1<<" alloted pages = "<<PageSum<<" "<<endl;
            if(CountStudents > students || arr[i] > mid)
                return 0;
            PageSum = arr[i];
        }
    }
    cout<<"student "<<CountStudents<<" alloted pages = "<<PageSum<<" "<<endl;
    if(CountStudents != students)
        return 0;
    else
        return 1;
}

int AllocateBooks(int arr[] , int size , int students) {
    int start = 0 , SumOfElements = 0;
    for(int i = 0 ; i < size ; i++)
        SumOfElements += arr[i];
    int end = SumOfElements , mid = start + ((end - start)/2);
    int ans = -1;
    while(start <= end) {
        if(AllocationPossible(arr , size , mid , students)) {
            ans = mid;
            cout<<"possible for "<<mid<<endl;
            end = mid - 1;
        }
        else {
            start = mid + 1;
            cout<<"not possible for "<<mid<<endl;
        }
        mid = start + ((end - start)/2);
    }
    return ans;
}

int main() {
    int arr[4] = {1 , 4 , 4};
    int students = -1;
    while(students <= 0) {
        cout<<"please enter no. of students you want ot allocate books . ";
        cin>>students;
        if(students <= 0)
            cout<<"please enter valid non-negative and non-zero students . ";
    }
    cout<<"The minimun no. of maximum page that can be allocated to a student = "<<AllocateBooks(arr , 4 , students);
}
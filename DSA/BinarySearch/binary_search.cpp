#include <iostream>
using namespace std;
#include <vector>

int binarySearch(vector<int> &arr,int target){
    int start = 0;
    int end = arr.size()-1;

    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] > target){
            end = mid -1;
        }else{
            start = mid+1;
        }
    }

    return -1;

}
int main(){
    vector<int> a1 = {3,5,6,8,10}; //odd
    int target_a1 = 10;

    vector<int> a2 = {33,52,70,89,100,120}; //odd
    int target_a2 = 33;

    cout << binarySearch(a1,target_a1);
    cout << endl;
    cout << binarySearch(a2,target_a2);

}
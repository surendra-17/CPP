#include <iostream>
#include <vector>
using namespace std;

int firstOccurance(vector<int> arr,int target){
    int size = arr.size();
    int start = 0;
    int end = size-1;
    int result = -1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid] == target){
            if(result == -1 || mid < result){
                result = mid;
            }
            end = mid-1;
        }else if(arr[mid] > target){
            end = mid -1;
        }else{
            start = mid+1;
        }
    }
    return result;
}

int lastOccurance(vector<int> arr,int target){
    int size = arr.size();
    int start = 0;
    int end = size-1;
    int result = -1;
    while(start <= end){
        int mid = start + (end-start)/2;
        cout << "start: "<<start<<" end: "<<end<<" mid:"<<mid<<endl;
        if(arr[mid] == target){
            if(result == -1 || mid > result){
                result = mid;
            }
            start = mid+1;
        }else if(arr[mid] > target){
            end = mid -1;
        }else{
            start = mid+1;
        }
    }
    return result;
}

int main(){
    vector<int> sample = {1,2,3,4,5,5,5,5,5};
    int target = 5;
    int first = firstOccurance(sample, target);
    int last =  lastOccurance(sample, target);
    cout << "first and last index of " << target << " is " << endl;
    cout << first << ", " << last;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
vector<int> getFirstLastIndex(vector<int> &arr,int target){
    int size = arr.size()-1;
    int first_index = -1;
    int last_index = -1;
    int start = 0;
    int end = size;
    int mid = start + (end-start)/2;
    while(start<=end){
        if(arr[mid] == target){
            if(first_index == -1 || first_index > mid){
                first_index = mid;
            }
            if(last_index == -1 || last_index < mid){
                last_index = mid;
            }
            int prefix_start = 0;
            int prefix_end = mid-1;
            int prefix_mid = prefix_start + (prefix_end-prefix_start)/2;
            int suffix_start = prefix_mid+1;
            int suffix_end = end;
            int suffix_mid = suffix_start + (suffix_end-suffix_start)/2;
            while (prefix_start<=prefix_end)
            {
                if(arr[prefix_mid] == target){
                    if(first_index == -1 || first_index > prefix_mid){
                        first_index = prefix_mid;
                    }
                    prefix_end = prefix_mid -1;
                }else if(arr[prefix_mid] > target){
                    prefix_end = prefix_mid -1;                    
                }else{
                    prefix_start = prefix_mid+1;
                }
                prefix_mid = prefix_start + (prefix_end-prefix_start)/2;
            }

            while (suffix_start<=suffix_end)
            {
                if(arr[suffix_mid] == target){
                    if(last_index == -1 || last_index < suffix_mid){
                        last_index = suffix_mid;
                    }
                    suffix_start = suffix_mid + 1;
                }
                if(arr[suffix_mid-1] >= target){
                    suffix_end = suffix_mid -1;
                }else{
                    suffix_start = suffix_mid+1;
                }
                suffix_mid = suffix_start + (suffix_end-suffix_start)/2;
            }
            if(arr[mid] > target){
            end = mid -1;
            }else{
                start = mid+1;
            }   
        }else if(arr[mid] > target){
            end = mid -1;
        }else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return {first_index,last_index};
}
int main(){
    vector<int> sample = {1,2,3,4,5,5,5,5,5};
    int target = 5;
    vector<int> result = getFirstLastIndex(sample,target);
    cout << "first and last index of " << target << " is " << endl;
    cout << result[0] << " " << result[1];
    return 0;
}
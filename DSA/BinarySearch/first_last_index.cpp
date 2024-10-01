#include <iostream>
#include <vector>
using namespace std;


vector<int> getFirstLastIndex(vector<int> arr,int target){
    int size = arr.size()-1;
    int first_index = -1;
    int last_index = -1;
   for (int i = 0; i <= size; i++ ){
        if(i> size-i){
            break;
        }
        if(arr[i] == target){
            if(first_index == -1 || first_index > i){
                first_index = i;
            }
            if(last_index == -1 || last_index < i){
                last_index = i;
            }
        }
        
        if(arr[size - i] == target){
            if(first_index == -1 || first_index > (size - i)){
                first_index = size - i;
            }
            if(last_index == -1 || last_index < (size - i)){
                last_index = size - i;
            }
        }
   }

   return {first_index,last_index};

}


int main(){
    vector<int> sample = {3,4,3,5,6,4,9};
    int target = 4;
    vector<int> result = getFirstLastIndex(sample,target);
    cout << "first and last index of " << target << " is " << endl;
    cout << result[0] << " " << result[1];
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;


vector<int> getFirstLastIndex(vector<int> arr,int target){
    int size = arr.size()-1;
    int first_index = -1;
    int last_index = -1;
   for (int i = 0; i <= size; i++ ){
        if(arr[i] == target){
            if(first_index == -1){
                first_index = i;
            }
            if(i > last_index){
                last_index = i;
            }
        }
   }

   return {first_index,last_index};

}


int main(){
    vector<int> sample = {8,4,3,5,6,4,9};
    int target = 8;
    vector<int> result = getFirstLastIndex(sample,target);
    cout << "first and last index of " << target << " is " << endl;
    cout << result[0] << " " << result[1];
    return 0;
}
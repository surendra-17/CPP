#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> arr,int target){
    int size = arr.size();
    cout << "size:" << size << endl;
    //handle edge cases
    if(size == 0) return -1;
    if(arr.back() == target) return size-1;

    for (int i = 0; i < size; i++)
    {
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
    
}

vector<int> linearSearchWithAllOccurances(vector<int> vec,int target){
     int size = vec.size();
    cout << "vec size:" << size << endl;
    vector<int> finalVec;
    for (int i = 0; i < vec.size(); i++)
    {
        if(vec[i] == target){
            finalVec.push_back(i);
        }
    }
    if(finalVec.empty()){
        finalVec.push_back(-1);
    }
    cout << "finalvec:" << finalVec.size()<<endl;
    return finalVec;

}

int main(){
    //linear search with single element
    vector<int> vec = {1,2,3,4,5};
    vector<int> emptyArray ={};
    int target = 4;
    cout << "Element Found At Index: " << linearSearch(vec,target) << endl;
    cout << "Empty Array: " << linearSearch(emptyArray,target);

    cout << endl;
    //linear serach with all ocurance of target using vector
    vector<int> allOccuranceVec = {1,2,3,4,5,3};
    int targetInVec = 3;
    vector<int> result = linearSearchWithAllOccurances(allOccuranceVec,targetInVec);
    for (int i : result)
    {
        cout << "Element "<< targetInVec << " Found At Index: " << i << endl;
        
    }

    return 0;
    
}
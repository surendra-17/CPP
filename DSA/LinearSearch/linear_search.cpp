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

vector<int> linearSearchWithAllOccurrences(vector<int> vec,int target){
    int size = vec.size();
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

int findLastOccurrence(vector<int> vec,int target){
    int lastOccurance = -1;
    for (int i = 0; i < vec.size(); i++)
    {
        if(vec[i] == target){
           lastOccurance = i;
        }
    }
    return lastOccurance;
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
    vector<int> result = linearSearchWithAllOccurrences(allOccuranceVec,targetInVec);
    for (int i : result)
    {
        cout << "Element "<< targetInVec << " Found At Index: " << i << endl;
        
    }

    //find last occurance
    vector<int> lastOccurrenceArr = {1, 2, 3, 4, 2, 5, 2};
    int targetLastOccurrence = 2;

    int index = findLastOccurrence(lastOccurrenceArr, targetLastOccurrence);
    
    if (index != -1) {
        std::cout << "Last occurrence of " << targetLastOccurrence << " is at index: " << index << std::endl;
    } else {
        std::cout << targetLastOccurrence << " not found in the array." << std::endl;
    }

    return 0;
    
}
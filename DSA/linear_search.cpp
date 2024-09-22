#include <iostream>
using namespace std;

int linearSearch(int array[],int target){

    for (int i = 0; i < sizeof(array[0]); i++)
    {
        if(array[i] == target){
            return i;
        }
    }
    return -1;
    
}

int main(){
    int array[] = {1,2,3,4,5};
    int target = 4;
    cout << "Element Found At Index: " << linearSearch(array,target);
}
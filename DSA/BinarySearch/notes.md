# Intuition
The intuition behind binary search is based on the idea of divide and conquer. If we have a sorted array, we can leverage the ordering of the elements to efficiently narrow down the search space. Instead of checking each element sequentially, we can repeatedly split the array in half, which significantly reduces the number of comparisons needed.

# Approach
1. Initialization: Start with two pointers, left at the beginning of the array and right at the end.
1. Iteration: While start is less than or equal to end:
    - Calculate the middle index: mid = start + (end - start)/2.
    - Compare the target value with the middle element:
    - If the middle element equals the target, return the index.
    - If the target is less than the middle element, adjust end to mid - 1.
    - If the target is greater than the middle element, adjust start to mid + 1.
1. Termination: If the loop exits without finding the target, return an indication (e.g., -1) that the target is not in the array.

# Complexity
- **Time complexity:**
The time complexity of binary search is O(logn) because the search space is halved with each iteration.

- **Space complexity:** 
The space complexity is O(1) for the iterative version, as it uses a constant amount of space for pointers. If implemented recursively, the space complexity would be O(logn) due to the call stack.

# Code
```cpp []
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;

        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                end = mid -1;
            }else{
                start = mid+1;
            }
        }

        return -1;
    }
};
```
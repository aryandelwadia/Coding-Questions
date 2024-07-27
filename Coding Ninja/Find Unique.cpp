//Link
//https://www.naukri.com/code360/problems/find-unique_625159

#include<map>

int findUnique(int *arr, int size)
{
    //Write your code here
    std::map<int, int> nums;

    for(int i = 0; i < size; i++) {
        nums[arr[i]]++;
    }
    
    for(int i = 0; i < size; i++) {
        if(nums[arr[i]] == 1) {
            return arr[i];
        }
    }
    
    return -1;

}
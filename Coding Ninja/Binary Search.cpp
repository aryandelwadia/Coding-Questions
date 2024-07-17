//LINK
//https://www.naukri.com/code360/problems/binary-search_972

int search(vector<int> &nums, int target) {
    // Write your code here.
    int s = 0;
    int e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    
    while(s <= e){
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}
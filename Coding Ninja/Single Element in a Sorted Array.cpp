//Link
//https://www.naukri.com/code360/problems/unique-element-in-sorted-array_1112654

int singleNonDuplicate(vector<int> &arr) {
  // Write your code here
  	int n = arr.size();

	int uniqueNumber = 0;
    for(int num : arr) {
        uniqueNumber ^= num;
    }
    return uniqueNumber;
  
}
        
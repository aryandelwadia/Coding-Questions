//link
//https://www.geeksforgeeks.org/problems/decode-the-pattern1138/1

class Solution {
  public:
    string countAndSay(int n) {
        // code here
        if(n == 1){
            return "1";
        }
        if(n == 2){
            return "11";
        }
        
        string result = countAndSay(n - 1);
        
        string newStr = "";
        int count = 1;
        for(int i = 1; i < result.size(); i++){
            if(result[i - 1] != result[i]){
                newStr.push_back('0' + count);
                newStr.push_back(result[i - 1]);
                count = 1;
            }
            else{
                count++;
            }
            if(i == result.size() - 1){
                newStr.push_back('0' + count);
                newStr.push_back(result[i]);
            }
        }
        
        return newStr;
    }
};

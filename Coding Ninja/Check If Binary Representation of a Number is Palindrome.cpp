//Link
//https://www.naukri.com/code360/problems/check-palindrome_920555

#include <bits/stdc++.h> 

string binary(long long N){
	string num = "";
    while(N > 0){
        num += to_string(N % 2);
        N = N / 2;
    }
    reverse(num.begin(), num.end());
    
	return num;
}

bool palindrome(string num, int i, int j){
	if(i > j){
		return true;
	}
	if (num[i] != num[j]){
		return false;
	}
	else{
		return palindrome(num, i + 1, j - 1);
	}

}

bool checkPalindrome(long long N)
{
	// Write your code here.
	string num = binary(N);
	bool ans = palindrome(num, 0, num.length() - 1);
	return ans;
}
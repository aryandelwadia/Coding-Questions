//Link
//https://www.naukri.com/code360/problems/reverse-the-string_799927

#include <bits/stdc++.h> 

void reverse(string& str, int f, int l){
	if (f > l){
		return ;
	}

	swap(str[f], str[l]);
	f++;
	l--;

	reverse(str, f, l);
}

string reverseString(string str)
{
	// Write your code here.
	int n = str.length() - 1;
	reverse(str, 0, n);
	return str;
}
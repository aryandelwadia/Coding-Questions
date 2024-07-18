//Link
//https://www.naukri.com/code360/problems/subsequences-of-string_985087

#include <bits/stdc++.h> 

void solve(string str, vector<string>& ans, string pair, int i){
	if (i >= str.length()){
		ans.push_back(pair);
		return;
	}

	solve(str, ans, pair, i + 1);

	pair.push_back(str[i]);
	solve(str, ans, pair, i + 1);
}

vector<string> subsequences(string str){
	
	// Write your code here
	vector<string> ans;
	string pair = "";
	int i = 0;
	solve(str, ans, pair, i);
	sort(ans.begin(), ans.end());
	ans.erase(ans.begin());
	return ans;
}

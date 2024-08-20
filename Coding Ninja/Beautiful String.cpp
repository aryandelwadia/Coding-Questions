//link
//https://www.naukri.com/code360/problems/beautiful-string_1115625

int makeBeautiful(string str) {
	// Write your code here
	int count1 = 0;
	int count2 = 0;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '0' && i % 2 != 0){
			count1++;
		}
		if(str[i] == '1' && i % 2 == 0){
			count1++;
		}
	}

	for(int i = 0; i < str.length(); i++){
		if(str[i] == '0' && i % 2 == 0){
			count2++;
		}
		if(str[i] == '1' && i % 2 != 0){
			count2++;
		}
	}

	return min(count1, count2);
}
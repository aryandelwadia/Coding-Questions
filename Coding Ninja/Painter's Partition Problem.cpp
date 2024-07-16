//Link
//https://www.naukri.com/code360/problems/painter's-partition-problem_1089557

bool isPossible(vector<int> &boards, int k, int n, int mid){
    int painters = 1;
    int length = 0;
    for (int i = 0; i < n; i++){
        if (length + boards[i] <= mid){
            length += boards[i];
        }
        else{
            painters++;
            if(painters > k || boards[i] > mid){
                return false;
            }
            length = boards[i];
        }
    }

    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int s = 0;
    int e = 0;
    int n = boards.size();
    int ans = 0;

    for (int i = 0; i < n; i++){
        e += boards[i];
    }

    int mid = s + (e - s) / 2;

    while (s <= e){
        if (isPossible(boards, k, n, mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

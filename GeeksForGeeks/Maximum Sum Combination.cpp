//link
//https://www.geeksforgeeks.org/problems/maximum-sum-combination/1

class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        
        priority_queue<tuple<int, int, int>> maxHeap;
        set<pair<int, int>> seen;
        vector<int> result;

        maxHeap.push(make_tuple(a[0] + b[0], 0, 0));

        seen.insert({0, 0});

        while (k-- && !maxHeap.empty()) {
            tuple<int, int, int> top = maxHeap.top();
            int sum = get<0>(top);
            int i = get<1>(top);
            int j = get<2>(top);
            maxHeap.pop();
            result.push_back(sum);

            if (i + 1 < n && !seen.count({i + 1, j})) {
                maxHeap.push(make_tuple(a[i + 1] + b[j], i + 1, j));
                seen.insert({i + 1, j});
            }

            if (j + 1 < n && !seen.count({i, j + 1})) {
                maxHeap.push(make_tuple(a[i] + b[j + 1], i, j + 1));
                seen.insert({i, j + 1});
            }
        }

        return result;
    }
};

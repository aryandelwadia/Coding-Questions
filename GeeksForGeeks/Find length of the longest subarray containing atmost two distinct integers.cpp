// link
// https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

class Solution
{
public:
    int totalElements(vector<int> &arr)
    {
        // code here
        int l = 0, r = 0, ans = 0;
        unordered_map<int, int> m;

        while (r < arr.size())
        {
            m[arr[r]]++;
            if (m.size() > 2)
            {
                while (m.size() > 2)
                {
                    m[arr[l]]--;
                    if (m[arr[l]] == 0)
                    {
                        m.erase(arr[l]);
                    }
                    l++;
                }
            }

            int len = r - l + 1;
            ans = max(ans, len);
            r++;
        }

        return ans;
    }
};
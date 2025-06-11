// link
// https://www.geeksforgeeks.org/problems/remove-the-balls--170647/1

class Solution
{
public:
    int findLength(vector<int> &color, vector<int> &radius)
    {
        stack<pair<int, int>> st;

        for (int i = 0; i < color.size(); ++i)
        {
            pair<int, int> curr = {color[i], radius[i]};
            if (!st.empty() && st.top() == curr)
            {
                st.pop();
            }
            else
            {
                st.push(curr);
            }
        }

        return st.size();
    }
};

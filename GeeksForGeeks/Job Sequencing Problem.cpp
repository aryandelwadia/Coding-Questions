//link
//https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

class Solution {
    public:
        vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
            int n = deadline.size();
            vector<pair<int, int>> jobs(n);
    
            int maxDays = 0;
            for (int i = 0; i < n; i++) {
                jobs[i] = {profit[i], deadline[i]};
                maxDays = max(maxDays, deadline[i]);
            }
    
            sort(jobs.rbegin(), jobs.rend());
    
            vector<int> parent(maxDays + 1);
            for (int i = 0; i <= maxDays; i++) parent[i] = i; 
            function<int(int)> find = [&](int day) {
                if (parent[day] == day) return day;
                return parent[day] = find(parent[day]);
            };
    
            int jobCount = 0, maxProfit = 0;
    
            for (auto& job : jobs) {
                int p = job.first, d = job.second;
    
                int availableDay = find(d);
                if (availableDay > 0) {
                    parent[availableDay] = find(availableDay - 1); 
                    jobCount++;
                    maxProfit += p;
                }
            }
    
            return {jobCount, maxProfit};
        }
    };
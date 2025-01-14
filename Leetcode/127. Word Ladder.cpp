//link
//https://leetcode.com/problems/word-ladder

class Solution {
private:
    bool compare(string s1, string s2) {
        int count = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                count++;
            }
        }

        if (count == 1) {
            return true;
        }
        return false;
    }

public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        bool check = false;
        for (int i = 0; i < wordList.size(); i++) {
            if (endWord == wordList[i]) {
                check = true;
            }
        }

        if (!check) {
            return 0;
        }

        unordered_map<string, list<string>> adj;
        for (int i = 0; i < wordList.size(); i++) {
            if (compare(beginWord, wordList[i])) {
                adj[beginWord].push_back(wordList[i]);
            }
        }
        for (int i = 0; i < wordList.size() - 1; i++) {
            for (int j = i; j < wordList.size(); j++) {
                if (compare(wordList[i], wordList[j])) {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        int ans = 0;
        unordered_map<string, bool> visited;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        visited[beginWord] = true;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            string str = front.first;
            int move = front.second;

            if (str == endWord) {
                return move;
            }

            for (auto& neighbor : adj[str]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, move + 1});
                }
            }
        }

        return ans;
    }
};
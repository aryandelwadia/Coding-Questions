//link
//https://leetcode.com/problems/longest-common-prefix?envType=problem-list-v2&envId=trie

class TrieNode{
    public:
    char data;
    int childCount;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        childCount = 0;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(char ch){
        root = new TrieNode(ch);
    }

    void insertRec(TrieNode* root, string word){
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root -> childCount++;
            root -> children[index] = child;
        }

        insertRec(child, word.substr(1));
    }

    void insert(string word){
        insertRec(root, word);
    }

    void lcp(string first, string &ans){
        TrieNode* curr = root;
        while(curr && curr -> childCount == 1 && !curr -> isTerminal){
            for(int i = 0; i < 26; i++){
                if(curr -> children[i]){
                    ans.push_back(curr -> children[i] -> data);
                    curr = curr -> children[i];
                    break;
                }
            }
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* t = new Trie('\0');
        for(int i = 0; i < strs.size(); i++){
            t -> insert(strs[i]);
        }

        string first = strs[0];
        string ans = "";

        t -> lcp(first, ans);
        return ans;
    }
};
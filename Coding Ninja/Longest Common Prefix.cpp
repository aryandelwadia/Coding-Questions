//link
//https://www.naukri.com/code360/problems/longest-common-prefix_2090383

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

    /** Initialize your data structure here. */

    Trie(char ch){
        root = new TrieNode(ch);
    }

    /** Inserts a word into the trie. */
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

    void insert(string word) {
        insertRec(root, word);
    }

    void lcp(string first, string &ans){
        TrieNode* curr = root;
        while (curr && curr->childCount == 1 && !curr->isTerminal) {
            for (int i = 0; i < 26; i++) {
                if (curr->children[i]) {
                    ans.push_back(curr->children[i]->data);
                    curr = curr->children[i];
                    break; // Move to the next character
                }
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    Trie* t = new Trie('\0');
    for(int i = 0; i < n; i++){
        t -> insert(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t -> lcp(first, ans);
    return ans;
}



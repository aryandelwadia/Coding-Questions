//link
//https://www.naukri.com/code360/problems/implement-trie_631356

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class TrieNode{
    public:

    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++){
            children[i] = 0;
        }
        isTerminal = false;
    }
};

class Trie {

public:

    TrieNode* root;

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
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
            root -> children[index] = child;
        }

        insertRec(child, word.substr(1));
    }

    void insert(string word) {
        insertRec(root, word);
    }

    /** Returns if the word is in the trie. */
    bool searchRec(TrieNode* root, string word){
        if(word.length() == 0){
            return root -> isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root -> children[index] != NULL){
            child = root -> children[index];
        }else{
            return false;
        }

        return searchRec(child, word.substr(1));
    }

    bool search(string word) {
        return searchRec(root, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool searchPrefixRec(TrieNode* root, string word){
        if(word.length() == 0){
            return true;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root -> children[index] != NULL){
            child = root -> children[index];
        }else{
            return false;
        }

        return searchPrefixRec(child, word.substr(1));
    }

    bool startsWith(string prefix) {
        return searchPrefixRec(root, prefix);
    }
};
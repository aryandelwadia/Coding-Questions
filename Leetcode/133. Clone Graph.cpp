//link
//https://leetcode.com/problems/clone-graph?envType=problem-list-v2&envId=graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }

        unordered_map<Node*, Node*> copy;
        Node* ans = new Node(node -> val, {});
        copy[node] = ans;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* front = q.front();
            q.pop();

            for(auto i: front -> neighbors){
                if(copy.find(i) == copy.end()){
                    copy[i] = new Node(i -> val, {});
                    q.push(i);
                }
                copy[front] -> neighbors.push_back(copy[i]);
            }
        }

        return ans;
    }
};
//link
//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/?envType=problem-list-v2&envId=binary-tree

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return NULL;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            Node* prev = NULL;

            for(int i = 0; i < size; i++){
                Node* frontNode = q.front();
                q.pop();

                if(prev){
                    prev -> next = frontNode;
                }
                prev = frontNode;

                if(frontNode -> left){
                    q.push(frontNode -> left);
                }
                if(frontNode -> right){
                    q.push(frontNode -> right);
                }
            }

            prev -> next = NULL;
        }

        return root;
    }
};
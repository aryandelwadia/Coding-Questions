//Link
//https://www.naukri.com/code360/problems/delete-node-in-ll_5881

/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *deleteNode(Node *head, int pos)
{
    // Write your code here.

	if(head == NULL){
		return NULL;
	}

	if(pos == 0){
		return head -> next;
	}

	Node* temp = head;
	Node* prev = NULL;

	for(int i = 0; i < pos; i++){
		if(temp == NULL){
			return head;
		}
		prev = temp;
		temp = temp -> next;
	}

	if (temp == NULL) return head;

	prev -> next = temp -> next;
	return head;
}

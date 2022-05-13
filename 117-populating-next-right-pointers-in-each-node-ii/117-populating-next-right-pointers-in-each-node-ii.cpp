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
void levelOrder(Node* root)
{
    queue<Node*>q;
    q.push(root);
    Node* p=NULL;
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* t=q.front();
            q.pop();
            if(i==0)
            {
                p=t;
                p->next=NULL; 
            }
            else
            {
                p->next=t;
                p=t;
                p->next=NULL;
            }
            
            if(t->left!=NULL)
                q.push(t->left);
            if(t->right!=NULL)
                q.push(t->right);
        }
    }
}
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        levelOrder(root);
        return root;
    }
};
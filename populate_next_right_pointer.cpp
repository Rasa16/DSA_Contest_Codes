//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

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
        if(root == NULL)
            return NULL;
        vector<vector<Node*>> res;
        vector<Node*> t;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node* p = q.front();
                q.pop();
                t.push_back(p);
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            res.push_back(t);
            t.clear();
        }
        for(auto v : res){
            for(int i = 0; i<v.size(); i++){
                if(i == v.size()-1)
                    v[i]->next = NULL;
                else{
                    v[i]->next = v[i+1];
                }
            }
        }
        return root;
    }
};

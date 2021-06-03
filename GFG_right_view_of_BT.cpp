class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<vector<int>> level(Node* p){
        if(p == nullptr)
            return {};
        queue<Node*> q;
        vector<vector<int>> res;
        q.push(p);
        Node* t;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            while(size--){
                t = q.front();
                q.pop();
                
                v.push_back(t->data);
                
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            res.push_back(v);
        }
        return res;
    }
    vector<int> rightView(Node *root)
    {
       // Your code here
       vector<vector<int>> v = level(root);
       vector<int> res;
       for(auto i:v){
           res.push_back(i[i.size()-1]);
       }
       return res;
    }
};
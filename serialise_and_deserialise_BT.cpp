//https://leetcode.com/problems/serialize-and-deserialize-bst/submissions/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr){
            return "";
        }
        string lans=serialize(root->left);
        string rans=serialize(root->right);
        return to_string(root->val)+","+lans+rans;
    }

    // Decodes your encoded data to tree.
    TreeNode* helper(TreeNode* root,int val){
        if(root==nullptr){
            TreeNode* root=new TreeNode(val);
            return root;
        }
        else{
            if(root->val>val){
                root->left=helper(root->left,val);
            }
            else if(root->val<val){
                root->right=helper(root->right,val);
            }
        }
        return root;
    }
       
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=nullptr;
        for(int i=0;i<preorder.size();i++){
            root=helper(root,preorder[i]);
        }
        return root;
    }
    
    TreeNode* deserialize(string data) {
        int num=data.length();
        if(num == 0)
            return NULL;
        vector<int> preorder;
        string t = "";
        int i = 0, j = 1;
        while(j < num){
            while(data[j] != ','){
                j++;
            }
            t = data.substr(i, j-i);
            int n = stoi(t);
            
            preorder.push_back(n);
            j++;
            i = j;
        }
        
        return bstFromPreorder(preorder);
    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void fun(vector<vector<int>>& res, TreeNode* root, int level){

        if(root==nullptr)
            return;

        if(res.size()==level)
            res.push_back({});

        res[level].push_back(root->val);

        // call left child
        fun(res, root->left, level+1);
        // call right child
        fun(res, root->right, level+1);

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 0;
        vector<vector<int> > res;
        fun(res, root, level);

        return res;
    }
};

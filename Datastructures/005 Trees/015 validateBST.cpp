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
    bool isValidBST(TreeNode* root) {

        TreeNode* prev = nullptr;
        TreeNode* temp = root;
        stack<TreeNode*> stk;

        while(!(stk.empty() && temp==nullptr)){

            if(temp!=nullptr){
                stk.push(temp);
                temp = temp->left;
            }else{

                temp = stk.top(); stk.pop();

                // // visit curr
                // if(prev==nullptr){
                //     prev = temp;
                //     temp = temp->right;
                //     continue;
                // }

                if( prev!=nullptr && temp->val<=prev->val)
                    return false;
                prev = temp;
                temp = temp->right;
            }

        }

        return true;
    }
};

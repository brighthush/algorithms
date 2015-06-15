/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if(n<=0) {
            ans.push_back(NULL);
            return ans;
        }
        ans = genTrees(1, n);
        return ans;
    }

    TreeNode *copyTree(TreeNode *root) {
        if(root == NULL) return NULL;
        TreeNode *cur = new TreeNode(root->val);
        cur->left = copyTree(root->left);
        cur->right = copyTree(root->right);
        return cur;
    }

    vector<TreeNode*> genTrees(int left, int right) {
        vector<TreeNode*> ans;
        if(left > right) {
            ans.push_back(NULL);
            return ans;
        }
        if(left == right) {
            TreeNode *cur = new TreeNode(left);
            ans.push_back(cur);
            return ans;
        }
        for(int i=left; i<=right; ++i) {
            vector<TreeNode*> leftTrees = genTrees(left, i-1);
            vector<TreeNode*> rightTrees = genTrees(i+1, right);
            int n1 = leftTrees.size();
            int n2 = rightTrees.size();
            for(int i1=0; i1<n1; ++i1) {
                for(int i2=0; i2<n2; ++i2) {
                    TreeNode *cur = new TreeNode(i);
                    cur->left = copyTree(leftTrees[i1]);
                    cur->right = copyTree(rightTrees[i2]);
                    ans.push_back(cur);
                }
            }
        }
        return ans;
    }
};

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)  return ans;
        queue<TreeNode *>q;
        q.push(root);
        while(q.size()!=0)
        {
            vector<int> level;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left)   q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(level);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

/* ntuition
Normal level order = top → bottom
This question = bottom → top
👉 So instead of complicating traversal:
Just do normal BFS and reverse at the end.
Because BFS naturally processes nodes level by level

Approach
-Use queue (BFS) for level order
-For each level:
Process all nodes
Store values in a vector
-Push level into result
-After traversal → reverse answer
👉 This is optimal and simplest approach
🔥 Key Insight
Do NOT overthink — just reverse the final result

Complexity
Time complexity:O(N)
(each node visited once)
Space complexity:O(N)
(queue + result storage)

*/
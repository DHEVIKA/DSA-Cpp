/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool traversal(TreeNode* p, TreeNode* q) {

        // If both nodes are NULL
        if (p == NULL && q == NULL)
            return true;

        // If one node is NULL
        if (p == NULL || q == NULL)
            return false;

        // Compare left subtree
        bool lft = traversal(p->left, q->left);
        if (lft == false)
            return false;

        // Compare right subtree
        bool rgt = traversal(p->right, q->right);
        if (rgt == false)
            return false;

        // Compare current node values
        return p->val == q->val;
        //return p->val == q->val && lft && rgt ;

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traversal(p, q);
    }
};


/* Intuition
To determine whether two binary trees are identical, we need to compare:

The value of each corresponding node.
The structure of both trees.
A recursive solution works naturally because each subtree can be checked independently.

Approach
We recursively traverse both trees at the same time.

Steps:
If both nodes are NULL, they are identical at this position.

If one node is NULL and the other is not, the trees are different.

Recursively compare:

left subtrees
right subtrees
Finally, compare the current node values.

If all conditions match, the trees are the same.

Complexity
Time complexity:
[
O(N)
]
where N is the number of nodes, since every node is visited once.

Space complexity:
[
O(H)
]
where H is the height of the tree due to recursive stack space.

Worst case: O(N) for a skewed tree

Best case: O(log N) for a balanced tree

*/
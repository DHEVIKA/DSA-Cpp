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
    bool isTreeSymmetric(TreeNode* leftRoot, TreeNode* rightRoot){
        if(leftRoot == nullptr && rightRoot == nullptr)
            return true;
        if((leftRoot == nullptr && rightRoot != nullptr)  || (leftRoot != nullptr && rightRoot == nullptr))
            return false;
        if(leftRoot -> val != rightRoot -> val)
            return false;
        return isTreeSymmetric(leftRoot -> left, rightRoot -> right) && isTreeSymmetric(leftRoot -> right, rightRoot -> left);
    }
    bool isSymmetric(TreeNode* root) {
        return isTreeSymmetric(root -> left, root -> right);
    }
};

/* Approach
Define a function "isTreeSymmetric" that takes in two TreeNode pointers as inputs, "leftRoot" and "rightRoot"
If both "leftRoot" and "rightRoot" are null, return true
If only one of "leftRoot" or "rightRoot" is null, return false
If "leftRoot" and "rightRoot" are not null and their values are not equal, return false
If "leftRoot" and "rightRoot" are not null and their values are equal, recursively call "isTreeSymmetric" on the left child of "leftRoot" and the right child of "rightRoot", and the right child of "leftRoot" and the left child of "rightRoot"
Return true if both recursive calls return true, else return false
Define a function "isSymmetric" that takes in a TreeNode pointer "root" as input
Call "isTreeSymmetric" on the left child of "root" and the right child of "root" and return the result*/
/*

 Cousins in Binary Tree

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.

*/

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

//URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/


class Solution {
  int xdepth=-1;
  int ydepth=-2;
public:

  
  void depth(TreeNode* root, int x,int y, int l) {
    if(root == NULL)  return;
      
    if(root->val == x) {
      xdepth = l; 
      return ;
    }
    if(root->val ==y) {
      ydepth =l;
      return;
    }
    
      depth(root->left, x,y, l+1);
      depth(root->right,x ,y,l+1);

    
    
  }
  
  
  int isSibling(int x, int y,TreeNode* root) {
    if(root==NULL) return 0;
    
    if(root->left != NULL && root->right !=NULL) {
      if(root->left->val==x && root->right->val==y) return 1;
      else if(root->left->val==y && root->right->val==x) return 1;
    }
    return(isSibling(x,y,root->left) || isSibling(x,y,root->right));
  }


bool isCousins(TreeNode* root, int x, int y) {
      int sib=isSibling(x,y,root);
      //cout<<sib<<endl;
      depth(root, x,y, 0);
     
  
      if(xdepth==ydepth && sib==0) {
        return true;
      }

      return false;
      
    }
};
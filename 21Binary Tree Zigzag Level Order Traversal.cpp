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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return vector<vector<int>>();
           
        queue <TreeNode*> q;
        TreeNode* cur;
        vector<int>level;vector<vector<int>>ans;
        int levelCount=0;
        
        q.push(root);
        levelCount++;
        int count=0;
        while(!q.empty()){
            cur=q.front();
            q.pop();
            levelCount--;
            
            level.push_back(cur->val);
            
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
            
            if(levelCount==0){
                count++;
                if(count%2==0)
                    reverse(level.begin(),level.end());
                    
                ans.push_back(level);
                
                level=vector<int>();
                
                levelCount=q.size();
            }
            
        }
        //reverse(ans.begin(),ans.end());
        return ans;
    }
};
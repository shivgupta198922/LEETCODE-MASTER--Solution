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
    void solve(TreeNode* root) {
        if(!root) return;

        // Queue to store pairs of (level, (TreeNode pointer, sibling sum))
        queue<pair<int,pair<TreeNode*, int>>> q, cpy;
        // Vector to store sum of sibling values at each level
        vector<int> levelSum;
        int level = 0;
        levelSum.push_back(root->val); // Start by adding the root's value to the level sum
        q.push({level, {root, root->val}});
        cpy.push({level, {root, root->val}});

        while(!q.empty()) {
            int n = q.size();
            int lvlSum = 0; // Sum of sibling values at the current level

            while(n--) {
                TreeNode* node = q.front().second.first;
                q.pop();
                int sibSum = 0;
                // Add values of left and right children to the sibling sum, if they exist
                if(node->left) sibSum += node->left->val;
                if(node->right) sibSum += node->right->val;

                // Push the left child to the queue, along with the sibling sum and updated level
                if(node->left) {
                    q.push({level + 1, {node->left, sibSum}});
                    cpy.push({level + 1, {node->left, sibSum}});
                }

                // Push the right child to the queue, along with the sibling sum and updated level
                if(node->right) {
                    q.push({level + 1, {node->right, sibSum}});
                    cpy.push({level + 1, {node->right, sibSum}});
                }

                lvlSum += sibSum;
            }

            // Store the total sum of sibling values for this level
            levelSum.push_back(lvlSum);
            ++level;
        }

        // Now update each node's value using the values in cpy queue and levelSum vector
        while(!cpy.empty()) {
            int lvl = cpy.front().first; // Get the level of the current node
            int sibSum = cpy.front().second.second; // Get the sibling sum
            TreeNode* node = cpy.front().second.first; // Get the current node
            cpy.pop();

            // Update the node's value to be the total sum at that level minus the sibling sum
            node->val = levelSum[lvl] - sibSum;
        }
    }

public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        solve(root);
        return root;
    }
};
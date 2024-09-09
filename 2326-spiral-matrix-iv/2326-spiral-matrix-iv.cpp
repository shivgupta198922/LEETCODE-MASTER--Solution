/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    static vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        const int layer=min((m+1)/2, (n+1)/2);
        ListNode* curr=head;
        for(int k=0; k<layer; k++){
            for(int j=k; j<n-k; j++, curr=curr->next){//right
                if (curr) ans[k][j]=curr->val;
                else break;
            }
            for(int i=k+1; i<m-k; i++, curr=curr->next){//down
                if (curr) ans[i][n-1-k]=curr->val;
                else break;
            }
            for(int j=n-k-2; j>k; j--, curr=curr->next){//left
                if (curr) ans[m-k-1][j]=curr->val;
                else break;
            }
            for(int i=m-1-k; i>k; i--, curr=curr->next){//up
                if (curr) ans[i][k]=curr->val;
                else break;
            }
            if (!curr) break;
        }
        return ans; 
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
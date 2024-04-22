class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        vector<int> temp;
        int j=0;
        
        // Iterate through the numbers from 1 to n
        for(int i=1;i<=n;i++){
            if(temp == target) return ans; // If stack equals target, return the answer
            
            // If the current number matches the target element
            if(i == target[j]){
                temp.push_back(i); // Push the number onto the stack
                ans.push_back("Push"); // Add "Push" operation to the answer vector
                j++; // Move to the next element in the target array
            }
            else{
                ans.push_back("Push"); // Add "Push" operation to the answer vector
                ans.push_back("Pop"); // Add "Pop" operation to the answer vector
            }
        }
        return ans;
    }
};
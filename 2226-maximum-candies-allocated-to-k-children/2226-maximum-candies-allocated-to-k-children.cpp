class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int c = candies.size();
        long long start = 1, end = 0, ans = 0, mid;
        long long sum = 0;

        // Compute the total sum and find the maximum candy pile
        for(int i = 0; i < c; i++) {
            sum += candies[i];
            end = max(end, (long long)candies[i]);
        }

        // If total candies are less than children, it's impossible to allocate any
        if (sum < k) return 0;

        // Binary search for the maximum candy size that can be given to each child
        while(start <= end) {
            mid = start + (end - start) / 2;
            long long tc = 0;  // Total count of possible piles
            
            for(int i = 0; i < c; i++) {
                tc += candies[i] / mid;  // Accumulate count of possible piles
            }

            if(tc >= k) {  
                ans = mid; // Store the valid maximum candy count
                start = mid + 1;  // Try to maximize the number of candies per child
            } else {
                end = mid - 1;  // Reduce the candy pile size
            }
        }
        
        return ans;
    }
};

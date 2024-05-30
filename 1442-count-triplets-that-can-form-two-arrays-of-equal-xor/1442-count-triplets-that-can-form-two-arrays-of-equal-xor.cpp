class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        for(int i = 0; i < arr.size() - 1; i++) {
            int val = arr[i];
            for(int k = i + 1; k < arr.size(); k++) {
                val ^= arr[k];
                if(val == 0) count += (k - i);
            }
        }
        return count;
    }
};
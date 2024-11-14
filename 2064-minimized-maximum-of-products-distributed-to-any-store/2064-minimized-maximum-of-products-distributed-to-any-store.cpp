class Solution {
public:
    bool isPossible(int x, vector<int>& quantities, int n) {
        double sum = 0;
        for (auto u : quantities)
            sum += ceil(u * 1.0 / x * 1.0);
        return sum > n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = 100000;
        while (left < right) {
            int mid = (left + right) / 2;
            if (isPossible(mid, quantities, n))
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
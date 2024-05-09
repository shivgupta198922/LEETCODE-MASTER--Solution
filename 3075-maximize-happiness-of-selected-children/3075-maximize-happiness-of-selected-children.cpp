#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int count = 0;
        long long sum = 0;
        sort(happiness.begin(), happiness.end());
        int n = happiness.size() - 1;
        while (n >= 0 && k > 0) {
            sum += max(0, happiness[n] - count++);
            k--;
            n--;
        }
        return sum;
    }
};

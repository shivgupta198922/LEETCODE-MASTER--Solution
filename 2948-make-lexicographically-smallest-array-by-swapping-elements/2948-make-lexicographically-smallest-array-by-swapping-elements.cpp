#include <ranges>
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& arr, int limit) {
        auto sorted = arr;
        sort(begin(sorted), end(sorted));
        auto groups = sorted | views::chunk_by([limit](int x, int y) { return y - x <= limit; });
        vector<vector<int>::iterator> group_iters;
        vector<int> group_heads;
        for (auto group : groups) {
            group_iters.push_back(group.begin());
            group_heads.push_back(group.front());
        }
        for (auto& x : arr) {
            auto it = prev(upper_bound(group_heads.begin(), group_heads.end(), x));
            auto& g_it = group_iters[distance(group_heads.begin(), it)];
            x = *g_it++;
        }
        return arr;
    }
};
static auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return nullptr; }();
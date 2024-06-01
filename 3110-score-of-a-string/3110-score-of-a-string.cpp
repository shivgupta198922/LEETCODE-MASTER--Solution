#include <string>
#include <cmath>

class Solution {
public:
    int scoreOfString(std::string s) {
        int score = 0;
        for (int i = 1; i < s.length(); ++i) {
            score += std::abs(s[i] - s[i - 1]);
        }
        return score;
    }
};

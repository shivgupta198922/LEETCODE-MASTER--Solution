class Solution {
public:
long long minEnd(int count, int value) {
    long long result = value, mask = 1;
    vector<int> indices;
    for (int i = 0; i < 63; i++) {
        if (result >> i & mask ^ mask) {
            indices.push_back(i);
        }
    }
    int size = indices.size();
    for (long long i = 0; i < (mask << size); i++) {
        if (--count == 0) {
            for (int j = 0; j < 63; j++) {
                if (i >> j & mask) {
                    result |= mask << indices[j];
                }
            }
            return result;
        }
    }
    return result;
}

};
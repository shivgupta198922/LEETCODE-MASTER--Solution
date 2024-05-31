class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        // Initial total XOR value for all numbers in the array
        long long total_xor = 0;
        for (int num : nums) {
            total_xor ^= num;
        }
      
        // Find the rightmost set bit in the total XOR (first bit that differs between the two unique numbers)
        int last_bit = total_xor & -total_xor;
      
        int num1 = 0;
        for (int num : nums) {
            // Separate numbers into two groups and find the first unique number by XORing numbers in the same group
            if (num & last_bit) {
                num1 ^= num;
            }
        }
      
        // The second unique number is found by XORing the first unique number with the initial total XOR
        int num2 = total_xor ^ num1;
      
        // Return the two unique numbers
        return {num1, num2};
    }
};
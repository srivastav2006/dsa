class Solution {
public:
    string largestOddNumber(string num) {
        // Start from the last character and move left
        for (int i = num.size() - 1; i >= 0; i--) {
            int digit = num[i] - '0';
            if (digit % 2 == 1) {
                // Found the rightmost odd digit
                return num.substr(0, i + 1);
            }
        }
        // No odd digit found
        return "";
    }
};

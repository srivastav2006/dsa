class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0; 
        int i = 0, sign = 1;

        while (i < (int)s.size() && s[i] == ' ') ++i;          // skip spaces
        if (i < (int)s.size() && (s[i] == '+' || s[i] == '-'))  // sign
            sign = (s[i++] == '-') ? -1 : 1;

        while (i < (int)s.size() && isdigit((unsigned char)s[i])) {
            ans = ans * 10 + (s[i++] - '0');
            long long val = sign * ans;
            if (val >= INT_MAX) return INT_MAX;
            if (val <= INT_MIN) return INT_MIN;
        }
        return (int)(sign * ans);
    }
};

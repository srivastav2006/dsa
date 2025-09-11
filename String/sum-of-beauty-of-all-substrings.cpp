class Solution {
public:
    int beautySum(string str)
    {
        int len = str.length();
        int sum = 0;

        for (int i = 0; i < len; i++) {
            int freq[26] = {0};
            int maxFreq = 0;

            for (int j = i; j < len; j++) {
                int idx = str[j] - 'a';
                freq[idx]++;
                maxFreq = max(maxFreq, freq[idx]);

                
                int minFreq = maxFreq;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        minFreq = min(minFreq, freq[k]);
                        if (minFreq == 1)
                        goto label;
                    }
                }
                label:
                sum += (maxFreq - minFreq);
            }
        }
        return sum;
    }
};
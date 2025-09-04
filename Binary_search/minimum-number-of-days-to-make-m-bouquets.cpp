class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = 1LL * m * k;
        if (total > bloomDay.size()) return -1; 

        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end()); 
        int ans = -1;

        while (high >= low) {
            int mid = low + (high - low) / 2;
            int start = 0, bouquets = 0;

            for (int i = 0; i < (int)bloomDay.size(); i++) {
                if (bloomDay[i] <= mid) {
                    start++;
                    if (start == k) { 
                        bouquets++;
                        start = 0;
                    }
                } else {
                    start = 0;
                }
            }

            if (bouquets >= m) {
                ans = mid;     
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }

        return ans; 
    }
};

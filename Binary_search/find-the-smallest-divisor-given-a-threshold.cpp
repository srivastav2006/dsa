class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canDivide(nums, threshold, mid)) {
                ans = mid;          // candidate answer
                right = mid - 1;    // try smaller divisor
            } else {
                left = mid + 1;     // need bigger divisor
            }
        }
        return ans;
    }

private:
    bool canDivide(vector<int>& nums, int threshold, int divisor) {
        long long total = 0;
        for (int num : nums) {
            total += (num + divisor - 1) / divisor;  // ceil(num/divisor)
            if (total > threshold) return false;     // early stop
        }
        return total <= threshold;
    }
};

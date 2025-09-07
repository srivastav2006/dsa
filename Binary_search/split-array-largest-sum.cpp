class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int count = 1;  // start with 1 subarray
        int currentSum = 0;
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                // need to start a new subarray
                count++;
                currentSum = num;
                if (count > k) return false; // too many subarrays
            } else {
                currentSum += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end()); // minimum possible max sum
        int right = accumulate(nums.begin(), nums.end(), 0); // maximum possible max sum
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canSplit(nums, k, mid)) {
                ans = mid;      // mid works, try smaller
                right = mid - 1;
            } else {
                left = mid + 1; // mid too small, need larger
            }
        }
        return ans;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1); // ensure nums1 is smaller
        }
        
        int n = nums1.size(), m = nums2.size();
        int totalLeft = (n + m + 1) / 2;
        
        int left = 0, right = n;
        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = totalLeft - i;
            
            int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int right1 = (i == n) ? INT_MAX : nums1[i];
            int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2 = (j == m) ? INT_MAX : nums2[j];
            
            if (left1 <= right2 && left2 <= right1) {
                if ((n + m) % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    return max(left1, left2);
                }
            } else if (left1 > right2) {
                right = i - 1; // too many from nums1
            } else {
                left = i + 1; // too few from nums1
            }
        }
        
        return 0.0; // should never reach
    }
};

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;
        
        // Binary search for the first index where missing >= k
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int missing = arr[mid] - (mid + 1);
            
            if (missing < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }

        }
        
        // After the loop, left is the position
        // Answer is left + k
        return left + k;
    }
};

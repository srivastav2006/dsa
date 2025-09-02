class Solution {
public:
    vector<int> searchRange(vector<int>& a, int k) {
        int n = a.size();
        int first = -1, last = -1;

        
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid] < k) {
                low = mid + 1;
            } else if (a[mid] > k) {
                high = mid - 1;
            } else {
                first = mid;
                high = mid - 1; 
            }
        }

      
        low = 0; high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid] < k) {
                low = mid + 1;
            } else if (a[mid] > k) {
                high = mid - 1;
            } else {
                last = mid;
                low = mid + 1; 
            }
        }

        return {first, last};
    }
};

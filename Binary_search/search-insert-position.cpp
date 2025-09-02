class Solution {
public:
    int searchInsert(vector<int>& a, int k) {
        int low=0; int high=a.size();
        while(high>low){
            int mid=low+(high-low)/2;
            if(a[mid]>=k){
                high=mid;
            }
            else{
               low=mid+1;
            }

        }
        return low;
    }
};
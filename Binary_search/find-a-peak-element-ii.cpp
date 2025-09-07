class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size(),l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2,row=0;
            for(int i=0;i<m;i++) if(mat[i][mid]>mat[row][mid]) row=i;
            bool left=mid>0 && mat[row][mid-1]>mat[row][mid];
            bool right=mid<n-1 && mat[row][mid+1]>mat[row][mid];
            if(!left && !right) return {row,mid};
            else if(left) r=mid-1;
            else l=mid+1;
        }
        return {-1,-1};
    }
};

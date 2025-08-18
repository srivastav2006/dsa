class Solution {
public:
    void dfs(vector<vector<int>>& img, int xa, int ya, int nc, int oc) {
        if (xa < 0 || ya < 0 || xa >= img.size() || ya >= img[0].size()) return;
        if (img[xa][ya] != oc) return;

        img[xa][ya] = nc;

        dfs(img, xa+1, ya, nc, oc);
        dfs(img, xa-1, ya, nc, oc);
        dfs(img, xa, ya+1, nc, oc);
        dfs(img, xa, ya-1, nc, oc);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oc = image[sr][sc];
        if (oc == color) return image; 
        dfs(image, sr, sc, color, oc);
        return image;
    }
};

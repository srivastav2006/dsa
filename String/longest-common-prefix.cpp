class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre=strs[0];
        for(int i=1;i<strs.size();i++){
            while(strs[i].find(pre)!=0) pre=pre.substr(0,pre.size()-1);
            if(pre.empty()) return "";
        }
        return pre;
    }
};

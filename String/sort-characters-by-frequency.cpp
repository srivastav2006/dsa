class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for (char c : s) m[c]++;
        vector<pair<int,char>> v;
        for (auto &p : m) v.push_back({p.second,p.first});
        sort(v.begin(), v.end(), [](auto &a, auto &b){ return a.first > b.first; });
        string r;
        for (auto &p : v) r.append(p.first, p.second);
        return r;
    }
};

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        if(dict.find(endWord) == dict.end()) return ans;

        // Step 1: BFS to build levels
        unordered_map<string, vector<string>> parents;
        unordered_set<string> current, next;
        current.insert(beginWord);
        bool found = false;

        while(!current.empty() && !found) {
            for(string w : current) dict.erase(w); // avoid revisiting

            for(string word : current) {
                string tmp = word;
                for(int i = 0; i < tmp.size(); i++) {
                    char original = tmp[i];
                    for(char c = 'a'; c <= 'z'; c++) {
                        tmp[i] = c;
                        if(dict.count(tmp)) {
                            next.insert(tmp);
                            parents[tmp].push_back(word);
                            if(tmp == endWord) found = true;
                        }
                    }
                    tmp[i] = original;
                }
            }
            current.swap(next);
            next.clear();
        }

        // Step 2: Backtracking DFS from endWord to beginWord
        if(found) {
            vector<string> path;
            function<void(string)> dfs = [&](string word) {
                path.push_back(word);
                if(word == beginWord) {
                    vector<string> temp(path.rbegin(), path.rend());
                    ans.push_back(temp);
                } else {
                    for(string p : parents[word]) dfs(p);
                }
                path.pop_back();
            };
            dfs(endWord);
        }

        return ans;
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(endWord) == dict.end()) return 0; // endWord not in dictionary

        queue<pair<string,int>> q;
        q.push({beginWord, 1});

        while(!q.empty()) {
            auto [word, steps] = q.front(); q.pop();
            if(word == endWord) return steps;

            for(int i = 0; i < word.size(); i++) {
                string tmp = word;
                for(char c = 'a'; c <= 'z'; c++) {
                    tmp[i] = c;
                    if(dict.find(tmp) != dict.end()) {
                        dict.erase(tmp); // mark visited
                        q.push({tmp, steps+1});
                    }
                }
            }
        }
        return 0;
    }
};

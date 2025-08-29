
class Solution {
public:
    string reverseWords(string s) {
        // Remove leading/trailing spaces and handle multiple spaces
        stringstream ss(s);
        string word;
        vector<string> words;
        
        while (ss >> word) { // this automatically skips spaces
            words.push_back(word);
        }

        // Reverse the list of words
        reverse(words.begin(), words.end());

        // Join them with a single space
        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i < words.size() - 1) {
                result += " ";
            }
        }
        return result;
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        
        int res = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string word = q.front();
                q.pop();

                if (word == endWord) return res;

                for (int i = 0; i < word.size(); i++) {
                    char old = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == old) continue;
                        word[i] = c;

                        if (words.find(word) != words.end()) {
                            q.push(word);
                            words.erase(word);    // mark visited
                        }
                    }
                    word[i] = old;
                }
            }
            res++;
        }
        return 0;
    }
};
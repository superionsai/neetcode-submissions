class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> categories;
        string temp;
        for (auto it: strs) {
            temp = it;
            sort(temp.begin(), temp.end());
            categories[temp].push_back(it);
        }
        vector<vector<string>> answer;
        for (auto &entry: categories) {
            answer.push_back(entry.second);
        }
        return answer;
    }
};

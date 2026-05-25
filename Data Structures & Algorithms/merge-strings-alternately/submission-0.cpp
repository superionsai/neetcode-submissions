class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int pointer_1 = 0, pointer_2 = 0;
        string word = "";
        while (pointer_1 < word1.size() && pointer_2 < word2.size()) {
            word += word1[pointer_1]; 
            word += word2[pointer_2];
            pointer_1++; pointer_2++;
        }
        if (pointer_1 < word1.size()) {
            while (pointer_1 < word1.size()) {
                word += word1[pointer_1]; pointer_1++;
            }
        }
        if (pointer_2 < word2.size()) {
            while (pointer_2 < word2.size()) {
                word += word2[pointer_2]; pointer_2++;
            }
        }
        return word;
    }
};
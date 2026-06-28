class Solution {
public:
    void dfs(vector<string>& res, string cur, int&n, int count, int total) {
        if (count + total == n) {
            while (count--) cur += ")";
            res.push_back(cur);
            return;
        }

        dfs(res, cur + "(", n, count + 1, total);
        if (count > 0) dfs(res, cur + ")", n, count - 1, total + 1);
    }

    vector<string> generateParenthesis(int n) {
        if (n==0) return {};
        vector<string> res;
        dfs(res, "(", n, 1, 0);

        return res;
    }
};

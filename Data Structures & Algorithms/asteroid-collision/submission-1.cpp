class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> buffer;
        for (auto it : asteroids) {
            if (it < 0) {
                while (!buffer.empty() && buffer.back() > 0 && abs(buffer.back()) < abs(it)) {
                    buffer.pop_back();
                }
                if (!buffer.empty() && buffer.back() > 0) {
                    if (buffer.back() == abs(it)) buffer.pop_back();
                    continue;
                }
                buffer.push_back(it);
            } else {
                buffer.push_back(it);
            }
        }
        return buffer;
    }
};
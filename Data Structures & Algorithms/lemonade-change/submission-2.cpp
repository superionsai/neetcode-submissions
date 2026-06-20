class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        for (auto iter: bills) {
            if (iter == 5) fives++;
            else if (iter == 10) {
                if (fives) fives--;
                else return false;
                tens++;
            }
            else {
                if (fives && tens) {
                    fives--; tens--;
                }
                else if (fives >= 3) {
                    fives = fives - 3;
                }
                else return false;
            }
        }
        return true;
    }
};
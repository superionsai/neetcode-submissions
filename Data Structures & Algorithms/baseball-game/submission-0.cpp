class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector <int> record; int size = 0;
        for (auto it: operations) {
            if (it == "+") {
                record.push_back(record[size-1] + record[size-2]);
                size++;
            }
            else if (it == "C") {
                record.pop_back(); size--;
            }
            else if (it == "D") {
                record.push_back(record[size-1]*2);
                size++;
            }
            else {
                record.push_back(stoi(it));
                size++;
            }
        }
        return accumulate(record.begin(), record.end(), 0);
    }
};
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset <int> sortedHand; 
        for (auto it: hand) sortedHand.insert(it);

        while (!sortedHand.empty()) {
            int curr = *sortedHand.begin();
            sortedHand.erase(sortedHand.find(curr));
            cout << curr << " ";
            int counter = groupSize - 1;
            while (counter--) {
                if (sortedHand.empty() ||
                    sortedHand.find(++curr) == sortedHand.end()) 
                        return false;
                cout << curr << " ";
                sortedHand.erase(sortedHand.find(curr));
            }

            cout << "\n";
        }

        return true;
    }
};

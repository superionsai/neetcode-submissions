class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boatCount = 0;
        int smaller = 0, larger = people.size()-1;
        while (smaller < larger) {
            if ((people[smaller] + people[larger]) > limit) {
                do { larger--; boatCount++; }
                while (larger >= 0 && (people[larger] == people[larger+1]));
            }
            else {
                smaller++; larger--; boatCount++;
            }
        }
        return boatCount + ((smaller==larger) ? 1 : 0);
    }
};
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> maxHeap;
        for (auto stone: stones) {
            maxHeap.push(stone);
        } 
        while (maxHeap.size() > 1) {
            int stone1 = maxHeap.top(); maxHeap.pop();
            int stone2 = maxHeap.top(); maxHeap.pop();
            maxHeap.push(abs(stone1 - stone2));
        }
        return (maxHeap.empty()) ? 0 : maxHeap.top();
    }
};

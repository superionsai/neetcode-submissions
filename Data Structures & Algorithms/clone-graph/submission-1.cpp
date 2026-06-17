class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        return clone(node);
    }

    Node* clone(Node* node) {
        if (mp.count(node))
            return mp[node];

        Node* newNode = new Node(node->val);
        mp[node] = newNode;

        for (Node* nei : node->neighbors)
            newNode->neighbors.push_back(clone(nei));

        return newNode;
    }
};

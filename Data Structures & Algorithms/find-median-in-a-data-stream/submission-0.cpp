class MedianFinder {
private:
    struct Node {
        int val, height, size;
        Node *left, *right;
        Node(int v) : val(v), height(1), size(1), left(NULL), right(NULL) {}
    };

    Node* root = NULL;

    int height(Node* n) { return n ? n->height : 0; }
    int size(Node* n) { return n ? n->size : 0; }

    void update(Node* n) {
        if (!n) return;
        n->height = 1 + max(height(n->left), height(n->right));
        n->size = 1 + size(n->left) + size(n->right);
    }

    int balanceFactor(Node* n) {
        return height(n->left) - height(n->right);
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        update(y);
        update(x);
        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        update(x);
        update(y);
        return y;
    }

    Node* balance(Node* n) {
        update(n);
        int bf = balanceFactor(n);

        if (bf > 1) {
            if (balanceFactor(n->left) < 0)
                n->left = rotateLeft(n->left);
            return rotateRight(n);
        }
        if (bf < -1) {
            if (balanceFactor(n->right) > 0)
                n->right = rotateRight(n->right);
            return rotateLeft(n);
        }
        return n;
    }

    Node* insert(Node* n, int val) {
        if (!n) return new Node(val);

        if (val <= n->val)
            n->left = insert(n->left, val);
        else
            n->right = insert(n->right, val);

        return balance(n);
    }

    // Find k-th smallest (1-indexed)
    int kth(Node* n, int k) {
        int leftSize = size(n->left);
        if (k == leftSize + 1)
            return n->val;
        if (k <= leftSize)
            return kth(n->left, k);
        return kth(n->right, k - leftSize - 1);
    }

public:
    MedianFinder() {}

    void addNum(int num) {
        root = insert(root, num);
    }

    double findMedian() {
        int n = size(root);
        if (n % 2 == 1)
            return kth(root, (n + 1) / 2);
        else {
            int a = kth(root, n / 2);
            int b = kth(root, n / 2 + 1);
            return (a + b) / 2.0;
        }
    }
};

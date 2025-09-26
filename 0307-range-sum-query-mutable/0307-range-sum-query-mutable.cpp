class SegmentTree {
private:
    struct Node {
        int l, r;
        int sum;
        Node* lChild;
        Node* rChild;
        
        Node(int l, int r) : l(l), r(r), sum(0), lChild(nullptr), rChild(nullptr) {}
    };
    
    Node* root;
    
    Node* build(vector<int>& nums, int l, int r) {
        Node* node = new Node(l, r);
        
        if (l == r) {
            node->sum = nums[l];
            return node;
        }
        
        int mid = (l + r) / 2;
        node->lChild = build(nums, l, mid);
        node->rChild = build(nums, mid + 1, r);
        node->sum = node->lChild->sum + node->rChild->sum;
        
        return node;
    }
    
    void pointUpdate(Node* node, int index, int value) {
        if (node->l == node->r) {
            node->sum = value;
            return;
        }
        
        int mid = (node->l + node->r) / 2;
        if (index <= mid) {
            pointUpdate(node->lChild, index, value);
        } else {
            pointUpdate(node->rChild, index, value);
        }
        node->sum = node->lChild->sum + node->rChild->sum;
    }
    
    int rangeQuery(Node* node, int l, int r) {
        if (l > node->r || r < node->l) {
            return 0;
        }
        
        if (l <= node->l && r >= node->r) {
            return node->sum;
        }
        
        return rangeQuery(node->lChild, l, r) + rangeQuery(node->rChild, l, r);
    }
    
public:
    SegmentTree(vector<int>& nums) {
        root = build(nums, 0, nums.size() - 1);
    }
    
    void update(int index, int val) {
        pointUpdate(root, index, val);
    }
    
    int sumRange(int left, int right) {
        return rangeQuery(root, left, right);
    }
};

class NumArray {
private:
    SegmentTree* segTree;
    
public:
    NumArray(vector<int>& nums) {
        segTree = new SegmentTree(nums);
    }
    
    void update(int index, int val) {
        segTree->update(index, val);
    }
    
    int sumRange(int left, int right) {
        return segTree->sumRange(left, right);
    }
};
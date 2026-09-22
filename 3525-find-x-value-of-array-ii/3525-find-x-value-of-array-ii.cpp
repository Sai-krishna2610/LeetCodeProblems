struct Info {
    int count[5] = {0};
    int product = 0;
};

class RangeTree {
public:
    int size;
    int mod;
    vector<Info> tree;

    RangeTree(vector<int>& arr, int k) {
        mod = k;
        size = arr.size();
        tree.assign(4 * size, Info());
        buildTree(0, 0, size - 1, arr);
    }

    void buildTree(int node, int left, int right, vector<int>& arr) {
        if (left == right) {
            makeLeaf(node, arr[left]);
            return;
        }

        int middle = left + (right - left) / 2;

        buildTree(2 * node + 1, left, middle, arr);
        buildTree(2 * node + 2, middle + 1, right, arr);

        tree[node] = combine(
            tree[2 * node + 1],
            tree[2 * node + 2]
        );
    }

    void makeLeaf(int node, int value) {
        for (int rem = 0; rem < mod; rem++) {
            tree[node].count[rem] = 0;
        }

        int remainder = value % mod;

        tree[node].count[remainder] = 1;
        tree[node].product = remainder;
    }

    Info combine(Info& leftPart, Info& rightPart) {
        Info merged;

        merged.product =
            (leftPart.product * rightPart.product) % mod;

        for (int rem = 0; rem < mod; rem++) {
            merged.count[rem] = leftPart.count[rem];
        }

        for (int rem = 0; rem < mod; rem++) {
            int newRemainder =
                (leftPart.product * rem) % mod;

            merged.count[newRemainder] +=
                rightPart.count[rem];
        }

        return merged;
    }

    void changeValue(
        int node,
        int left,
        int right,
        int position,
        int value
    ) {
        if (left == right) {
            makeLeaf(node, value);
            return;
        }

        int middle = left + (right - left) / 2;

        if (position <= middle) {
            changeValue(
                2 * node + 1,
                left,
                middle,
                position,
                value
            );
        } else {
            changeValue(
                2 * node + 2,
                middle + 1,
                right,
                position,
                value
            );
        }

        tree[node] = combine(
            tree[2 * node + 1],
            tree[2 * node + 2]
        );
    }

    void updateValue(int position, int value) {
        changeValue(
            0,
            0,
            size - 1,
            position,
            value
        );
    }

    Info getRange(
        int queryLeft,
        int queryRight,
        int node,
        int left,
        int right
    ) {
        if (left >= queryLeft && right <= queryRight) {
            return tree[node];
        }

        int middle = left + (right - left) / 2;

        if (queryRight <= middle) {
            return getRange(
                queryLeft,
                queryRight,
                2 * node + 1,
                left,
                middle
            );
        }

        if (queryLeft > middle) {
            return getRange(
                queryLeft,
                queryRight,
                2 * node + 2,
                middle + 1,
                right
            );
        }

        Info leftResult = getRange(
            queryLeft,
            queryRight,
            2 * node + 1,
            left,
            middle
        );

        Info rightResult = getRange(
            queryLeft,
            queryRight,
            2 * node + 2,
            middle + 1,
            right
        );

        return combine(leftResult, rightResult);
    }

    Info queryRange(int start, int finish) {
        return getRange(
            start,
            finish,
            0,
            0,
            size - 1
        );
    }
};

class Solution {
public:
    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        int n = nums.size();

        RangeTree segmentTree(nums, k);

        vector<int> answer;

        for (auto& query : queries) {
            int updateIndex = query[0];
            int newValue = query[1];
            int startIndex = query[2];
            int targetRemainder = query[3];

            segmentTree.updateValue(
                updateIndex,
                newValue
            );

            Info result = segmentTree.queryRange(
                startIndex,
                n - 1
            );

            answer.push_back(
                result.count[targetRemainder]
            );
        }

        return answer;
    }
};
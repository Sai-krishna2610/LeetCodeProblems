class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& health, string dir) {
        
        int n = pos.size();

        // Step 1: Store indices and sort by position
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b) {
            return pos[a] < pos[b];
        });

        // Step 2: Track alive robots
        vector<bool> alive(n, true);

        // Stack to keep right-moving robots
        vector<int> stack;

        // Step 3: Process robots in sorted order
        for (int idx : order) {

            // If moving right → push to stack
            if (dir[idx] == 'R') {
                stack.push_back(idx);
            } 
            else {
                // Moving left → possible collisions
                while (!stack.empty()) {

                    int top = stack.back();

                    if (health[top] < health[idx]) {
                        // Right robot dies
                        alive[top] = false;
                        stack.pop_back();
                        health[idx]--;
                    } 
                    else if (health[top] > health[idx]) {
                        // Left robot dies
                        alive[idx] = false;
                        health[top]--;
                        break;
                    } 
                    else {
                        // Both die
                        alive[top] = false;
                        alive[idx] = false;
                        stack.pop_back();
                        break;
                    }
                }
            }
        }

        // Step 4: Collect surviving robots' health
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (alive[i]) {
                result.push_back(health[i]);
            }
        }

        return result;
    }
};
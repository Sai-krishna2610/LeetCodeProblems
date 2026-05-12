#define ll long long

class Solution {
public:

    bool isPossible(ll energy, vector<vector<int>>& tasks) {

        for (auto &task : tasks) {

            int actual = task[0];
            int minimum = task[1];

            if (energy < minimum) {
                return false;
            }

            energy -= actual;
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(),
             [](const vector<int>& a, const vector<int>& b) {

                 return (a[1] - a[0]) > (b[1] - b[0]);
             });

        ll low = 0;
        ll high = INT_MAX;

        ll answer = INT_MAX;

        while (low <= high) {

            ll mid = low + (high - low) / 2;

            if (isPossible(mid, tasks)) {

                answer = mid;
                high = mid - 1;

            } else {

                low = mid + 1;
            }
        }

        return (int)answer;
    }
};
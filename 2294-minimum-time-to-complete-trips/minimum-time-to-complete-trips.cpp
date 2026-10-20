class Solution {
public:
    bool possible(const vector<int>& time, long long givenTime, int totalTrips) {
        long long actualTrips = 0;
        for (const int& t : time) {
            actualTrips += givenTime / t;
            if (actualTrips >= totalTrips) return true;
        }
        return actualTrips >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1;
        long long r = (long long)*min_element(time.begin(), time.end()) * totalTrips;
        long long ans = r;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (possible(time, mid, totalTrips)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
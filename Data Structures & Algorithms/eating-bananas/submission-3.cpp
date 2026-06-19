class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long n = piles.size();
        long long time;
        long long ans;

        if (n > h)
            return -1;

        long long l = 0, r = LLONG_MAX; // cuz r has to be less than or equal to h upper bound
        
        while (l < r) {
            long long mid = (l+r)/2;
            time = 0;

            if (mid == 0)
                break;
            
            for (long long i = 0; i < n; i++) {
                time += ceil((double)piles[i]/mid);
            }

            cout << l << " " << " " << mid << " " << r << " " << time << endl;

            if (time > h) {
                l = mid+1;
            }

            if (time <= h) {
                r = mid;
                ans = mid;
            }
            
        }

        return ans;

    }
};

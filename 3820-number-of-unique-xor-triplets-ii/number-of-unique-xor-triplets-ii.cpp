class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<int> has(MAXX, 0);
        for (int x : nums)
            has[x] = 1;

        vector<int> two(MAXX, 0);
        for (int a = 0; a < MAXX; a++) {
            if (!has[a]) continue;
            for (int b = 0; b < MAXX; b++) {
                if (!has[b]) continue;
                two[a ^ b] = 1;
             }
        }

        vector <int> three(MAXX, 0);
        for (int x = 0; x < MAXX; x++) {
            if (! two[x]) continue;
            for (int v = 0; v < MAXX; v++) {
                if (!has[v]) continue;
                three[x ^ v] = 1;
            }
        }

        int ans = 0;
        for (int x : three)
            ans += x;
        return ans;
    }
};
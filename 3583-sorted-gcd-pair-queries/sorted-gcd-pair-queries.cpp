class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;

        vector<long long> cnt(mx + 1, 0);

        for (int g = 1; g <= mx; g++) {
            for (int multiple = g; multiple <= mx; multiple += g) {
                cnt[g] += freq[multiple];
            }
        }

        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            long long c = cnt[g];
            exact[g] = c * (c - 1) / 2;

            for (int multiple = 2 * g; multiple <= mx; multiple += g) {
                exact[g] -= exact[multiple];
            }
        }

        vector<long long> pref(mx + 1, 0);
        for (int g = 1; g <= mx; g++) {
            pref[g] = pref[g - 1] + exact[g];
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (long long k : queries) {
            int g = lower_bound(pref.begin() + 1, pref.end(), k + 1) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};
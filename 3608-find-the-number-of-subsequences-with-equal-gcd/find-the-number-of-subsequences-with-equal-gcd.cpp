class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int n;
    vector<int> nums;

    vector<vector<vector<int>>> memo;

    int solve(int idx, int g1, int g2) {
        if (idx == n) {
            return (g1 == g2 && g1 != 0);
        }

        int &res = memo[idx][g1][g2];
        if (res != -1) return res;

        long long ans = 0;
        int x = nums[idx];

        // Put in seq1
        int ng1 = (g1 == 0 ? x : gcd(g1, x));
        ans += solve(idx + 1, ng1, g2);

        // Put in seq2
        int ng2 = (g2 == 0 ? x : gcd(g2, x));
        ans += solve(idx + 1, g1, ng2);

        // Skip
        ans += solve(idx + 1, g1, g2);

        return res = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());

        memo.assign(
            n,
            vector<vector<int>>(mx + 1,
            vector<int>(mx + 1, -1))
        );

        return solve(0, 0, 0);
    }
};
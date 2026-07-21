class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";

        int ones = 0;
        for (char c : s)
            if (c == '1') ones++;

        int best = 0;
        int n = t.size();
        int i = 0;

        while (i < n) {
            if (t[i] == '0') {
                int j = i;
                while (j < n && t[j] == '0') j++;
                int leftZero = j - i;

                int k = j;
                while (k < n && t[k] == '1') k++;

                if (k < n) {
                    int l = k;
                    while (l < n && t[l] == '0') l++;

                    if (l > k) {
                        int rightZero = l - k;
                        best = max(best, leftZero + rightZero);
                    }
                }

                i = j;
            } else {
                i++;
            }
        }

        return ones + best;
    }
};
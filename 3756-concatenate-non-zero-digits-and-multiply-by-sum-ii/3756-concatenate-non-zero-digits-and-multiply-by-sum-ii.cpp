class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
            vector<int> pos;          // original indices of non-zero digits
        vector<int> digit;        // non-zero digits

        // Build compressed string of non-zero digits
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int n = digit.size();

        // powers of 10
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // prefix value
        vector<long long> prefValue(n + 1, 0);

        // prefix digit sum
        vector<long long> prefSum(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefValue[i] = (prefValue[i - 1] * 10 + digit[i - 1]) % MOD;
            prefSum[i] = prefSum[i - 1] + digit[i - 1];
        }
        vector<int>ans;
        for (auto&q:queries){
            int l=q[0];
            int r=q[1];
            
            auto it1 = lower_bound(pos.begin(), pos.end(), l);
            auto it2 = upper_bound(pos.begin(), pos.end(), r);
            if (it1 == it2) {
                ans.push_back(0);
                continue;
            }
            int L = it1 - pos.begin();
            int R = (it2 - pos.begin()) - 1;

            int len = R - L + 1;
            long long x =(prefValue[R + 1] -prefValue[L] * pow10[len] % MOD + MOD) % MOD;
            long long sum = prefSum[R + 1] - prefSum[L];
            ans.push_back((x * (sum % MOD)) % MOD);
        }
        return ans;
    }
};
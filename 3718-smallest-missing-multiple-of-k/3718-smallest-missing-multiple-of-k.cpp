class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());
        int current=k;
        while(st.count(current)){
            current+=k;
        }
        return current;
    }
};
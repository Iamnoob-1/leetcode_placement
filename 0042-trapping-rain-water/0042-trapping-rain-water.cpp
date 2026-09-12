class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftmax(n);
        int maxl=INT_MIN;
        for (int i=0;i<n;i++){
            maxl=max(maxl,height[i]);
            leftmax[i]=maxl;
        }
        vector<int>rightmax(n);
        int maxr=INT_MIN;
        for (int i=n-1;i>=0;i--){
            maxr=max(maxr,height[i]);
            rightmax[i]=maxr;
        }
        int ans=0;
        for (int i=0;i<n;i++){
            ans+=min(rightmax[i],leftmax[i])-height[i];
        }
        return ans;
    }
};
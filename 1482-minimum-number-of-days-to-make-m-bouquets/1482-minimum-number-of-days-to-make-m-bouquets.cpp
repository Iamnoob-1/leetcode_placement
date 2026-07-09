class Solution {
public:
    bool possible(vector<int>bloom,int m,int k,int days){
        int bouquets=0;
        int flowers=0;
        for (int i=0;i<bloom.size();i++){
            if (bloom[i]<=days){
                flowers++;
                if (flowers==k){
                    bouquets++;
                    flowers=0;
                }
            }
            else{
                flowers=0;
            }
        }
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1LL*m*k>bloomDay.size())return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=INT_MAX;
        while (low<=high){
            int mid=low+(high-low)/2;
            if (possible(bloomDay,m,k,mid)){
                high=mid-1;
                ans=min(ans,mid);
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
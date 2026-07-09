class Solution {
public:
    long long findtime(vector<int>&piles,int speed){
        long long totalhours=0;
        for (int i=0;i<piles.size();i++){
            if (piles[i]%speed==0){
                totalhours+=piles[i]/speed;
            }
            else{
                totalhours+=piles[i]/speed+1;
            }
        }
        return totalhours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for (int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        int high=maxi;
        int low=1;
        int ans=high;
        while (low<=high){
            int mid = low + (high - low) / 2;
            long long timerequired=findtime(piles,mid);
            if (timerequired<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
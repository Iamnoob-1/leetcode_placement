class Solution {
public:
    bool findnext(vector<int>&hand,int gsize,int i,int n){
        int next=hand[i]+1;
        hand[i]=-1;
        int count=1;
        while (i<n &&count<gsize){
            if (hand[i]==next){
                next=hand[i]+1;
                hand[i]=-1;
                count++;
            }
            i++;
        }
        return count==gsize;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if (n%groupSize!=0)return false;
        sort(hand.begin(),hand.end());
        for (int i=0;i<n;i++){
            if (hand[i]>=0){
                if (!findnext(hand,groupSize,i,n))return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>mp;
        for (int b:bills){
            if(b==5){
                mp[5]++;
            }
            else if (b==10){
                if (mp[5]>=1){
                    mp[5]--;
                    mp[10]++;
                }
                else{
                    return false;
                }
            }
            else{
                if (mp[10]>=1 && mp[5]>=1){
                    mp[10]--;
                    mp[5]--;
                    mp[20]++;
                }
                else if(mp[5]>=3){
                    mp[5]-=3;
                    mp[20]++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len=tasks.size();
        unordered_map<char,int>mp;
        int maxfreq=INT_MIN;

        for(auto &task:tasks){
            mp[task]++;
            maxfreq=max(maxfreq,mp[task]);
        }
        int numberofmaxfreq=0;
        for(auto &it:mp){
            if(it.second==maxfreq){
                numberofmaxfreq++;
            }
        }
        int ans=((n+1)*(maxfreq-1))+numberofmaxfreq;
        return max(len,ans);
    }
};
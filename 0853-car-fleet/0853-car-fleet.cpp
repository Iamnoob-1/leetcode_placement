class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>car;
        for (int i=0;i<speed.size();i++){
            car.push_back({position[i],speed[i]});
        }
        sort(car.begin(),car.end());
        reverse(car.begin(),car.end());
        int fleets=0;
        double lasttime=0;
        for(auto ch:car){
            int pos=ch.first;
            int speed=ch.second;
            double time=(double)(target-pos)/speed;
            if(time>lasttime){
                fleets++;
                lasttime=time;
            }
        }
        return fleets;
    }
};
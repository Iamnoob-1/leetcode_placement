class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        vector<pair<double,double>> rate;
        for (int i = 0; i < quality.size(); i++) {
            rate.push_back({(1.0 * wage[i]) / (1.0 * quality[i]), i});
        }
        sort(rate.begin(), rate.end());
        priority_queue<int> pq;
        double sum = 0;
        double mini = DBL_MAX;
        for (int i = 0; i < rate.size(); i++) {
            sum += quality[rate[i].second];
            pq.push(quality[rate[i].second]);
            if (pq.size() < k)
                continue;
            while (pq.size() > k) {
                int tp = pq.top();
                sum -= tp;
                pq.pop();
            }
            if (pq.size()==k){
                double ans = sum * rate[i].first;
                mini = min(mini, ans);
            }
        }
        return mini;
    }
};
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int num:stones){
            pq.push(num);
        }
        while (pq.size()>1){
            int num1=pq.top();
            pq.pop();
            int num2=pq.top();
            pq.pop();
            if (abs(num1-num2)==0){
                continue;
            }

            else{
                pq.push(abs(num1-num2));
            }
        }
        return pq.empty() ? 0: pq.top();

    }
};
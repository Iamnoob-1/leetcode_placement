class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        if (!st.count(endWord))return 0;
        queue<string>q;
        q.push(beginWord);
        int step=1;
        while(!q.empty()){
            int qsize=q.size();
            for (int i=0;i<qsize;i++){
                string curr=q.front();
                q.pop();
                if (curr==endWord)return step;
                for (int i=0;i<curr.size();i++){
                    char original=curr[i];
                    for (char ch='a';ch<='z';ch++){
                        curr[i]=ch;
                        if(st.count(curr)){
                            q.push(curr);
                            st.erase(curr);
                        }
                    }
                    curr[i]=original;
                }
            }
            step++;
        }
        return 0;
    }
};
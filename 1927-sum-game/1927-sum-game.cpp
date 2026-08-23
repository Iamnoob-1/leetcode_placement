class Solution {
public:
    bool sumGame(string num) {
        int countl=0;
        int suml=0,sumr=0;

        int countr=0;
        for (int i=0;i<num.size();i++){
            if(i<num.size()/2){
                if(num[i]=='?')countl++;
                else{
                    suml+=num[i]-'0';
                }
            }
            else{
                if(num[i]=='?')countr++;
                else{
                    sumr+=num[i]-'0';
                }
            }
        }
        if(countl==0&&countr==0)return suml!=sumr;
        if((countl+countr)%2!=0)return true;
        if(countl==countr){
            if(suml==sumr)return false;
            else{return true;}
        }
        return 2*(suml-sumr)!=9*(countr-countl);
    }
};
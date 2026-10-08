class Solution {
public:
    int romanToInt(string s) {
        int res=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='V'){
                if(i>0 && s[i-1]=='I'){
                    res-=2*1;
                }
                res+=5;
            }
            else if(s[i]=='X'){
                if(i>0 && s[i-1]=='I'){
                    res-=2*1;
                }
                res+=10;
            }
            else if(s[i]=='L'){
                if(i>0 && s[i-1]=='X'){
                    res-=2*10;
                }
                res+=50;
            }
            else if(s[i]=='C'){
                if(i>0 && s[i-1]=='X'){
                    res-=2*10;
                }
                res+=100;
            }
            else if(s[i]=='D'){
                if(i>0 && s[i-1]=='C'){
                    res-=2*100;
                }
                res+=500;
            }
            else if(s[i]=='M'){
                if(i>0 && s[i-1]=='C'){
                    res-=2*100;
                }
                res+=1000;
            }
            else res+=1;
        }
        return res;
    }
};
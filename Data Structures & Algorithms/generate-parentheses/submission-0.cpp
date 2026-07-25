class Solution {
    void solver(vector<string> &res,string str,int a,int b,int n){
        if(str.size()==2*n){
            res.push_back(str);
            return;
        }
        string s1 = str,s2 = str;
        if(a<n){
            s1+="(";
            solver(res,s1,a+1,b,n);
        }
        if(b<a){
            s2+=")";
            solver(res,s2,a,b+1,n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str = "(";
        solver(res,str,1,0,n);
        return res;
    }
};

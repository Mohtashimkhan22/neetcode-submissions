class Solution {
    void solver(vector<vector<string>> &res,string s,vector<string> &temp,int start){
        int n = s.size();
        if(start==s.size()){
            res.push_back(temp);
            return;
        } 
        for(int j=start;j<n;j++){
            string st = s.substr(start,j-start+1);
            cout<<st<<" ";
            if(palindrom(s,start,j)){
                temp.push_back(st);
                solver(res,s,temp,j+1);
                temp.pop_back();
            }
        }
    }
    bool palindrom(string str,int i,int j){
        while(i<j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        // int n = s.size();
        solver(res,s,temp,0);
        return res;
    }
};

class Solution {
    void solver(unordered_map<char,string> &mp,string digits,vector<string> &res,string str,int row){
        int n = digits.size();
        if(row==n){
            res.push_back(str);
            return;
        }
        string s = mp[digits[row]];
        cout<<s<<" ";
        for(auto ch : s){            
            str+=ch;
            solver(mp,digits,res,str,row+1);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> res;
        string str;
        if(digits.empty()) return res;
        solver(mp,digits,res,str,0);
        return res;
    }
};

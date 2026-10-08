class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int maxi = 0;
        string res = "",str="";
        int i=0,j=0;
        while(i<str1.size() && j<str2.size()){
            str+=str1[i];
            string a = "";
            while(a.size()<str1.size()){
                a+=str;
            }
            string b = "";
            while(b.size()<str2.size()){
                b+=str;
            }
            if(a==str1 && b==str2){
                if(maxi<str.size()){
                    maxi = str.size();
                    res=str;
                }
            }
            i++;
            j++;
        }
        return res;
    }
};
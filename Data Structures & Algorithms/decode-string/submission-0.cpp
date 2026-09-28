class Solution {

    string solver(int &i, string &s) {

        int n = s.size();
        string str = "";
        int num = 0;

        while (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            i++;
        }

        // skip '['
        i++;

        while (i < n && s[i] != ']') {

            if (isdigit(s[i])) {
                str += solver(i, s);
            }
            else {
                str += s[i];
                i++;
            }
        }

        // skip ']'
        if (i < n && s[i] == ']')
            i++;

        string res = "";

        for (int j = 1; j <= num; j++) {
            res += str;
        }

        return res;
    }

public:

    string decodeString(string s) {

        int i = 0;
        int n = s.size();
        string str = "";

        while (i < n) {

            if (isdigit(s[i])) {
                str += solver(i, s);
            }
            else {
                str += s[i];
                i++;
            }
        }

        return str;
    }
};
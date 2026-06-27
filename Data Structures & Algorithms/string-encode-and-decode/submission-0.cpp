class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for (auto it : strs) {
            str += to_string(it.size());
            str += "#";
            str += it;
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;
        while (i < s.size()) {

            int len = 0;
            while (s[i] != '#') {
                len = len * 10 + (s[i] - '0');
                i++;
            }

            i++;

            string str = s.substr(i, len);
            ans.push_back(str);

            i += len;
        }

        return ans;
    }
};
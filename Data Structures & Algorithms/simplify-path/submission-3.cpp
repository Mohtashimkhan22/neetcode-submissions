class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> result;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            }
            else if (token == "..") {
                if (!result.empty())
                    result.pop_back();
            }
            else {
                result.push_back(token);
            }
        }
        string res = "";
        for (auto it : result) {
            res += "/" + it;
        }
        return res.empty() ? "/" : res;
    }
};
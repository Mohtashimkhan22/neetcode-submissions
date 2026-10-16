struct trie {
    trie* child[26];
    bool isEnd;
    string word;

    trie() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        isEnd = false;
    }
};

class Solution {
    trie* root = new trie();

    void insert(string str) {
        trie* curr = root;

        for (char ch : str) {
            int idx = ch - 'a';

            if (curr->child[idx] == nullptr) {
                curr->child[idx] = new trie();
            }

            curr = curr->child[idx];
        }

        curr->isEnd = true;
        curr->word = str;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        for (const auto& word : dictionary) {
            insert(word);
        }

        int n = s.size();
        // vector<int> dp(n + 1, -1);
        // string str = "";
        // for (int i = 1; i <= n; i++) {
        //     dp[i] = dp[i - 1] + 1;

        //     trie* curr = root;

        //     for (int j = i - 1; j < n; j++) {
        //         int idx = s[j] - 'a';

        //         if (curr->child[idx] == nullptr) {
        //             break;
        //         }

        //         curr = curr->child[idx];

        //         if (curr->isEnd) {
        //             dp[j + 1] = min(dp[j + 1], dp[i - 1]);
        //             str+=curr->word;
        //         }
        //     }
        // }
        // return dp[n];
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1 + dp[i + 1];

            trie* curr = root;

            for (int j = i; j < n; j++) {
                if (!curr->child[s[j] - 'a'])
                    break;

                curr = curr->child[s[j] - 'a'];

                if (curr->isEnd) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};
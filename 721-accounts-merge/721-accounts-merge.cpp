class Solution {
private:
    set<string> visited_email;
    map<string, vector<string>> adj_account;
public:
     /*
            Ex. Input: [["John", "j1@g.com", "j2@y.com"], ["Ruby", "r1@g.com", "r2@g.com", "j2@y.com"], ["John", "j3@g.com", "j4@y.com"]]
                Output: [["John", "j1@g.com", "j2@y.com", "r1@g.com", "r2@g.com"], ["John", "j3@g.com", "j4@y.com"]]
        */
    void dfs_explore(vector<string>& merge_acc, string email) {
        visited_email.insert(email);
        merge_acc.push_back(email);
        for(auto& adj_email : adj_account[email]) {
            if(visited_email.find(adj_email) == visited_email.end())
                        dfs_explore(merge_acc, adj_email);
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       /*
        O(NK log NK) solution [N -> No. of accounts, K -> no. of emails]
        1. Build adj matrix of emails
        2. Traverse each and every account in DFS only if not visited
        3. Obtain merge account and sort each account value
       */
        
        string acc_name, first_email, email;
        vector<vector<string>> res;
        
        //build adj_list
        for(vector<string>& account : accounts) {
            acc_name = account[0];
            first_email = account[1];
            for(int i = 2; i < account.size(); i++) {
                    email = account[i];
                    adj_account[first_email].push_back(email);
                    adj_account[email].push_back(first_email);
                }
            }
            //traverse
            for(vector<string>& account : accounts) {
                acc_name = account[0];
                first_email = account[1];
                if(visited_email.find(first_email) == visited_email.end()) {
                    vector<string> merge_acc;
                    merge_acc.push_back(acc_name);
                    dfs_explore(merge_acc, first_email);
                    sort(merge_acc.begin() + 1, merge_acc.end());
                    res.push_back(merge_acc);
                }
            }
            return res;
    }
};

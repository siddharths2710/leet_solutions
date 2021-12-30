class Solution {
private:
    struct Log {
        int id;
        bool start;
        int ts;
    };
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<Log> log_stack;
        vector<int> times(n, 0);
        string id_str, start_str, ts_str;
        stringstream ss;
        int exec_time;
        for(string& log: logs) {
            ss.clear();
            ss.str(log);
            getline(ss, id_str, ':');
            getline(ss, start_str, ':');
            getline(ss, ts_str, ':');
            
            Log new_log = {stoi(id_str), !start_str.compare("start"), stoi(ts_str)};
            if(new_log.start) log_stack.push(new_log);
            else {
                Log start_log = log_stack.top();
                exec_time = new_log.ts - start_log.ts + 1;
                times[new_log.id] += exec_time;
                log_stack.pop();
                if(!log_stack.empty()) times[log_stack.top().id] -= exec_time;
            }
        }
        return times;
    }
};
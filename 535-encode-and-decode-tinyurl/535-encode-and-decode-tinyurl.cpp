class Solution {
private:
    map<string, string> url_mapping;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int len = longUrl.size();
        int idx = 0;
        string res("");
        int accumulator = 0;
        while(idx < len) {
            if(!((idx + 1) % 13)) {
                res += (char)((accumulator % 10) + '0');
                accumulator = 0;
            }
            else if((idx + 1) % 7 == 0) {
                res += (char)((accumulator % 26) + 'A');
                accumulator = 0;
            }
            else if((idx + 1) % 11 == 0) {
                res += (char)((accumulator % 26) + 'a');
                accumulator = 0;
            }
            accumulator += (int)longUrl[idx];
            idx++;
        }
        if(accumulator) {
            res += (char)((accumulator % 26) + 'a');
        }
        if(url_mapping.find(res) != url_mapping.end()) {
            res[0] = ( longUrl[len - 1] % 10) + '0';
            res[res.size() - 1] = ( longUrl[0] % 10) + '0';
        }
        url_mapping[res] = longUrl;
        cout<<res;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        stringstream in(shortUrl);
        string temp;
        string res("");
        while(getline(in, temp, '/')) {
            if(!(temp.compare("http:") && temp.compare("https:"))) continue;
            if(!(temp.compare("") && temp.compare("tinyurl.com") )) continue;
            if(url_mapping.find(temp) != url_mapping.end()) res = url_mapping[temp];
        }
        return res;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int, vector<vector<int>>> dist_map;
        vector<int> distances;
        vector<vector<int>> res;
        int dist;
        if(k > points.size()) return points;
        for(auto& pt: points) {
            dist = (pt[0] * pt[0]) + (pt[1] * pt[1]); 
            if(dist_map.find(dist) == dist_map.end())
                dist_map[dist] = vector<vector<int>>();
            dist_map[dist].push_back(pt);
            distances.push_back(-1 * dist);
        }
        make_heap(distances.begin(), distances.end());
        int cur_dist;
        vector<vector<int>> close_pts;
        while(k--) {
            cur_dist = distances.front() * -1;
            res.push_back(dist_map[cur_dist].back());
            dist_map[cur_dist].pop_back();
            if(!dist_map[cur_dist].size()) {
                dist_map.erase(cur_dist);
                pop_heap(distances.begin(), distances.end());
                distances.pop_back();
            }
        }
        return res;
    }
};
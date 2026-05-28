class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> dist_pq;
        vector<vector<int>> result;
        for(int i = 0; i<points.size(); i++){
            int distance = pow(points[i][0], 2) + pow(points[i][1], 2);

            dist_pq.push({distance, points[i]}); 

            if(dist_pq.size()> k){
                dist_pq.pop();
            }
        }
        while( !dist_pq.empty()){
            auto pair_iter = dist_pq.top();
            result.push_back(pair_iter.second);

            dist_pq.pop();
        }
        return result;
    }
};

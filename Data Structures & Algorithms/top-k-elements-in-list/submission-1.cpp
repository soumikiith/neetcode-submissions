class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_list;

        for(int i=0;i<nums.size(); i++){
            if(freq_list.find(nums[i]) == freq_list.end()){
                freq_list[nums[i]] = 1;
            }
            else{
                freq_list[nums[i]]++;
            }
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto iter = freq_list.begin(); iter!=freq_list.end(); iter++){
            pq.push(iter->second);

            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> res;
        set<int>res_set;
        while(!pq.empty()){
            int elem = pq.top();
            for(auto iter = freq_list.begin(); iter!=freq_list.end(); iter++){
                if(elem == iter->second && res_set.find(iter->first) == res_set.end() ){
                    res.push_back(iter->first);
                    res_set.insert(iter->first);
                }
            }
            pq.pop();
        }

        return res;
    }
};

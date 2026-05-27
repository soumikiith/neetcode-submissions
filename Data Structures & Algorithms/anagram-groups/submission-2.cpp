class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<unordered_map<char, int>> freq_list;

        for(int i=0; i<strs.size(); i++){
            string s = strs[i];
            unordered_map<char, int> m;
            for(int j=0; j<s.length(); j++){
                if(m.find(s[j]) == m.end()){
                    m[s[j]] = 1;
                }
                else
                {                    m[s[j]]++;
                }
            }
            freq_list.push_back(m);
        }
        unordered_map<int, vector<string>> res_map;
        set<int> visited;
        for(int i = 0; i < freq_list.size(); i++){
            if(visited.find(i) != visited.end()){
                continue;
            }
            res_map[i] = {strs[i]};
            visited.insert(i);
            for(int j = i + 1; j < freq_list.size(); j++){
                if(freq_list[i] == freq_list[j]){
                    res_map[i].push_back(strs[j]);
                    visited.insert(j);
                }
            }
        }
        vector<vector<string>> result;
        for(auto iter = res_map.begin(); iter!=res_map.end(); iter++){
            result.push_back(iter->second);
        }
        return  result;
    }
};

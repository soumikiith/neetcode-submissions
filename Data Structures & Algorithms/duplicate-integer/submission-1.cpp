class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::map<int, bool> num_map;
        for(auto iter = nums.begin(); iter!=nums.end(); iter++)
        {
            if(num_map.find(*iter)==num_map.end())
            {
                num_map[*iter] = true;
            }
            else
            {
                return true;
            }

        }
        return false;
    }
};

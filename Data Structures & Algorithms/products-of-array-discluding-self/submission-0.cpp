class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int prod_z =1;
        unordered_set<int> zeros, negs;
        for(int i=0;i<nums.size(); i++){
            product = product * nums[i];
            if( nums[i] != 0 ){
                prod_z = prod_z * nums[i];
            }
            if(nums[i] == 0){
                zeros.insert(i);
            }
            else if(nums[i]< 0)
                negs.insert(i); 
        }
        vector<int> res;
        for(int i=0;i<nums.size(); i++){
            if(! zeros.empty()){
                if(zeros.find(i) != zeros.end()){
                    if(zeros.size() > 1)
                        res.push_back(0);
                    else
                        res.push_back(prod_z);
                }
                else{
                    res.push_back(0);
                }
            }
            else{
                res.push_back(product / nums[i]);
            }
        }
        return res;
    }
};

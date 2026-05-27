class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }
        unordered_set<char> set_char;
        int left = 0;
        int right = 0;
        int max_l = - pow(2, 31);
        while(right !=s.length() ){
            if( set_char.find(s[right]) != set_char.end() ){
                set_char.erase(s[left]);
                left++;
            }
            else{
                set_char.insert(s[right]);
                right++;
            }
            int length_l = right - left;
            if(length_l > max_l)
                max_l = length_l;
        }
        return max_l;
    }
};

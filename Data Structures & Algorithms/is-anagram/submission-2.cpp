class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        {
            return false;
        }
        else
        {
            std::vector<char> string_map;
            for(int i=0; i<s.length(); i++)
            {
                string_map.push_back(s[i]);
            }
            for(int i=0; i<t.length(); i++)
            {
                auto find_iter = std::find(string_map.begin(), string_map.end(), t[i]);
                if(find_iter == string_map.end())
                {
                    return false;
                }
                else
                {
                    string_map.erase(find_iter);
                }

            }
            if(string_map.size()==0)
                return true;
            else
                return false;
        }
    }
};

class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while(s.length()>0 && s.find(part) < s.length()){
            int idx = s.find(part);
            if(idx < s.length()){
                s.erase(idx, part.length());
            } else{
                break;
            }
        }
        return s;
    }
};
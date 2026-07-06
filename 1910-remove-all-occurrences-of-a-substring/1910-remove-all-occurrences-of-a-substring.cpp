class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while(true){
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
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> nge(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()){
                nge[i] = -1;
            } else{
                nge[i] = st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int x : nums1){
            int i=0;
            while(nums2[i] != x) i++;

            ans.push_back(nge[i]);
        }
        return ans;
    }
};
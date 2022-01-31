class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> res;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            
            while( nums[i]-1 != i and nums[i]!=nums[nums[i]-1])  // MAIN LOGIC OF SWAP SORT
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        
        
        for(int i=0;i<n;i++){
            if( nums[i] != i+1){
                res.push_back(nums[i]);
            }
        }
        
        for(auto a : nums) cout<< a << " ";
        cout<<endl;
        
        return res;
    }
};
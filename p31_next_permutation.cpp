class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int k = 0;
        int l = 0;
        bool flag = false;

        for(int i = 0;i<nums.size()-1;i++ )
        {
            if(nums[i]<nums[i+1])
            {
                k = i;
                flag = true;
            }

        }
        if(!flag){
            std::reverse(nums.begin(),nums.end());
            return;
        }


        for(int i = k+1;i<nums.size();i++ )
        {
            if(nums[k]<nums[i])
            {
                l = i;
            }

        }
        int temp = nums[k];
        nums[k] = nums[l];
        nums[l] = temp;

        std::reverse(nums.begin()+k+1, nums.end());


    }
};

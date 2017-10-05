class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        int curr;
        int begin = 1;
        int count = 1;
        for (int i=1; i<nums.size(); i++)
        {
            curr = nums[i-1];
            if(nums[i] != curr)
            {
                nums[begin++] = nums[i];
                count++;
            }
        }
        return count;

    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() > k) {
            int arrnew[nums.size()];
            for (int i = 0; i < k; i++) {
                arrnew[i] = nums[nums.size() - k + i];
            }
            for (int i = 0; i < nums.size() - k; i++) {
                arrnew[i + k] = nums[i];
            }
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = arrnew[i];
            }
        } else if (nums.size() >1 && nums.size() < k) {
            for (int i = 0; i < k; i++){
                int tmp = nums[(nums.size()-1)];
                for (int j = nums.size()-2; j>=0; j--){
                    nums[j+1]=nums[j];
                }
                nums[0]=tmp;
            }
        }
    }
};

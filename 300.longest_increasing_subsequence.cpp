class Solution {
  public:
    int lengthOfLIS (vector<int>nums) {
      int len = nums.size();
      vector<int>opt;
      opt.reserve(len);

      for (int i = 0; i < n; i++) {
      }
    };
};

/*
 *
class Solution:
  def lengthOfLIS(self, nums: List[int]) -> int:
      opt = []
      for i, num in enumerate(nums):
          le = [opt[j] for j in range(i) if nums[j] < num]
          curr = max(le) + 1 if len(le) > 0 else 1
          opt.append(curr)
      return max(opt)
*/

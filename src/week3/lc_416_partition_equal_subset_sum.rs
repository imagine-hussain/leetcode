use crate::Solution;


impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let sum: i32 = nums.iter().sum();
        if sum % 2 == 1 {
            return false;
        }
        let goal = (sum / 2) as usize;
        init_dp(&nums, goal)[nums.len()][goal]
    }
}

fn init_dp(nums: &[i32], goal: usize) -> Vec<Vec<bool>> {
    let mut dp: Vec<Vec<bool>> = vec![vec![false; (goal + 1) as usize]; nums.len() + 1];
    dp[0][0] = true;
    for i in 1..dp.len() {
        let val = nums[i - 1];
        for j in 0..dp[i].len() {
            let without_val = dp[i - 1][j];
            let with_val = match j < val as usize {
                true => false,
                false => dp[i - 1][j - val as usize],
            };
            dp[i][j] = with_val || without_val;
        }
    }
    dp
}


use crate::Solution;

impl Solution {
    pub fn combination_sum4(nums: Vec<i32>, target: i32) -> i32 {
        let mut dp: Vec<u32> = vec![0; target as usize + 1];
        nums.iter()
            .filter(|i| **i <= target)
            .for_each(|i| dp[*i as usize] += 1);

        for i in 0..=target {
            dp[i as usize] += nums
                .iter()
                .filter(|num| i - *num >= 0)
                .fold(0, |subtotal, num| subtotal + dp[(i - num) as usize]);
        }

        dp[target as usize] as i32
    }
}

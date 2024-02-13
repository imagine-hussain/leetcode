use crate::Solution;

impl Solution {
    pub fn min_operations(nums: Vec<i32>, nums_divide: Vec<i32>) -> i32 {
        nums.sort();
        let gcd = nums_divide.iter()
            .fold(nums_divide[0], |a, b| std::num::integer::gcd(a, b));




        todo!()
    }
}

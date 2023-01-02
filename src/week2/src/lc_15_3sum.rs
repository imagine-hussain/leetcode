use crate::Solution;

use std::{cmp, collections::HashSet};

// enum Option {
//     None,
//     Some(___)
// }

impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut solutions: HashSet<(i32, i32, i32)> = HashSet::new();
        nums.sort();

        for i in 0..nums.len() - 1 {
            two_sum(&nums[i..], &mut solutions);
        }

        let mut x = String::from("hi");
        print_str(&mut x);
        print_str(&mut x);

        solutions
            .into_iter()
            .map(|(a, b, c)| vec![a, b, c])
            .collect()
    }
}

fn print_str(s: &mut str) {
    println!("{}", s);
    s.make_ascii_uppercase();
}

pub fn two_sum(nums: &[i32], solutions: &mut HashSet<(i32, i32, i32)>) {
    if nums.len() < 3 {
        return;
    }

    let target = -nums[0];
    let mut lo = 1;
    let mut hi = nums.len() - 1;

    while hi > lo {
        match (nums[hi] + nums[lo]).cmp(&target) {
            cmp::Ordering::Equal => {
                checked_solution_insertion(nums[lo], nums[hi], -target, solutions);
                if nums[lo] == nums[lo + 1] {
                    lo += 1;
                } else {
                    hi -= 1;
                }
            }
            cmp::Ordering::Less => lo += 1,
            cmp::Ordering::Greater => hi -= 1,
        };
    }
}

fn checked_solution_insertion(a: i32, b: i32, c: i32, solutions: &mut HashSet<(i32, i32, i32)>) {
    let already_exists = vec![
        (a, b, c),
        (a, c, b),
        (b, a, c),
        (b, c, a),
        (c, a, b),
        (c, b, a),
    ]
    .into_iter()
    .any(|perm| solutions.contains(&perm));

    if !already_exists {
        solutions.insert((a, b, c));
    };
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1() {
        let nums = vec![-1, 0, 1, 2, -1, -4];
        let expected = vec![vec![-1, -1, 2], vec![-1, 0, 1]];
        let actual = Solution::three_sum(nums);
        assert_eq!(expected, actual);
    }
}

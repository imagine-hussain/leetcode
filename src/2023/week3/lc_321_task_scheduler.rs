use crate::Solution;

use std::{collections::HashMap, cmp::max};

impl Solution {
    pub fn least_interval(tasks: Vec<char>, n: i32) -> i32 {
        let items_by_freq = sort_tasks_by_freq(&tasks);
        let max_item_count = items_by_freq[0].1;
        let idle_time = (max_item_count - 1) * (n + 1) as usize;
        let mut total_time =  max_item_count + idle_time;

        'dup_freq: for (_, freq) in &items_by_freq[1..] {
            if *freq == max_item_count {
                total_time += 1;
            }
        }

        max(tasks.len() as i32, total_time as i32)
    }
}

fn sort_tasks_by_freq(tasks: &[char]) -> Vec<(char, usize)> {
    let mut map: HashMap<char, usize> = HashMap::new();

    for task in tasks {
        let count = map.get(task).unwrap_or(&0_usize) + 1;
        map.insert(*task, count);
    }

    let mut output: Vec<(char, usize)> = map.into_iter().collect();
    output.sort_by(|(_, a), (_, b)| {
        a.cmp(b)
    });

    output
}





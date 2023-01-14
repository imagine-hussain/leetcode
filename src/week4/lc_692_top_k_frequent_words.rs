use crate::Solution;

use std::{cmp::Ordering, collections::HashMap};

impl Solution {
    pub fn top_k_frequent(words: Vec<String>, k: i32) -> Vec<String> {
        let mut counts: HashMap<&String, usize> = HashMap::new();

        for word in &words {
            counts.insert(word, counts.get(word).unwrap_or(&0) + 1);
        }

        let mut count_vec: Vec<(&String, usize)> = counts.into_iter().map(|e| (e.0, e.1)).collect();

        count_vec.sort_by(|a, b| {
            match a.1.cmp(&b.1) {
                Ordering::Less => Ordering::Greater,
                Ordering::Greater => Ordering::Less,
                Ordering::Equal => match a.0.cmp(b.0) {
                    Ordering::Less => Ordering::Less,
                    Ordering::Greater => Ordering::Greater,
                 Ordering::Equal => Ordering::Equal,
                },
            }
        });

        count_vec[0..k as usize].into_iter().map(|(word, count)| word.to_string()).collect()
    }
}


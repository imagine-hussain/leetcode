use crate::Solution;

use std::{vec::Vec, collections::HashSet};


impl Solution {
    pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
        let hset: HashSet<String> = vec_to_hash(word_dict);
        let dp = init_graph(&s, &hset);

        dfs(&dp)
    }

}

fn dfs(dp: &Vec<Vec<bool>>) -> bool {
    let mut visited: Vec<bool> = vec![false; dp.len() + 1];
    visit(dp, &mut visited, 0);
    visited[dp.len()]
}

fn visit(dp: &Vec<Vec<bool>>, visited: &mut Vec<bool>, curr: usize) {

    match visited.get(curr).unwrap_or(&false) {
        true => return,
        false => visited[curr] = true,
    }

    if curr == visited.len() - 1 {
        return;
    }

    for i in 0..(visited.len() - 1) {
        if dp[curr][i] {
            visit(dp, visited, i+ 1);
        }
    }
}

fn init_graph(s: &str, hset: &HashSet<String>) -> Vec<Vec<bool>> {
    let n = s.len();
    let mut dp: Vec<Vec<bool>> = vec![vec![false; n]; n];

    for i in 0..n {
        for j in i..n {
            dp[i][j] = hset.contains(&s[i..=j]);
        }
    }

    dp
}

fn vec_to_hash(word_dict: Vec<String>) -> HashSet<String> {
    let mut hset: HashSet<String> = HashSet::new();

    for word in word_dict {
        hset.insert(word);
    }

    hset
}


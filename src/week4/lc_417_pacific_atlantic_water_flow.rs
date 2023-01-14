
use std::collections::VecDeque;

use crate::Solution;

impl Solution {
    pub fn pacific_atlantic(heights: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let from_pac: Vec<Vec<bool>> = vec![vec![false; heights[0].len()]; heights.len()];
        let from_atl: Vec<Vec<bool>> = vec![vec![false; heights[0].len()]; heights.len()];

        fill_pac(&heights, &mut from_pac);
        fill_atl(&heights, &mut from_atl);

        let res: Vec<Vec<i32>> = Vec::new();

        for row in 0..heights.len() {
            for col in 0..heights[0].len() {
                if from_pac[row][col] && from_atl[row][col] {
                    res.push(vec![row as i32, col as i32]);
                }
            }
        }

        res
    }
}


fn fill_pac(heights: &Vec<Vec<i32>>, visited: &mut Vec<Vec<bool>>) {
    let q: VecDeque<(usize, usize)> = VecDeque::new();

    // Fill border
    for col in 0..heights[0].len() {
        q.push_back((0, col))
    }
    for row in 0..heights.len() {
        q.push_back((row, 0))
    }

    dfs(heights, visited, q);
}

fn fill_atl(heights: &Vec<Vec<i32>>, visited: &mut Vec<Vec<bool>>) {
    let q: VecDeque<(usize, usize)> = VecDeque::new();

    // Fill border
    for col in 0..heights[0].len() {
        q.push_back((heights[0].len() - 1, col))
    }
    for row in 0..heights.len() {
        q.push_back((row, heights.len() - 1))
    }

    dfs(heights, visited, q);
}

fn dfs(heights: &Vec<Vec<i32>>, visited: &Vec<Vec<bool>>, q: VecDeque<(usize, usize)>) {
    while !q.is_empty() {
        let curr = q.pop_back().unwrap();

        let (row, col) = curr;

        if visited[row][col] {
            continue;
        }

        get_neighbours(curr, heights).iter().for_each(|(y, x)| {
            if !visited[*y][*x] && (heights[*y][*x] >= heights[row][col]) {
                q.push_back((*y, *x))
            }
        });

        visited[row][col] = true;
    }
}

fn get_neighbours<T>(point: (usize, usize), grid: &Vec<Vec<T>>) -> Vec<(usize, usize)> {
    let (row, col) = point;
    let res: Vec<(usize, usize)> = Vec::new();

    if row != 0 {
        res.push((row - 1, col))
    }
    if col != 0 {
        res.push((row - 1, col))
    }

    if row != grid.len() {
        res.push((row + 1, col))
    }
    if col != grid[0].len() {
        res.push((row, col + 1))
    }

    res
}



use crate::Solution;

use std::{collections::VecDeque, vec::Vec};

impl Solution {
    pub fn oranges_rotting(mut grid: Vec<Vec<i32>>) -> i32 {
        let mut q: VecDeque<(i32, i32)> = VecDeque::new();

        let mut next_left = q_initial(&mut grid, &mut q);

        let mut day = 0;

        while !q.is_empty() {
            day += 1;
            let curr_left = next_left;
            next_left = 0;
            for _ in 0..curr_left {
                let (i, j) = q.pop_front().expect("queue is not empty");
                next_left += q_neighbours(&mut grid, &mut q, i as usize, j as usize);
            }
        }

        day
    }
}

fn q_initial(grid: &mut Vec<Vec<i32>>, q: &mut VecDeque<(i32, i32)>) -> i32 {
    let mut found = 0;

    for i in 0..grid.len() {
        for j in 0..grid[i].len() {
            if grid[i][j] == 2 {
                found += q_neighbours(grid, q, i, j)
            }
        }
    }

    found
}

fn q_neighbours(grid: &mut [Vec<i32>], q: &mut VecDeque<(i32, i32)>, i: usize, j: usize) -> i32 {
    vec![
        (i as i32 - 1, j as i32),
        (i as i32 + 1, j as i32),
        (i as i32, j as i32 - 1),
        (i as i32, j as i32 + 1),
    ]
    .into_iter()
    .map(|(i, j)| {
        if !in_bounds(grid, i, j) {
            return 0;
        }

        let cell = &mut grid[i as usize][j as usize];
        if *cell == 1 {
            *cell = 2;
            q.push_back((i, j));
            return 1;
        }
        0
    })
    .sum()
}

fn in_bounds(grid: &[Vec<i32>], i: i32, j: i32) -> bool {
    i >= 0 && i < grid.len() as i32 && j >= 0 && j < grid[0].len() as i32
}

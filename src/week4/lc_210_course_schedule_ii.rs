use crate::Solution;

use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn can_finish(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> Vec<i32> {
        let (mut graph_incoming, graph_outgoing) =
            initialise_graphs(num_courses as usize, &prerequisites);

        let mut queue = intialise_initial_queue(&graph_incoming);
        let mut visited: Vec<Option<i32>> = vec![None; num_courses as usize];

        while !queue.is_empty() {
            let curr = queue.pop_front().expect("Checked non-empty queue");


            graph_outgoing[curr as usize].iter().for_each(|unlocked| {
                let target = &mut graph_incoming[*unlocked as usize];
                if target.remove(&curr) && target.is_empty() {
                    queue.push_front(*unlocked);
                    match visited[curr as usize] {
                        Some(_) => return,
                        None => visited[*unlocked as usize] = Some(curr),
                    }
                }
            });
        }

        if visited.iter().any(|x| x.is_none()) {
            return vec![];
        }

        let preds: Vec<i32> = Vec::new();


        // pred
    }
}

type Edges<T> = Vec<HashSet<T>>;

fn initialise_graphs(num_vertices: usize, raw_edges: &Vec<Vec<i32>>) -> (Edges<i32>, Edges<i32>) {

    let mut graph_incoming: Vec<HashSet<i32>> = Vec::new();
    let mut graph_outgoing: Vec<HashSet<i32>> = Vec::new();

    for _ in 0..num_vertices {
        graph_incoming.push(HashSet::new());
        graph_outgoing.push(HashSet::new());
    }

    // Init graphs
    for edge in raw_edges {
        graph_incoming[edge[1] as usize].insert(edge[0]);
        graph_outgoing[edge[0] as usize].insert(edge[1]);
    }

    (graph_incoming, graph_outgoing)
}

fn intialise_initial_queue(graph_incoming: &[HashSet<i32>]) -> VecDeque<i32> {
    graph_incoming
        .iter()
        .enumerate()
        .filter_map(|(i, incoming_set)| {
            match incoming_set.is_empty() {
                true => Some(i as i32),
                false => None
            }
        })
        .collect::<VecDeque<i32>>()
}

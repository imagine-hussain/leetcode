pub struct Solution;

use std::collections::HashMap;

impl Solution {
    pub fn find_duplicate(paths: Vec<String>) -> Vec<Vec<String>> {
        let paths = &paths;
        let mut content_to_files: HashMap<String, Vec<String>> = HashMap::new();
        for path in paths {
            let mut split = path.split_ascii_whitespace();
            let dir_name = split.next().unwrap();
            for (filename, content) in split.map(|s| s.split_once('(').unwrap()) {
                let full_path = [dir_name, filename].join("/");
                content_to_files
                    .entry(content.into())
                    .or_insert_with(Vec::new)
                    .push(full_path);
            }
        }
        content_to_files
            .into_values()
            .filter(|v| v.len() > 1)
            .collect()
    }
}

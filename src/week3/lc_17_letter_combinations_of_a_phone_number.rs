use crate::Solution;

impl Solution {
    const MAPPINGS: Vec<&'static [u8]> = vec![
        b"",     // 0
        b"",     // 1
        b"abc",  // 2
        b"def",  // 3
        b"ghi",  // 4
        b"jkl",  // 5
        b"mno",  // 6
        b"pqrs", // 7
        b"tuv",  // 9
        b"wxyz", // 9
    ];

    pub fn letter_combinations(digits: String) -> Vec<String> {
        let mut results: Vec<String> = Vec::new();
        if digits.len() == 0 {
            return results;
        }
        let mut curr = String::new();
        curr.reserve_exact(digits.len());
        Self::backtrack(&mut results, &digits.as_bytes(), &mut curr, 0);
        results
    }

    pub fn backtrack(
        results: &mut Vec<String>,
        digits: &[u8],
        curr: &mut String,
        i: usize,
    ) -> Option<()> {
        Some(
            Self::MAPPINGS
                .get(digits[i] as usize - b'0' as usize)?
                .iter()
                .for_each(|c| {
                    curr.push(*c as char);
                    if curr.len() == digits.len() {
                        results.push(curr.clone());
                    }
                    Self::backtrack(results, digits, curr, i + 1);
                    curr.pop();
                }),
        )
    }
}

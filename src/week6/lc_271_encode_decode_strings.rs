
struct Codec {}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Codec {
    fn new() -> Self {
        Self {}
    }

    fn encode(&self, strs: Vec<String>) -> String {
        let total_lens: usize = strs.iter().map(|s| s.len()).sum();
        let mut out = String::with_capacity(total_lens);
        strs.iter().for_each(|s| {
            out.push(s.len() as u8 as char);
            out.push_str(s);
        });
        out
    }

    fn decode(&self, s: String) -> Vec<String> {
        let mut out = Vec::new();
        let s = s.as_bytes();
        let mut idx: usize = 0;
        while idx < s.len() {
            let len = s[idx] as u8 as usize;
            let curr = String::from_utf8(Vec::from(&s[idx + 1..idx + 1 + len])).unwrap();
            out.push(curr);
            idx += len + 1;
        }
        out
    }
}

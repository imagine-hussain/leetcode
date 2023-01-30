struct Entry {
    timestamp: i32,
    count: u32,
}

impl Entry {
    fn new(timestamp: i32) -> Self {
        Self {
            timestamp,
            count: 1,
        }
    }
}

struct HitCounter {
    list: Vec<Entry>, // ts, count
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl HitCounter {
    fn new() -> Self {
        Self {
            list: Vec::default(),
        }
    }

    fn hit(&mut self, timestamp: i32) {
        let needs_push = self
            .list
            .last()
            .map_or_else(|| true, |last| last.timestamp != timestamp);
        match needs_push {
            true => self.list.push(Entry::new(timestamp)),
            false => {
                self.list.last_mut().map(|elem| elem.count += 1);
            }
        }
    }

    fn get_hits(&self, timestamp: i32) -> i32 {


        // bsearch for first thingy less than or equal to thingy

        todo!()
    }
}

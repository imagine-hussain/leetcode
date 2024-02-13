#include <iterator>
#include <unordered_map>

using namespace std;

class LruNode {
public:
    LruNode* prev;
    LruNode* next;
    int key;
    int value;

    LruNode(int key, int value) {
        this->key = key;
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }

};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
        this->nodemap = unordered_map<int, LruNode*>();
    }

    int get(int key) {
        return this->nodemap[key]->value;
    }

    void put(int key, int value) {
        auto searched_iter = this->nodemap.find(key);
        LruNode* node;
        if (searched_iter == this->nodemap.end()) {
            if (this->capacity == this->size)
                evict_lru();
            else
                this->size++;
            node = new LruNode(key, value);
        } else {
            node = searched_iter->second;
        }
        extract_node(node);
        insert_head(node);
    }

    inline void insert_head(LruNode* node) {
        if (this->head == nullptr) {
            this->head = node;
            this->tail = node;
            return;
        }

        this->head->prev = node;
        node->next = head;
        node->prev = nullptr;
    }

    void extract_node(LruNode* node) {
        if (node == nullptr) return;
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }
        if (node->next != nullptr) {
            node->next->prev = node->next;
        }
    }

    void evict_lru() {
        if (this->size == 0)
            return;

        int key = this->tail->key;
        this->nodemap.erase(key);

        if (this->size == 1) {
            delete this->tail;
            this->head = nullptr;
            this->tail = nullptr;
        }
        this->tail = this->tail->prev;
    }


private:
    int capacity;
    int size;
    LruNode* head;
    LruNode* tail;
    unordered_map<int, LruNode*> nodemap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

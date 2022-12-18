#include <string>
#include <vector>

using namespace std;

class Trie {
    vector<Trie *> children;
    bool isTerminating;

public:
    Trie() {
        // Vector<Trie*> children(26, nullptr);
        for (int i = 0; i < 26; i++) children.push_back(nullptr);
        this->isTerminating = false;
    }

    void insert(string word) {
        Trie* curr = this;
        for (auto c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new Trie();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isTerminating = true;
    }

    bool search(string word) {
        Trie* curr = this;
        for (auto c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return curr->isTerminating;
    }

    bool startsWith(string prefix) {
        Trie* curr = this;
        for (auto c : prefix) {
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

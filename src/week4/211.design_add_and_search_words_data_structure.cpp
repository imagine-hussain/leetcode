#include <iostream>

using namespace std;

class TrieNode {
public:
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        is_word = false;
    }

    bool has_word(string word) {
        return do_has_word(word, 0);
    }

    void insert_word(string word) {
        TrieNode* curr = this;
        for (auto letter : word) {
            if (curr->children[letter - 'a'] == nullptr)
                curr->children[letter - 'a'] = new TrieNode();

            curr = children[letter - 'a'];
        }
        curr->is_word = true;
    }
    bool is_word;
    TrieNode* children[26];

    bool do_has_word(string word, int i) {
        if (i == word.length() - 1) return this->is_word;

        int c = word[i];
        if (c <= 'z' && c >= 'a') {
            TrieNode* next = this->children[c - 'a'];
            if (next == nullptr)
                return false;
            return next->do_has_word(word, i + 1);
        }

        for (auto node : this->children) {
            if (node == nullptr)
                continue;
            if (node->do_has_word(word, i + 1))
                return true;
        }

        return false;
    }

};

class WordDictionary {
public:
    WordDictionary() {
        this->dict_head = new TrieNode();
    }
    
    void addWord(string word) {
        this->dict_head->insert_word(word);
    }
    
    bool search(string word) {
        return this->dict_head->do_has_word(word, 0);
    }
private:
    TrieNode *dict_head;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

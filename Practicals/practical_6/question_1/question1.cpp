#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
        cout << "Inserted: " << word << endl;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
    
    // ========================================================================
    // DELETE OPERATION
    // Time Complexity: O(m) where m is the length of the word
    // Space Complexity: O(1)
    bool deleteWord(string word) {
        return deleteHelper(root, word, 0);
    }
    
    bool deleteHelper(TrieNode* curr, string word, int idx) {
        if (idx == word.length()) {
            if (!curr->isEndOfWord) return false;
            curr->isEndOfWord = false;
            return curr->children.empty();
        }
        
        char c = word[idx];
        if (curr->children.find(c) == curr->children.end()) return false;
        
        TrieNode* child = curr->children[c];
        bool shouldDelete = deleteHelper(child, word, idx + 1);
        
        if (shouldDelete) {
            curr->children.erase(c);
            return curr->children.empty() && !curr->isEndOfWord;
        }
        return false;
    }
};

int main() {
    Trie trie;
    
    cout << "=== TRIE DEMONSTRATION ===" << endl << endl;
    
    // Insert words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");
    trie.insert("banana");
    trie.insert("band");
    
    cout << "\nSearch Tests:" << endl;
    cout << "apple: " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "app: " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "appl: " << (trie.search("appl") ? "Found" : "Not Found") << endl;
    cout << "xyz: " << (trie.search("xyz") ? "Found" : "Not Found") << endl;
    
    cout << "\nPrefix Tests:" << endl;
    cout << "Prefix 'ap': " << (trie.startsWith("ap") ? "Exists" : "Not Found") << endl;
    cout << "Prefix 'ba': " << (trie.startsWith("ba") ? "Exists" : "Not Found") << endl;
    cout << "Prefix 'xy': " << (trie.startsWith("xy") ? "Exists" : "Not Found") << endl;
    
    return 0;
}

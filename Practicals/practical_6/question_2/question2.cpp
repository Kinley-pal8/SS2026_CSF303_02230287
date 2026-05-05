#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// ============================================================================
// PATRICIA TRIE TREE - SIMPLIFIED RADIX TREE VERSION
// ============================================================================
// PATRICIA = Practical Algorithm to Retrieve Information Coded in Alphanumeric
// 
// This is a simplified version that acts like a radix tree.
// Each edge has a string label, making it more space-efficient than a standard trie.
// ============================================================================

struct RadixNode {
    unordered_map<char, RadixNode*> children;
    string edgeLabel;      // Label on the incoming edge
    string value;          // The stored word
    bool isWord;           // Is this node a complete word?
    
    RadixNode() : isWord(false) {}
};

class PatriciaTree {
private:
    RadixNode* root;
    
public:
    PatriciaTree() {
        root = new RadixNode();
    }
    
    // ========================================================================
    // INSERT OPERATION
    // Time Complexity: O(m log n) where m = word length, n = word count
    // Space Complexity: O(m)
    // ========================================================================
    void insert(const string& word) {
        if (word.empty()) return;
        
        RadixNode* current = root;
        int pos = 0;
        
        while (pos < word.length()) {
            char firstChar = word[pos];
            
            if (current->children.find(firstChar) == current->children.end()) {
                // No matching edge, create new node
                RadixNode* newNode = new RadixNode();
                newNode->edgeLabel = word.substr(pos);
                newNode->value = word;
                newNode->isWord = true;
                current->children[firstChar] = newNode;
                
                cout << "✓ Inserted: \"" << word << "\"" << endl;
                return;
            }
            
            RadixNode* child = current->children[firstChar];
            const string& edgeLabel = child->edgeLabel;
            const string remaining = word.substr(pos);
            
            // Find common prefix length
            int commonLen = 0;
            for (int i = 0; i < min(edgeLabel.length(), remaining.length()); i++) {
                if (edgeLabel[i] == remaining[i]) {
                    commonLen++;
                } else {
                    break;
                }
            }
            
            if (commonLen == 0) {
                // No match, continue searching
                pos++;
                continue;
            }
            
            if (commonLen == edgeLabel.length() && commonLen == remaining.length()) {
                // Exact match - word already exists
                if (!child->isWord) {
                    child->value = word;
                    child->isWord = true;
                    cout << "✓ Inserted: \"" << word << "\"" << endl;
                }
                return;
            }
            
            if (commonLen == edgeLabel.length()) {
                // Edge label is fully matched, continue
                pos += commonLen;
                current = child;
                continue;
            }
            
            if (commonLen == remaining.length()) {
                // Remaining word is a prefix of edge label - split edge
                RadixNode* newNode = new RadixNode();
                newNode->edgeLabel = "";
                newNode->value = word;
                newNode->isWord = true;
                
                // Create node for the rest of old edge
                RadixNode* suffixNode = new RadixNode();
                suffixNode->edgeLabel = edgeLabel.substr(commonLen);
                suffixNode->value = child->value;
                suffixNode->isWord = child->isWord;
                suffixNode->children = child->children;
                
                newNode->children[suffixNode->edgeLabel[0]] = suffixNode;
                child->edgeLabel = remaining;
                child->value = word;
                child->isWord = true;
                
                cout << "✓ Inserted: \"" << word << "\" (split edge)" << endl;
                return;
            }
            
            // Partial match - split edge
            RadixNode* commonNode = new RadixNode();
            commonNode->edgeLabel = edgeLabel.substr(0, commonLen);
            commonNode->isWord = false;
            
            RadixNode* suffixNode = child;
            suffixNode->edgeLabel = edgeLabel.substr(commonLen);
            
            RadixNode* newWord = new RadixNode();
            newWord->edgeLabel = remaining.substr(commonLen);
            newWord->value = word;
            newWord->isWord = true;
            
            commonNode->children[suffixNode->edgeLabel[0]] = suffixNode;
            commonNode->children[newWord->edgeLabel[0]] = newWord;
            
            current->children[firstChar] = commonNode;
            
            cout << "✓ Inserted: \"" << word << "\" (complex split)" << endl;
            return;
        }
    }
    
    // ========================================================================
    // SEARCH OPERATION
    // Time Complexity: O(m) where m = word length
    // ========================================================================
    bool search(const string& word) {
        if (word.empty()) return false;
        
        RadixNode* current = root;
        int pos = 0;
        
        while (pos < word.length()) {
            char firstChar = word[pos];
            
            if (current->children.find(firstChar) == current->children.end()) {
                return false;
            }
            
            RadixNode* child = current->children[firstChar];
            const string& edgeLabel = child->edgeLabel;
            const string remaining = word.substr(pos);
            
            // Check if remaining matches edge label
            if (remaining.length() < edgeLabel.length()) {
                return false;
            }
            
            if (remaining.substr(0, edgeLabel.length()) != edgeLabel) {
                return false;
            }
            
            if (remaining.length() == edgeLabel.length()) {
                // Exact match
                return child->isWord && child->value == word;
            }
            
            pos += edgeLabel.length();
            current = child;
        }
        
        return false;
    }
    
    // ========================================================================
    // DELETE OPERATION
    // Time Complexity: O(m) where m = word length
    // ========================================================================
    bool deleteWord(const string& word) {
        if (!search(word)) return false;
        
        RadixNode* current = root;
        int pos = 0;
        
        while (pos < word.length()) {
            char firstChar = word[pos];
            RadixNode* child = current->children[firstChar];
            const string& edgeLabel = child->edgeLabel;
            const string remaining = word.substr(pos);
            
            if (remaining.length() == edgeLabel.length()) {
                // Found the node to delete
                child->isWord = false;
                return true;
            }
            
            pos += edgeLabel.length();
            current = child;
        }
        
        return false;
    }
    
    // Display all words
    void displayAll() {
        cout << "\n--- All Words in PATRICIA Tree ---" << endl;
        if (root->children.empty()) {
            cout << "(empty)" << endl;
            return;
        }
        displayHelper(root);
    }
    
    void displayHelper(RadixNode* node) {
        if (node->isWord) {
            cout << node->value << " (edge: \"" << node->edgeLabel << "\")" << endl;
        }
        
        for (auto& pair : node->children) {
            displayHelper(pair.second);
        }
    }
};

// ============================================================================
// MAIN FUNCTION - DEMONSTRATION
// ============================================================================
int main() {
    cout << "========================================" << endl;
    cout << "   PATRICIA TREE IMPLEMENTATION" << endl;
    cout << "========================================" << endl;
    
    PatriciaTree patricia;
    
    // ====== INSERT OPERATIONS ======
    cout << "\n1. INSERT OPERATIONS:" << endl;
    cout << "------------------------" << endl;
    patricia.insert("apple");
    patricia.insert("app");
    patricia.insert("application");
    patricia.insert("apply");
    patricia.insert("banana");
    patricia.insert("band");
    patricia.insert("can");
    patricia.insert("cat");
    patricia.insert("catch");
    
    patricia.displayAll();
    
    // ====== SEARCH OPERATIONS ======
    cout << "\n2. SEARCH OPERATIONS:" << endl;
    cout << "------------------------" << endl;
    
    cout << "Search 'apple': " << (patricia.search("apple") ? "Found ✓" : "Not Found ✗") << endl;
    cout << "Search 'app': " << (patricia.search("app") ? "Found ✓" : "Not Found ✗") << endl;
    cout << "Search 'application': " << (patricia.search("application") ? "Found ✓" : "Not Found ✗") << endl;
    cout << "Search 'appl': " << (patricia.search("appl") ? "Found ✓" : "Not Found ✗") << endl;
    cout << "Search 'banana': " << (patricia.search("banana") ? "Found ✓" : "Not Found ✗") << endl;
    cout << "Search 'xyz': " << (patricia.search("xyz") ? "Found ✓" : "Not Found ✗") << endl;
    cout << "Search 'cat': " << (patricia.search("cat") ? "Found ✓" : "Not Found ✗") << endl;
    cout << "Search 'catch': " << (patricia.search("catch") ? "Found ✓" : "Not Found ✗") << endl;
    
    // ====== DELETE OPERATIONS ======
    cout << "\n3. DELETE OPERATIONS:" << endl;
    cout << "------------------------" << endl;
    
    cout << "Delete 'app': " << (patricia.deleteWord("app") ? "Deleted ✓" : "Not Found ✗") << endl;
    cout << "Delete 'application': " << (patricia.deleteWord("application") ? "Deleted ✓" : "Not Found ✗") << endl;
    cout << "Delete 'band': " << (patricia.deleteWord("band") ? "Deleted ✓" : "Not Found ✗") << endl;
    cout << "Delete 'xyz': " << (patricia.deleteWord("xyz") ? "Deleted ✓" : "Not Found ✗") << endl;
    
    // Display remaining words
    cout << "\n4. WORDS AFTER DELETION:" << endl;
    cout << "------------------------" << endl;
    patricia.displayAll();
    
    // ====== VERIFICATION ======
    cout << "\n5. VERIFICATION:" << endl;
    cout << "------------------------" << endl;
    cout << "Search 'app': " << (patricia.search("app") ? "Found ✓" : "Not Found ✗") << endl;
    cout << "Search 'apple': " << (patricia.search("apple") ? "Found ✓" : "Not Found ✗") << endl;
    cout << "Search 'banana': " << (patricia.search("banana") ? "Found ✓" : "Not Found ✗") << endl;
    cout << "Search 'cat': " << (patricia.search("cat") ? "Found ✓" : "Not Found ✗") << endl;
    
    cout << "\n========================================" << endl;
    cout << "   END OF PATRICIA TREE DEMONSTRATION" << endl;
    cout << "========================================" << endl;
    
    return 0;
}

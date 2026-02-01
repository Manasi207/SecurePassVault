#ifndef TRIE_H
#define TRIE_H

#include <map>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    map<char, TrieNode*> child;
    bool isEnd;

    TrieNode() { isEnd = false; }
};

class Trie {
    TrieNode* root;
    void collect(TrieNode*, string, vector<string>&);

public:
    Trie();
    void insert(string word);
    vector<string> autocomplete(string prefix);
};

#endif

#include "Trie.h"

Trie::Trie()
{
    root = new TrieNode();
}

void Trie::insert(string word)
{
    TrieNode *cur = root;

    for (char c : word)
    {
        if (!cur->child[c])
            cur->child[c] = new TrieNode();

        cur = cur->child[c];
    }
    cur->isEnd = true;
}

void Trie::collect(TrieNode *node, string pre,
                   vector<string> &res)
{
    if (node->isEnd)
        res.push_back(pre);

    for (auto &p : node->child)
        collect(p.second, pre + p.first, res);
}

vector<string> Trie::autocomplete(string prefix)
{
    TrieNode *cur = root;

    for (char c : prefix)
    {
        if (!cur->child[c])
            return {};
        cur = cur->child[c];
    }

    vector<string> res;
    collect(cur, prefix, res);
    return res;
}

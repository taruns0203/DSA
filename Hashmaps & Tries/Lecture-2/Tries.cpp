#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char d)
    {
        this->data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertWord(TrieNode *root, string word)
{
    cout << "Word is. " << word << endl;
    // base case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';

    TrieNode *child;
    // present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // not present
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursion sambhal lega
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    // present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return false;
    }

    // rec call
    return searchWord(child, word.substr(1));
}

int main()
{
    TrieNode *root = new TrieNode('-');

    insertWord(root, "coding");
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "codehelp");
    insertWord(root, "baba");
    insertWord(root, "baby");
    insertWord(root, "babu");
    insertWord(root, "shona");

    if (searchWord(root, "coding"))
    {
        cout << "present" << endl;
    }
    else
    {
        cout << "absent " << endl;
    }

    return 0;
}
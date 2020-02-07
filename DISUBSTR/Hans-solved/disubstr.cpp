#include <iostream>

using namespace std;

struct TrieNode
{
    TrieNode * child[26];
    int count;
    bool isWord;
    TrieNode()
    {
        for(int i = 0; i < 26; i++)
			child[i] = NULL;
        count = 0;
        isWord = false;
    }
};

struct Tree
{
    TrieNode * root;
    int count;

    Tree()
    {
        root = new TrieNode;
    }

    void add(char * s)
    {
        TrieNode * t = root;
        for(int i = 0; s[i]; i++)
        {
            int m = s[i]-'A';

            if(!t->child[m])
            {
                count++;
                t->child[m] = new TrieNode;
            }
            t = t->child[m];
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n;
    Tree * t;
    cin >> n;
    while(n--)
    {
        t = new Tree;
        char s[1002];
        cin >> s;
        for(int i = 0; s[i]; i++)
            t->add(s+i); 
        cout << t->count << endl;
    }
    return 0;
}
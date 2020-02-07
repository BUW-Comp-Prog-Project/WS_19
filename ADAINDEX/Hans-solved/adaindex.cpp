#include <iostream>

using namespace std;

struct TrieNode
{
    TrieNode * child[26];
    bool isWord;
    long long count;

    TrieNode()
    {
        for(int i = 0; i < 26; i++)
			child[i] = NULL;
		isWord = false;
        count = 0;
    }
};

bool addWord(TrieNode * root, string s)
{
    TrieNode * t = new TrieNode;
    long long limit = s.length();
    t = root;
    if(root->child[s[0]-'a'] == NULL)
        root->child[s[0]-'a'] = new TrieNode;
        
    for(long long i = 0; i < limit; i++)
	{
		int m = s[i] - 'a';
		if(t->child[m] == NULL)
			t->child[m] = new TrieNode;  
		t = t->child[m];
        t->count++;
	}
	t->isWord = true;
}

long long findWord(TrieNode * root, string s)
{
    long long limit = s.length();
    if(limit == 0)
        return 0;
    for(long long i = 0; i < limit; i++)
    {
        int m = s[i] - 'a';
        if(root->child[m] == NULL)
            return 0;
        root = root->child[m];
    }
    return root->count;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    long long n, m;
    cin >> n >> m;
    string s;
    TrieNode * root = new TrieNode;
    while(n--)
    {
        cin >> s;
        addWord(root, s);
    }
    while(m--)
    {
        cin >> s;
        cout << findWord(root, s) << endl;
    }
    return 0;
}
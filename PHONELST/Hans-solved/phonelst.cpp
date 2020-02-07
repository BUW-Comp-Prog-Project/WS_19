#include <iostream>

using namespace std;

struct TrieNode
{
    TrieNode * child[10];
    bool isNumber;

    TrieNode()
    {
        for(int i = 0; i < 10; i++)
			child[i] = NULL;
		isNumber = false;
    }
};

bool found;
TrieNode * root;

bool addNumber(string s)
{
    TrieNode * t = new TrieNode;
    int limit = s.length();
    t = root;
    if(root->child[s[0]-'0'] == NULL)
        root->child[s[0]-'0'] = new TrieNode;
        
    for(int i = 0; i < limit; i++)
	{
		int m = s[i] - '0';
		if(t->isNumber)
			found = true;
		if(t->child[m] == NULL)
			t->child[m] = new TrieNode;  
		t = t->child[m];
	}
	t->isNumber = true;

	for(int i = 0; i < 10; i++)
		if(t->child[i] != NULL)
			found = true;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n, m;
    cin >> n;
    
    while(n--)
    {
        found = false;
        root = new TrieNode;
        cin >> m;
        while(m--)
        {
            string s;
            cin >> s;
            addNumber(s);
        }
        (found) ? cout << "NO" << endl : cout << "YES" << endl;
    }
    return 0;
}
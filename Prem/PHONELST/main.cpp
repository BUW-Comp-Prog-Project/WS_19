#include <iostream>
#include<string.h>
using namespace std;
bool located;
struct Trie
{
    Trie * offspring[10];
    bool isdigit;

    Trie()
    {
        for(int i=0; i<10; i++) offspring[i]=NULL;
        isdigit = false;
    }
};
Trie *root;

bool add_Contact(string s)
{
    Trie *q  = new Trie;
    int length = s.length();
    q = root;
    if(root->offspring[s[0]-'0']==NULL) root->offspring[s[0]-'0'] = new Trie;
    for(int i = 0; i < length; i++)
    {
        int m = s[i] - '0';
        if(q->isdigit)
            located = true;
        if(q->offspring[m] == NULL)
            q->offspring[m] = new Trie;
        q = q->offspring[m];
    }
    q->isdigit = true;

    for(int i = 0; i < 10; i++)
        if(q->offspring[i] != NULL)
            located = true;
}


int main() {
int t, n;
string s;
cin >> t;
while(n--)
{
    cin>>n;
    located = false;
    root = new Trie;
    while(n--)
    {
        cin >> s;
        add_Contact(s);
    }
    if(located) cout<<"NO"<< endl;
    else cout << "YES" <<endl;
}


return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int MAX = 26;
struct Node{
    Node* children[26]{};
    bool isEnd;
    Node()
    {
        isEnd = false;
        for(int i=0 ; i<MAX; i++)
        {
            children[i] = nullptr;
        }
    }
};
void insert(struct Node* root , const string& key)
{
    Node* current = root;
    for(int i=0 ; i<key.length() ; i++)
    {
        if(current->children[key[i]-'a']==nullptr)
            current->children[key[i]-'a'] = new Node();
        current = current->children[key[i] -'a'];
    }
    current->isEnd= true;
}
bool search(Node *root, const string& key)
{
    Node* current = root;
    for(int i=0 ; i<key.length() ; i++)
    {
        if(current->children[key[i]-'a']== nullptr){
            return false;
        }
        current = current->children[key[i]-'a'];
    }
    if(current!=nullptr && current->isEnd)
        return true;
}
void display(Node* root , char s[] ,int level )
{
    if(root->isEnd)
    {
        s[level] = '\0';
        cout<<s<<"\n";
    }
    for(int i=0 ; i<MAX ; i++){
        if(root->children[i]){
            s[level]=i+'a';
            display(root->children[i] , s , level+1);
        }
    }
}
int main()
{
    Node *root = new Node();
    string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/ sizeof(keys[0]);
    for(int i=0; i<n ; i++)
    {
        insert(root , keys[i]);
    }
    search(root, "by")? cout << "Yes\n" :
    cout << "No\n";
    search(root, "answers")? cout << "Yes\n" :
    cout << "No\n";

    char s[20];
    int level = 0;
    display(root, s , level);
    return 0;
}

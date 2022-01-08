#include<bits/stdc++.h>
using namespace std;

// very easy implementation


class node{

    public:

    char data;
    unordered_map<char,node*> children;
    bool terminal;


    node(char data){
        this->data = data;
        terminal = false;
    }
};


class trie{

    node* root;
    // int cnt;


    public:

    trie(){
        root = new node('\0');
        // cnt = 0;
    }

    void insert(char* s){

        node* temp = root;

        for(int i=0; s[i] != '\0'; i++){

            char ch = s[i];

            if( temp->children.count(ch)){
                temp = temp->children[ch];
            }
            else{
                node* n = new node(ch);
                temp->children[ch] = n;
                temp = n;

            }

        }

        temp->terminal = true;

    }

    bool find(char* s){

        node* temp = root;

        for(int i=0; s[i] != '\0'; i++){

            char ch = s[i];

            if(temp->children.count(ch)){
                temp = temp->children[ch];
            }
            else{
                return false;
            }
        }

        return temp->terminal;

    }

};


int main(){

    trie t;

    char words[][10] = { "a","apple","hello","not","news"};
    char w[10];
    cin>>w;

    for(int i=0;i<5;i++){

        t.insert(words[i]);
    }


    if(t.find(w)){
        cout<<"present"<<endl;
    }
    else{
        cout<<"not present"<<endl;
    }


    return 0;

}
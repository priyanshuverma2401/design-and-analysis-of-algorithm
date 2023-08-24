#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

struct node {
    char data;
    int frequency;
    node* left;
    node* right;

    // Constructor for leaf nodes
    node(char d, int freq) : data(d), frequency(freq), left(nullptr), right(nullptr) {}
};

struct compare {
    bool operator()(node* a, node* b) {
        return a->frequency > b->frequency;
    }
};

node* createhuffman(map<char, int> frequency) {
    priority_queue<node*, vector<node*>, compare> pq;
    for (auto entry : frequency) {
        pq.push(new node(entry.first, entry.second));
    }

    while (pq.size() > 1) {
        node* left = pq.top();
        pq.pop();
        node* right = pq.top();
        pq.pop();
        node* combined = new node('$', left->frequency + right->frequency);
        combined->left = left;
        combined->right = right;

        pq.push(combined);
    }
    return pq.top();
}

void hcode(node* root, string code, map<char, string>& huffmanCode) {
    if (!root) return;

    if (root->data != '$') {
        huffmanCode[root->data] = code;
    }
    hcode(root->left, code + "0", huffmanCode);
    hcode(root->right, code + "1", huffmanCode);
}

int main() {
    string str;
    cout << "input string : ";
    cin >> str;
    map<char, int> frequency;

    for (char c : str) {
        frequency[c]++;
    }

    node* root = createhuffman(frequency); // Fixed function name
    map<char, string> huffmanCode;
    hcode(root, "", huffmanCode);

    cout << "huffman code: "<<endl;
    for (auto entry : huffmanCode) {
        cout << entry.first << " : " << entry.second << endl;
    }
    
    string compressed;
    for(char c: str){
        compressed += huffmanCode[c];
    }
    cout<<"compressed text : "<<compressed<<endl;
    int totalbit= compressed.length();
    cout<<"total bit used : "<<totalbit<<endl;

    return 0;
}


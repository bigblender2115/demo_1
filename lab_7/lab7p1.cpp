#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

//node structure, has a char, freq and pointers towards left and right nodes
struct Node {
    char c;
    int freq;
    Node *left, *right;
    Node(char s, int f) : c(s), freq(f), left(nullptr), right(nullptr) {}
};

//minheap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

//generates the code
void codes(Node* root, string code, unordered_map<char, string>& thecodes) {
    //if empty tree, return
    if(!root) return;

    //if leaf node, assigns the code to the character
    if(!root->left && !root->right) {
        thecodes[root->c] = code;
    }

    //recursively calling codes fxn on left and right subtrees
    codes(root->left, code + "0", thecodes); //left nodes -> 0 gets appended to the code
    codes(root->right, code + "1", thecodes); //right nodes -> 1 gets appended to the code
}

int main() {
    string text = "duke blue devils";

    //count frequency
    unordered_map<char, int> freq;
    for(char s : text) {
        freq[s]++;
    } 

    //pushing all the nodes to a minheap
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& p : freq){
        pq.push(new Node(p.first, p.second));
    }

    //building the huffman tree
    while (pq.size() > 1) {
        //smallest node
        Node* a = pq.top(); 
        pq.pop();

        //2nd smallest node
        Node* b = pq.top();
        pq.pop();

        //merge those 2 nodes, add their frequencies
        Node* merged = new Node('\0', a->freq + b->freq);
        merged->left = a;
        merged->right = b;

        //push the merged node back into the minheap
        pq.push(merged);
    }

    Node* root = pq.top();

    //generating the codes
    unordered_map<char, string> thecodes;
    codes(root, "", thecodes);

    for(auto& s : thecodes) {
        cout << s.first << " : " << s.second << endl;
    }

    cout << endl;

    for(char c : text) {
        cout << thecodes[c];
    }
    cout << endl;

    int obytes = text.size();
    int tbits = 0;
    for(char c : text) tbits += thecodes[c].length();
    int cbytes = (tbits + 7) / 8;

    cout << "Original size: " << obytes << endl;
    cout << "Compressed size: " << cbytes << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
    Node(int d){
        val = d;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

Node* head = NULL;

Node* find(long long x)
{
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->val == x) 
            return temp;
        else if(temp->val > x)
            temp = temp->left;
        else
            temp = temp->right;         
    }
    return NULL;
}

void insert2(long long x)
{
    Node* temp = head;
    if(temp == NULL)
    {
        head = new Node(x);
        return;
    }
    while(temp != NULL)
    {
        if(temp->val == x) 
            return ;
        else if(temp->val > x && temp->left != NULL)
            temp = temp->left;
        else if(temp->val > x && temp->left == NULL)
        {
            Node* new_node = new Node(x);
            new_node->parent = temp;
            temp->left = new_node;
            return;
        }
        else if(temp->val < x && temp->right != NULL)
            temp = temp->right;
        else if(temp ->val < x && temp->right == NULL)
        {
            Node* new_node = new Node(x);
            new_node->parent = temp;
            temp->right = new_node;
            return;
        }         
    }
    return ;   
}


void del(Node* todel){
    if(todel->parent == NULL){
        
    }
    if(todel->left == NULL){
        todel->right->parent = todel->parent;
        if(todel->parent->left == todel)    todel->parent->left = todel->right;
        else    todel->parent->right = todel->right;
        return;
    }   
    if(todel->right == NULL){
        todel->left->parent = todel->parent;
        if(todel->parent->left == todel)    todel->parent->left = todel->left;
        else    todel->parent->right = todel->left;
        return;
    }
    Node* temp = todel->right;
    while(temp!=NULL){
        temp = temp->left;
    }
    temp->left = todel->left;
    todel->left->parent = temp;
    temp->parent->left = NULL;
    temp->parent = todel->parent;
    temp->right = todel->right;
    todel->right->parent = temp;
    if(todel->parent->left == todel)    todel->parent->left = temp;
    else    todel->parent->right = temp;
    return;
}

void del2(Node* todel)
{
    Node* parent_node = todel->parent;
    if(todel-> right != NULL)
    {
        Node* temp = todel->right;
        while(temp->left != NULL)
            temp = temp->left;
        
        temp->left = todel->left;
        if(temp->left != NULL)
            temp ->left->parent = temp;
        
        if(parent_node == NULL)
            head = todel->right;
        else if(parent_node->left == todel)
            parent_node -> left = todel->right;
        else if(parent_node ->right == todel)
            parent_node ->right = todel->right;
        
        todel ->right ->parent = parent_node;
        
        delete todel;
    }
    else
    {
        if(todel->left != NULL)
            todel->left->parent = parent_node;
        
        if(parent_node == NULL)
            head = todel->left;
        else if(parent_node->left == todel)
            parent_node ->left = todel->left;
        else if(parent_node->right == todel)
            parent_node ->right = todel->left;
        
        delete todel;
    }
    return;
}

Node* deleteNode(Node* root, int k)
{
    if (root == NULL)
        return root;
    if (root->val > k) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->val < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }
    else {
 
        Node* succParent = root;
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        root->val = succ->val;
        delete succ;
        return root;
    }
}
Node* insert(Node* node, int val)
{
    if (node == NULL)
        return new Node(val);
    if (val < node->val)
        node->left = insert(node->left, val);
    else
        node->right = insert(node->right, val);
    return node;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int D;cin>>D;
    while(D--){
        char ch;
        long long x;
        cin >> ch >> x;
        if(ch == 'B')
        {
            head = insert(head, x);
        }
        if(ch == 'S')
        {
            // Node* todel = find(x);
            // if(todel) del2(todel);
            head = deleteNode(head, x);
        }
        if(ch == 'R')
        {
            if(find(x))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }  
    }
    return 0;
}
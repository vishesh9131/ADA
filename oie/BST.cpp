//  object:
//  preceed n number of values from tghe user and build a bST of that ,
//  now ask for the type of traersal user wanna perform sp treverse the 
//  tree as per the guven input.
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *addL;
    Node *addR;

    Node(int data){this->data=data; addL=NULL; addR=NULL;}
}; 

//node maker
Node* insert(Node* root, int dt){
// dt : data int 
// Node *root is family init
if (root == NULL)  
    {return new Node(dt);}
if (dt < root->data)  
{
   root->addL = insert(root->addL,dt);
}else{
   root->addR = insert(root->addR,dt);
}
return root;
}

// In-order traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->addL);
        cout << root->data << " ";
        inorder(root->addR);
    }
}

// Pre-order traversal
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->addL);
        preorder(root->addR);
    }
}

// Post-order traversal
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->addL);
        postorder(root->addR);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = NULL;
    int n, value;
    cout << "Enter the number of values: ";
    cin >> n;

    cout << "Enter the values: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insert(root, value);
    }

    int choice;
    cout << "Enter the type of traversal (1: In-order, 2: Pre-order, 3: Post-order): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "In-order traversal: ";
            inorder(root);
            break;
        case 2:
            cout << "Pre-order traversal: ";
            preorder(root);
            break;
        case 3:
            cout << "Post-order traversal: ";
            postorder(root);
            break;
        default:
            cout << "Invalid choice!";
    }

    cout << endl;
    return 0;
}

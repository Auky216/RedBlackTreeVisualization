#include <iostream>


using namespace std;

template<typename T>
struct Node {
    Node* right;
    Node* left;
    T data;
};

template<typename T>
class Tree {
private:
    Node<T>* root;

    Node<T>* insertRecursive(Node<T>* node, T value) {
        if (node == nullptr) {
            Node<T>* newNode = new Node<T>;
            newNode->data = value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    Node<T>* findMin(Node<T>* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node<T>* deleteRecursive(Node<T>* node, T value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = deleteRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = deleteRecursive(node->right, value);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                Node<T>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node<T>* temp = node->left;
                delete node;
                return temp;
            } else {
                Node<T>* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteRecursive(node->right, temp->data);
            }
        }

        return node;
    }

    void displayUtil(Node<T>* root, int espacio) {
        if (root == nullptr) return;

        const int espaciado = 5;

        espacio += espaciado;

        displayUtil(root->right, espacio);

        cout << endl;
        for (int i = espaciado; i < espacio; ++i)
            cout << " ";
        cout << root->data << "\n";

        displayUtil(root->left, espacio);
    }

    int altura(Node<T>* root) {
        if (root == nullptr) return 0;
        int izquierda = altura(root->left);
        int derecha = altura(root->right);
        return (izquierda > derecha) ? izquierda + 1 : derecha + 1;
    }

public:
    Tree() {
        this->root = nullptr;
    }

    void insert(T value) {
        this->root = insertRecursive(this->root, value);
    }

    void remove(T value) {
        this->root = deleteRecursive(this->root, value);
    }

    void display() {
        displayUtil(root, 0);
    }
};

int main() {
    Tree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.insert(10);
    tree.insert(25);
    tree.insert(35);
    tree.insert(45);
    tree.insert(55);
    tree.insert(65);
    tree.insert(75);
    tree.insert(85);

    tree.display();

    return 0;
}

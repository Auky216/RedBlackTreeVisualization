#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node* parent;
    Node* left;
    Node* right;
    int color; // 0 for black and 1 for red

    Node(T data) {
        this->data = data;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        color = 1; // Every node created is red
    }

    void killSelf() {
        if (left != nullptr) {
            left->killSelf();
        }
        if (right != nullptr) {
            right->killSelf();
        }
        delete this;
    }



};

template <typename T>
class RedBlackTree {

    Node<T> *root;

    // Getters
    Node<T> *getParent(Node<T> *node) {
        if (node != nullptr) {
            return node->parent;
        }
        return nullptr;
    }

    Node<T> *getGrandparent(Node<T> *node) {
        if (node != nullptr && node->parent != nullptr) {
            return node->parent->parent;
        }
        return nullptr;
    }

    Node<T> *getUncle(Node<T> *node) {
        Node<T> *grandparent = getGrandparent(node);
        if (grandparent == nullptr)
            return nullptr;
        if (node->parent == grandparent->left)
            return grandparent->right;
        else
            return grandparent->left;
    }

    // Predecessor and successor
    Node<T> *getPredecessor(Node<T> *node) {
        if (node->left != nullptr)
            return getMax(node->left);

        Node<T> *temp = node->parent;
        while (temp != nullptr && node == temp->left) {
            node = temp;
            temp = temp->parent;
        }
        return temp;
    }

    Node<T> *getSuccessor(Node<T> *node) {
        if (node->right != nullptr)
            return getMin(node->right);

        Node<T> *temp = node->parent;
        while (temp != nullptr && node == temp->right) {
            node = temp;
            temp = temp->parent;
        }
        return temp;
    }

    // Methods for insertion and deletion
    void insertNode(Node<T> *&node, const T &data) {
        Node<T> *newNode = new Node<T>(data);
        newNode->color = 1; // Red node
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (node == nullptr) {
            root = newNode;
            newNode->color = 0;
            newNode->left = nullptr;
            newNode->right = nullptr;
        } else {
            Node<T> *temp = node;
            Node<T> *parent = nullptr;

            while (temp != nullptr) {
                parent = temp;
                if (data < temp->data) {
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            }

            newNode->parent = parent;
            if (data < parent->data) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }

        insert_Aux_Properties(newNode);
    }

    void insert_Aux_Properties(Node<T> *&node) {
        while (getParent(node) != nullptr && getParent(node)->color == 1) {
            if (getParent(node) == getGrandparent(node)->left) {
                Node<T> *uncle = getGrandparent(node)->right;
                if (uncle != nullptr && uncle->color == 1) {
                    getParent(node)->color = 0;
                    getUncle(node)->color = 0;
                    getGrandparent(node)->color = 1;
                    node = getGrandparent(node);
                } else {
                    if (node == getParent(node)->right) {
                        node = getParent(node);
                        rotateLeft(node);
                    }
                    getParent(node)->color = 0;
                    getGrandparent(node)->color = 1;
                    rotateRight(node->parent->parent);
                }
            } else {
                Node<T> *uncle = getGrandparent(node)->left;
                if (getUncle(node) != nullptr && getUncle(node)->color == 1) {
                    getParent(node)->color = 0;
                    getUncle(node)->color = 0;
                    getGrandparent(node)->color = 1;
                    node = getGrandparent(node);
                } else {
                    if (node == getParent(node)->left) {
                        node = getParent(node);
                        rotateRight(node);
                    }
                    getParent(node)->color = 0;
                    getGrandparent(node)->color = 1;
                    rotateLeft(getGrandparent(node));
                }
            }
        }

        root->color = 0;
    }

    Node<T> *searchNode(Node<T> *root, const T &data) {
        if (root == nullptr || root->data == data) {
            return root;
        }

        if (data < root->data) {
            return searchNode(root->left, data);
        } else {
            return searchNode(root->right, data);
        }
    }

    void rotateLeft(Node<T> *node) {
        Node<T> *rightChild = node->right;
        node->right = rightChild->left;

        if (rightChild->left != nullptr) {
            rightChild->left->parent = node;
        }

        rightChild->parent = getParent(node);
        if (getParent(node) == nullptr) {
            root = rightChild;
        } else if (node == getParent(node)->left) {
            getParent(node)->left = rightChild;
        } else {
            getParent(node)->right = rightChild;
        }

        rightChild->left = node;
        node->parent = rightChild;
    }

    void rotateRight(Node<T> *node) {
        Node<T> *leftChild = node->left;
        node->left = leftChild->right;

        if (leftChild->right != nullptr) {
            leftChild->right->parent = node;
        }

        leftChild->parent = getParent(node);
        if (getParent(node) == nullptr) {
            root = leftChild;
        } else if (node == getParent(node)->left) {
            getParent(node)->left = leftChild;
        } else {
            getParent(node)->right = leftChild;
        }

        leftChild->right = node;
        node->parent = leftChild;
    }

    Node<T> *minimum(Node<T> *node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node<T> *BSTSearch(Node<T> *root, const T &data) {
        if (root == nullptr || root->data == data) {
            return root;
        }
        if (root->data < data) {
            return BSTSearch(root->right, data);
        }
        return BSTSearch(root->left, data);
    }

    void deleteNode(Node<T> *&root, const T &data) {
        Node<T> *z = BSTSearch(root, data);
        if (z == nullptr) {
            return;
        }
        Node<T> *y = z;
        char yOriginalColor = y->color;
        Node<T> *x;
        if (z->left == nullptr) {
            x = z->right;
            transplant(root, z, z->right);
        } else if (z->right == nullptr) {
            x = z->left;
            transplant(root, z, z->left);
        } else {
            y = minimum(z->right);
            yOriginalColor = y->color;
            x = y->right;
            if (y->parent == z) {
                if (x != nullptr) {
                    x->parent = y;
                }
            } else {
                transplant(root, y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(root, z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        if (yOriginalColor == 0) {
            deleteFixup(root, x);
        }
        delete z;
    }

    void transplant(Node<T> *&root, Node<T> *u, Node<T> *v) {
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v != nullptr) {
            v->parent = u->parent;
        }
    }

    void deleteFixup(Node<T> *&root, Node<T> *x) {
        while (x != nullptr && x != root && x->color == 0) {
            if (x == x->parent->left) {
                Node<T> *w = x->parent->right;
                if (w != nullptr && w->color == 1) {
                    w->color = 0;
                    x->parent->color = 1;
                    rotateLeft(x->parent);
                    w = x->parent->right;
                }
                if (w != nullptr) {
                    if ((w->left == nullptr || w->left->color == 0) && (w->right == nullptr || w->right->color == 0)) {
                        w->color = 1;
                        x = x->parent;
                    } else {
                        if (w->right == nullptr || w->right->color == 0) {
                            if (w->left != nullptr) {
                                w->left->color = 0;
                            }
                            w->color = 1;
                            rotateRight(w);
                            w = x->parent->right;
                        }
                        if (w != nullptr) {
                            w->color = x->parent->color;
                            x->parent->color = 0;
                            if (w->right != nullptr) {
                                w->right->color = 0;
                            }
                            rotateLeft(x->parent);
                        }
                        x = root;
                    }
                }
            } else {
                Node<T> *w = x->parent->left;
                if (w != nullptr && w->color == 1) {
                    w->color = 0;
                    x->parent->color = 1;
                    rotateRight(x->parent);
                    w = x->parent->left;
                }
                if (w != nullptr) {
                    if ((w->right == nullptr || w->right->color == 0) && (w->left == nullptr || w->left->color == 0)) {
                        w->color = 1;
                        x = x->parent;
                    } else {
                        if (w->left == nullptr || w->left->color == 0) {
                            if (w->right != nullptr) {
                                w->right->color = 0;
                            }
                            w->color = 1;
                            rotateLeft(w);
                            w = x->parent->left;
                        }
                        if (w != nullptr) {
                            w->color = x->parent->color;
                            x->parent->color = 0;
                            if (w->left != nullptr) {
                                w->left->color = 0;
                            }
                            rotateRight(x->parent);
                        }
                        x = root;
                    }
                }
            }
        }
        if (x != nullptr) {
            x->color = 0;
        }
    }


public:
    RedBlackTree() : root(nullptr) {}

    void insert(const T &data) {
        insertNode(root, data);
    }

    void remove(const T &data) {
        deleteNode(root, data);
    }

    Node<T> *search(const T &data) {
        return searchNode(root, data);
    }



    // Utility functions for testing
    void inorder(Node<T>* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void printTree() {
        inorder(root);
        cout << endl;
    }

    Node<T>* getRoot() {
        return root;
    }

    void printTreeWithColors(Node<T>* node, int indent = 0, int color = 0) {
        if (node != nullptr) {
            cout << setw(indent) << " ";
            cout << node->data;
            if (node->color == 1) {
                cout << " (Red)" << endl;
            } else {
                cout << " (Black)" << endl;
            }
            printTreeWithColors(node->left, indent + 4, node->color);
            printTreeWithColors(node->right, indent + 4, node->color);
        }
    }
    void printTreeWithColors() {
        printTreeWithColors(root);
        cout << endl;
    }

};

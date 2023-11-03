#include "iostream"

template<typename T>

class RBT{
private:
    struct Node{
        T data;
        Node* right;
        Node* left;
        Node* parent;
        char color;

        Node(){
            this->right = nullptr;
            this->left = nullptr;
            this->parent = nullptr;
        }

    };

    Node* root;
public:
    RBT(){
        this->root = nullptr;
    }

    void Insert(T value){

    }

    void Find(T value){

    }

    void Delete(T value){

    }

};


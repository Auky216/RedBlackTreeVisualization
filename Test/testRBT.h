#include <iostream>
#include <string>
#include <iomanip>
#include <raylib.h>
#include <cmath>


using namespace std;

template<typename T>
struct Node {
    T data;
    Node* parent;
    Node* left;
    Node* right;
    int height; //altura
    int color; //0 para negro y 1 para rojo
    Node(T data) {
        this->data = data;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        color = 1; //Rojo
        height = 0;
    }
    //Color asignado para el nodo: rojo o negro
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
private:
    Node<T>* root;
    //Getters


    Node<T>* getParent(Node<T>* node){
        if(node!= nullptr){
            return node->parent;
        }
        return nullptr;
    }

    Node<T>* getGrandparent(Node<T>* node) {
        if (node != nullptr && node->parent != nullptr) {
            return node->parent->parent;
        }
        return nullptr;
    }

    Node<T>* getUncle(Node<T>* node){
        Node<T>* grandparent = getGrandparent(node);
        if (grandparent == nullptr)
            return nullptr;
        if (node->parent == grandparent->left)
            return grandparent->right;
        else
            return grandparent->left;
    }

    //Predecesor y sucesor
    Node<T>* getPredecessor(Node<T>* node){
        if(node->left != nullptr)
            return getMax(node->left);

        //Caso: si el nodo no tiene un subsarbol izquierdo, se busca el ancestro mas cercano
        Node<T>* temp = node->parent;
        while(temp != nullptr && node == temp->left){
            node = temp;
            temp = temp->parent;
        }
        return temp;
    }

    Node<T>* getSuccessor(Node<T>* node){
        if(node->right != nullptr)
            return getMin(node->right);
        //Caso contrario, se busca el sucesor mas cercano
        Node<T>* temp = node->parent;
        while(temp != nullptr && node == temp->right){
            node = temp;
            temp = temp->parent;
        }
        return temp;
    }


    //Metodos privados
    void insertNode(Node<T>*& node, const T& data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->color = 1; // Nodo rojo
        newNode->left = nullptr;
        newNode->right = nullptr;

        // Caso base: para árbol vacío, el nodo es la raiz y seteamos el color en negro
        if (node == nullptr) {
            root = newNode;
            newNode->color = 0;
            newNode->left = nullptr;
            newNode->right = nullptr;
        } else {
            Node<T>* temp = node;
            Node<T>* parent = nullptr;

            // Buscar la posición de inserción en el árbol BST O(log n)
            while (temp != nullptr) {
                parent = temp;
                if (data < temp->data) {
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            }

            // Enlazamos el nuevo nodo con su padre
            newNode->parent = parent;
            if (data < parent->data) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }

        //Funcion que nos ayuda a mantener las propiedades del arbol rojo y negro
        insert_Aux_Properties(newNode);
    }

    void insert_Aux_Properties(Node<T>*& node) {
        while (getParent(node) != nullptr && getParent(node)->color == 1) {
            if (getParent(node) == getGrandparent(node)->left) {
                Node<T>* uncle = getGrandparent(node)->right;
                if (uncle != nullptr && uncle->color == 1) {
                    // Caso 1: El tío es rojo, cambiamos colores y seguimos escalando
                    getParent(node)->color = 0;
                    getUncle(node)->color = 0;
                    getGrandparent(node)->color = 1;
                    node = getGrandparent(node);
                } else {
                    if (node == getParent(node)->right) {
                        // Caso 2: El tío es negro y el nodo es un hijo derecho, realizamos rotación izquierda
                        node = getParent(node);
                        rotateLeft(node);
                    }
                    // Caso 3: El tío es negro y el nodo es un hijo izquierdo, cambiar colores y realizamos rotación derecha
                    getParent(node)->color = 0;
                    getGrandparent(node)->color = 1;
                    rotateRight(node->parent->parent);
                }
            } else {
                Node<T>* uncle = getGrandparent(node)->left;
                if (getUncle(node) != nullptr && getUncle(node)->color == 1) {
                    // Caso 1: El tío es rojo, se cambia los colores y seguimos escalando
                    getParent(node)->color = 0;
                    getUncle(node)->color = 0;
                    getGrandparent(node)->color = 1;
                    node = getGrandparent(node);
                } else {
                    if (node == getParent(node)->left) {
                        // Caso 2: El tío es negro y el nodo es un hijo izquierdo, entonces se realiza rotación derecha
                        node = getParent(node);
                        rotateRight(node);
                    }
                    // Caso 3: El tío es negro y el nodo es un hijo derecho,lo cambio de color y hago una rotación izquierda
                    getParent(node)->color = 0;
                    getGrandparent(node)->color = 1;
                    rotateLeft(getGrandparent(node));
                }
            }
        }

        root->color = 0; //La raiz siempre se mantiene negra
    }


    Node<T>* searchNode(Node<T>*& root, const T& data){
        if(root == nullptr)
            return nullptr;
        //Caso contrario
        while(root != nullptr && root->data != data) {
            if (data < root->data)
                root = root->left;
            else if (data > root->dara)
                root = root->right;
            else
                return root;
        }
        return nullptr;
    }

    void rotateLeft(Node<T>* node){
        Node<T>* rightChild = node->right; //Nodo apunta al hijo derecho
        node->right = rightChild->left; //Hijo derecho apunta al hijo izquierdo

        //Se verifica que el hijo izquierdo no sea nulo para asignarle el padre
        if(rightChild->left != nullptr){
            rightChild->left->parent = node; //El padre del hijo izquierdo es el nodo
        }

        rightChild->parent = getParent(node); //El padre del hijo derecho es el padre del nodo
        if(getParent(node) == nullptr){ //Si el padre del nodo es nulo, el hijo derecho es la raiz
            root = rightChild; //La raiz es el hijo derecho ahora
        }
        else if(node == getParent(node)->left){ //Si el nodo es el hijo izquierdo
            getParent(node)->left = rightChild; //El hijo izquierdo del padre es el hijo derecho
        }
        else{
            getParent(node)->right = rightChild; //El hijo derecho del padre es el hijo derecho
        }

        rightChild->left = node; //El hijo izquierdo del hijo derecho es el nodo
        node->parent = rightChild; //El padre del nodo es el hijo derecho
    }

    void rotateRight(Node<T>* node){
        Node<T>* leftChild = node->left; //Nodo apunta al hijo izquierdo
        node->left = leftChild->right; //Hijo izquierdo apunta al hijo derecho
        //Se verifica que el hijo derecho no sea nulo para asignarle el padre
        if(leftChild->right != nullptr){
            leftChild->right->parent = node; //El padre del hijo derecho es el nodo
        }
        leftChild->parent = getParent(node); //El padre del hijo izquierdo es el padre del nodo
        if(getParent(node) == nullptr){ //Si el padre del nodo es nulo, el hijo izquierdo es la raiz
            root = leftChild; //La raiz es el hijo izquierdo ahora
        }
        else if(node == getParent(node)->left){ //Si el nodo es el hijo izquierdo
            getParent(node)->left = leftChild; //El hijo izquierdo del padre es el hijo derecho
        }
        else{
            getParent(node)->right = leftChild; //El hijo izquierdo del padre es el hijo izquierdo
        }

        leftChild->right = node; //El hijo derecho del hijo izquierdo es el nodo
        node->parent = leftChild; //El padre del nodo es el hijo izquierdo
    }



public:
    RedBlackTree(){
        root = nullptr;
    }
    ~RedBlackTree() {
        if (root != nullptr) {
            root->killSelf();
        }
    }
    RedBlackTree(T data){
        root = new Node<T>(data);
        root->color = 0; //color negro
    }
    Node<T>* getRoot() const {
        return root;
    }

    void insertNode(const T& data){
        insertNode(root, data);
    }

};

template <typename T>
void display(Node<T>* node, int indent) {
    if (node != nullptr) {
        if (node->right != nullptr) {
            display(node->right, indent + 4);
        }
        if (indent > 0) {
            cout << setw(indent) << " ";
        }
        cout << node->data << " (" << (node->color == 0 ? "B" : "R") << ")" << endl;
        if (node->left != nullptr) {
            display(node->left, indent + 5);
        }
    }
}


int main() {
    // Create a RedBlackTree of integers
    RedBlackTree<int> arbol;

    // Insert some values
    arbol.insertNode(10);
    arbol.insertNode(85);
    arbol.insertNode(15);
    arbol.insertNode(1);
    arbol.insertNode(25);
    arbol.insertNode(0);
    arbol.insertNode(35);
    arbol.insertNode(80);
    // Imprimiendo el arbol rojo y negro con su color
    cout << "Red-Black Tree Structure:" << endl;
    display(arbol.getRoot(), 0);
    //Buscando el nodo

    while (!WindowShouldClose()) {
        // Mover la vista de los nodos con las teclas de dirección

        BeginDrawing();
        ClearBackground(RAYWHITE);

        arbol.display(); // Dibujar el árbol binario

        // Dibujar un círculo móvil para representar la raíz del árbol

        EndDrawing();
    }

    CloseWindow();
}
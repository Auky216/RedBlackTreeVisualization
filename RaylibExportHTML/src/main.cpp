#include "raylib.h"
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#define screenWidth 1280 // x
#define screenHeight 720 // y

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

    struct TreeNode {
        Node<T>* node;
        Vector2 position;
    };

    vector<TreeNode> nodes; // Almacena los nodos y sus posiciones

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

    // Función para dibujar el árbol binario de manera gráfica con líneas de unión entre nodos
    void displayUtil(Node<T>* root, int nivel, float x, float y, float horizontalSeparation, float offsetY) {
        if (root == nullptr) return;

        // Calcular el desplazamiento horizontal
        float offsetX = screenWidth / std::pow(2, nivel + 1)/2.5;

        // Almacenar la posición del nodo y su información
        TreeNode treeNode;
        treeNode.node = root;
        treeNode.position = { x, y };
        nodes.push_back(treeNode);

        // Calcular las posiciones para los nodos izquierdo y derecho
        displayUtil(root->left, nivel + 1, x - offsetX, y + offsetY, horizontalSeparation / 2, offsetY);
        displayUtil(root->right, nivel + 1, x + offsetX, y + offsetY, horizontalSeparation / 2, offsetY);

        // Dibujar líneas entre nodos padre e hijo (si existen)
        if (root->left != nullptr) {
            DrawLineV(Vector2{ x, y }, Vector2{ x - offsetX, y + offsetY }, RED);
        }
        if (root->right != nullptr) {
            DrawLineV(Vector2{ x, y }, Vector2{ x + offsetX, y + offsetY }, RED);
        }
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

    int altura(Node<T>* root) {
        if (root == nullptr) return 0;
        int izquierda = altura(root->left);
        int derecha = altura(root->right);
        return (izquierda > derecha) ? izquierda + 1 : derecha + 1;
    }

    void display() {
        nodes.clear(); // Limpiar nodos y posiciones anteriores
        int nivel = altura(root);
        float horizontalSeparation = screenWidth / std::pow(2, nivel + 2);

        // Ajustar la separación vertical entre los nodos
        float offsetY = 150; // Ajusta este valor para cambiar la separación vertical entre los nodos

        // Dibujar el árbol desde la raíz con la nueva separación vertical
        displayUtil(root, 0, screenWidth / 2, 40, horizontalSeparation, offsetY);

        // Dibujar los nodos con sus posiciones calculadas
        for (const auto& treeNode : nodes) {
            DrawCircleV(treeNode.position, 40, BLUE);
            std::string text = std::to_string(treeNode.node->data);
            DrawText(text.c_str(), (int)(treeNode.position.x - MeasureText(text.c_str(), 20) / 2),
                     (int)(treeNode.position.y - 20 / 2), 20, WHITE);
        }
    }
};

int main() {
    InitWindow(screenWidth, screenHeight, "Binary Tree");

    Tree<int> arbol;
    arbol.insert(10);
    arbol.insert(5);
    arbol.insert(15);
    arbol.insert(3);
    arbol.insert(7);
    arbol.insert(12);
    arbol.insert(18);
    arbol.insert(1);
    arbol.insert(4);
    arbol.insert(6);
    arbol.insert(8);
    arbol.insert(11);
    arbol.insert(13);
    arbol.insert(16);
    arbol.insert(19);
    arbol.insert(2);
    arbol.insert(9);
    arbol.insert(14);
    arbol.insert(17);
    arbol.insert(20);


    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Mover la vista de los nodos con las teclas de dirección

        BeginDrawing();
        ClearBackground(RAYWHITE);

        arbol.display(); // Dibujar el árbol binario

        // Dibujar un círculo móvil para representar la raíz del árbol

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

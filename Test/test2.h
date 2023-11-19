#include "raylib.h"
#include <string>
#include "iostream"


#define screenWidth 1280
#define screenHeight 720

using namespace std;

template<typename T>
struct Node{
    Node* right;
    Node* left;
    T data;
};

template<typename T>
class Tree{
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

    void displayInorder(Node<T>* node) {
        if (node != nullptr) {
            displayInorder(node->left);
            cout << node->data << " ";
            displayInorder(node->right);
        }
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



public:
    Tree(){
        this->root = nullptr;
    }

    void insert(T value) {
        this->root = insertRecursive(this->root, value);
    }

    void remove(T value) {
        this->root = deleteRecursive(this->root, value);
    }

    void display() {
        cout << "Inorden traversal: ";
        displayInorder(this->root);
        cout <<endl;
    }

    void display2() {
        displayUtil(root, 0);
    }
};


int main() {
    InitWindow(screenWidth, screenHeight, "Red Black Tree");

    Vector2 circlePos = { (float)screenWidth / 2, 40};
    int circleRadius = 40;
    int number = 42; // Número dentro del círculo
    float speed = 5.0; // Velocidad de movimiento del círculo

    SetTargetFPS(60);

    Tree<int> tree;
    tree.insert(100);
    tree.insert(80);
    tree.insert(70);
    tree.insert(50);
    tree.insert(40);
    tree.insert(30);
    tree.insert(10);

    tree.display(); // Imprime el árbol en inorden
    tree.display2();

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT)) circlePos.x -= speed;
        if (IsKeyDown(KEY_LEFT)) circlePos.x += speed;
        if (IsKeyDown(KEY_UP)) circlePos.y += speed;
        if (IsKeyDown(KEY_DOWN)) circlePos.y -= speed;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Dibujar el círculo
        DrawCircleV(circlePos, circleRadius, BLUE);

        // Dibujar el número dentro del círculo
        string text = to_string(number);
        DrawText(text.c_str(), (int)(circlePos.x - MeasureText(text.c_str(), 20) / 2),
                 (int)(circlePos.y - 20 / 2), 20, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

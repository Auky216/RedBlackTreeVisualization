#include <string>
#include <raylib.h>
#include <cmath>
#include "vector"
#include "RBT.h"

#define screenWidth 1920
#define screenHeight 1080 

template<typename T>
struct TreeNode {
    Node<T>* node;
    Vector2 position;
};

vector<TreeNode<int>> nodes;

template<typename T>
int height(Node<T>* root){
    if (root == nullptr) return 0;
    int izquierda = height(root->left);
    int derecha = height(root->right);
    return (izquierda > derecha) ? izquierda + 1 : derecha + 1;
}
template<typename T>
void displayUtil(Node<T>* root, int nivel, float x, float y, float horizontalSeparation, float offsetY) {
    if (root == nullptr) return;

    // Calcular el desplazamiento horizontal
    float offsetX = screenWidth / std::pow(2, nivel + 1) / 2.5;

    // Almacenar la posición del nodo y su información
    TreeNode<T> treeNode;
    treeNode.node = root;
    treeNode.position = { x, y };
    nodes.push_back(treeNode);

    // Calcular las posiciones para los nodos izquierdo y derecho
    displayUtil(root->left, nivel + 1, x - offsetX, y + offsetY, horizontalSeparation / 2, offsetY);
    displayUtil(root->right, nivel + 1, x + offsetX, y + offsetY, horizontalSeparation / 2, offsetY);

    // Dibujar líneas entre nodos padre e hijo (si existen)
    if (root->left != nullptr) {
        DrawLineV(Vector2{ x, y }, Vector2{ x - offsetX, y + offsetY }, DARKGRAY);
    }
    if (root->right != nullptr) {
        DrawLineV(Vector2{ x, y }, Vector2{ x + offsetX, y + offsetY }, DARKGRAY);
    }

    // Dibujar el nodo con color rojo o negro
    Color nodeColor = (root->color == 0) ? BLACK : RED;
    DrawCircleV(treeNode.position, 40, nodeColor);
    std::string text = std::to_string(treeNode.node->data);
    DrawText(text.c_str(), (int)(treeNode.position.x - MeasureText(text.c_str(), 20) / 2),
             (int)(treeNode.position.y - 20 / 2), 20, WHITE);
}


template<typename T>
void displayRedBlackTree(Node<T>* root) {
    nodes.clear(); // Limpiar nodos y posiciones anteriores
    int nivel = height(root);
    float horizontalSeparation = screenWidth / pow(2, nivel + 2);

    // Ajustar la separación vertical entre los nodos
    float offsetY = 150; // Ajusta este valor para cambiar la separación vertical entre los nodos

    // Dibujar el árbol desde la raíz con la nueva separación vertical
    displayUtil(root, 0, screenWidth / 2, 200, horizontalSeparation, offsetY);

    // Dibujar los nodos con sus posiciones calculadas
    for (const auto& treeNode : nodes) {
        Color nodeColor = (treeNode.node->color == 0) ? BLACK : RED;
        DrawCircleV(treeNode.position, 40, nodeColor);
        string text = to_string(treeNode.node->data);
        DrawText(text.c_str(), (int)(treeNode.position.x - MeasureText(text.c_str(), 20) / 2),
                 (int)(treeNode.position.y - 20 / 2), 20, WHITE);
    }
}


int main() {
    // Create a RedBlackTree of integers
    RedBlackTree<int> arbol;

    // Initialize window
    InitWindow(screenWidth, screenHeight, "Red-Black Tree Display");

    // Input variables and rectangles
    char inputTextInsert[64] = { 0 };
    char inputTextDelete[64] = { 0 };
    char inputTextSearch[64] = { 0 };

    int textLengthInsert = 0;
    int textLengthDelete = 0;
    int textLengthSearch = 0;

    Rectangle inputBoxInsert = { 10, 40, 200, 50 };
    Rectangle inputBoxDelete = { 450, 40, 200, 50 };
    Rectangle inputBoxSearch = { 900, 40, 200, 50 };

    Rectangle insertButton = { 220, 40, 180, 50 };
    Rectangle deleteButton = { 670, 40, 180, 50 };
    Rectangle searchButton = { 1120, 40, 180, 50 };

    int elapsedTime;

    Node<int>* searchNode;
    int searchNum;
    bool showSearchInformation = false;

    int deleteNum;
    bool showDeleteInformation = false;


    while (!WindowShouldClose()) {

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePoint = GetMousePosition();

            if (CheckCollisionPointRec(mousePoint, insertButton)) {
                showSearchInformation = false;
                showDeleteInformation = false;
                inputTextInsert[textLengthInsert] = '\0';
                int number = atoi(inputTextInsert);
                arbol.insert(number);

                for (int i = 0; i < textLengthInsert; ++i) {
                    inputTextInsert[i] = '\0';
                }
                textLengthInsert = 0;

            } else if (CheckCollisionPointRec(mousePoint, deleteButton)) {
                showSearchInformation = false;
                showDeleteInformation = false;

                inputTextDelete[textLengthDelete] = '\0';
                int number = atoi(inputTextDelete);
                deleteNum = number;
                arbol.remove(number);

                for (int i = 0; i < textLengthDelete; ++i) {
                    inputTextDelete[i] = '\0';
                }
                textLengthDelete = 0;
            } else if (CheckCollisionPointRec(mousePoint, searchButton)) {
                showSearchInformation = false;
                showDeleteInformation = false;
                inputTextSearch[textLengthSearch] = '\0';
                int number = atoi(inputTextSearch);
                searchNum = number;
                searchNode = arbol.search(number);
                showSearchInformation = true;

                for (int i = 0; i < textLengthSearch; ++i) {
                    inputTextSearch[i] = '\0';
                }
                textLengthSearch = 0;
            }
        }

        // Handle keyboard input
        int keyPressed = GetKeyPressed();
        if (keyPressed != 0) {
            if (keyPressed >= 48 && keyPressed <= 57) { // Accept only numbers
                if (textLengthInsert < 63 && textLengthDelete < 63 && textLengthSearch < 63) {
                    if (CheckCollisionPointRec(GetMousePosition(), inputBoxInsert)) {
                        inputTextInsert[textLengthInsert] = (char)keyPressed;
                        textLengthInsert++;
                    } else if (CheckCollisionPointRec(GetMousePosition(), inputBoxDelete)) {
                        inputTextDelete[textLengthDelete] = (char)keyPressed;
                        textLengthDelete++;
                    } else if (CheckCollisionPointRec(GetMousePosition(), inputBoxSearch)) {
                        inputTextSearch[textLengthSearch] = (char)keyPressed;
                        textLengthSearch++;
                    }
                }
            } else if (keyPressed == KEY_BACKSPACE) {
                if (textLengthInsert > 0 && CheckCollisionPointRec(GetMousePosition(), inputBoxInsert)) {
                    textLengthInsert--;
                    inputTextInsert[textLengthInsert] = '\0';
                } else if (textLengthDelete > 0 && CheckCollisionPointRec(GetMousePosition(), inputBoxDelete)) {
                    textLengthDelete--;
                    inputTextDelete[textLengthDelete] = '\0';
                } else if (textLengthSearch > 0 && CheckCollisionPointRec(GetMousePosition(), inputBoxSearch)) {
                    textLengthSearch--;
                    inputTextSearch[textLengthSearch] = '\0';
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangleRec(inputBoxInsert, LIGHTGRAY);
        DrawText(inputTextInsert, (int)inputBoxInsert.x + 10, (int)inputBoxInsert.y + 10, 30, BLACK);
        DrawRectangleRec(insertButton,  DARKGRAY);
        DrawText("Insertar", (int)insertButton.x + 20, (int)insertButton.y + 10, 30, WHITE);

        DrawRectangleRec(inputBoxDelete, LIGHTGRAY);
        DrawText(inputTextDelete, (int)inputBoxDelete.x + 10, (int)inputBoxDelete.y + 10, 30, BLACK);
        DrawRectangleRec(deleteButton,  DARKGRAY);
        DrawText("Delete", (int)deleteButton.x + 20, (int)deleteButton.y + 10, 30, WHITE);

        DrawRectangleRec(inputBoxSearch, LIGHTGRAY);
        DrawText(inputTextSearch, (int)inputBoxSearch.x + 10, (int)inputBoxSearch.y + 10, 30, BLACK);
        DrawRectangleRec(searchButton,  DARKGRAY);
        DrawText("Search", (int)searchButton.x + 20, (int)searchButton.y + 10, 30, WHITE);

        if(showSearchInformation){

            if(searchNode != nullptr){
                string text = "The number " + to_string(searchNum) + " was found";
                DrawText(text.c_str(),10,100,25,BLACK);

            }
            else{
                string text = "The number " + to_string(searchNum) + " was not found";
                DrawText(text.c_str(),10,100,25,BLACK);
            }

        }

        if(showDeleteInformation){
            string text = "The number " + to_string(deleteNum) + " was deleted";
            DrawText(text.c_str(),10,100,25,BLACK);
        }

        displayRedBlackTree(arbol.getRoot()); // Draw the Red-Black tree

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
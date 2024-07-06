
#include <iostream>
#include <vector>

struct Node {
    int row, col, value;
    Node* next;
    Node(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

Node* insert(Node* head, int row, int col, int value) {
    if (value == 0) return head;
    Node* newNode = new Node(row, col, value);
    if (!head) return newNode;
    Node* current = head;
    while (current->next) current = current->next;
    current->next = newNode;
    return head;
}

void displayMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) std::cout << val << " ";
        std::cout << std::endl;
    }
}

void displayLinkedList(Node* head) {
    std::cout << "Linked List of Non-Zero Elements:\n";
    std::cout << "Row\tColumn\tValue\tNext Node Address\n";
    for (Node* current = head; current; current = current->next) {
        std::cout << current->row << "\t" << current->col << "\t" 
                  << current->value << "\t" << static_cast<void*>(current->next) << "\n";
    }
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int rows, cols;
    std::cout << "Number of rows: ";
    std::cin >> rows;
    std::cout << "Number of columns: ";
    std::cin >> cols;

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    std::cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "\nMatrix:\n";
    displayMatrix(matrix);

    Node* head = nullptr;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            head = insert(head, i, j, matrix[i][j]);
        }
    }

    displayLinkedList(head);
    freeList(head);

    return 0;
}

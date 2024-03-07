#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Định nghĩa cấu trúc Node cho danh sách liên kết kép
struct Node {
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Lớp DoublyLinkedList
class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr) {}

    // Hàm khởi tạo danh sách liên kết kép
    void initializeList() {
        head = nullptr;
    }

    // Hàm cấp phát miền nhớ cho một node
    Node* createNode(int value) {
        return new Node(value);
    }

    // Hàm thêm node vào đầu bên trái danh sách liên kết kép
    void insertAtLeftFront(int value) {
        Node* newNode = createNode(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Hàm thêm node vào đầu bên phải danh sách
    void insertAtRightFront(int value) {
        Node* newNode = createNode(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Hàm thêm node vào giữa danh sách liên kết kép
    void insertInMiddle(int value, int position) {
        Node* newNode = createNode(value);
        if (head == nullptr || position <= 0) {
            insertAtLeftFront(value);
        } else {
            Node* temp = head;
            for (int i = 0; i < position - 1 && temp->next != nullptr; ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
    }

    // Hàm loại bỏ node cuối bên trái danh sách
    void deleteAtLeftBack() {
        if (head == nullptr) {
            cout << "Danh sách rỗng.\n";
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = nullptr;
            delete temp;
        } else {
            // Nếu chỉ có một node trong danh sách
            delete temp;
            head = nullptr;
        }
    }

    // Hàm loại bỏ node cuối bên phải danh sách
    void deleteAtRightBack() {
        if (head == nullptr) {
            cout << "Danh sách rỗng.\n";
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = nullptr;
            delete temp;
        } else {
            // Nếu chỉ có một node trong danh sách
            delete temp;
            head = nullptr;
        }
    }

    // Hàm loại bỏ node ở giữa danh sách
    void deleteInMiddle(int position) {
        if (head == nullptr) {
            cout << "Danh sách rỗng.\n";
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position && temp->next != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    // Hàm duyệt trái danh sách
    void traverseLeft() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Hàm duyệt phải danh sách
    void traverseRight() {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    // Hàm tìm node trên danh sách
    int searchNode(int value) {
        Node* temp = head;
        int pos = 0;
        while (temp != nullptr) {
            if (temp->data == value) {
                return pos;
            }
            temp = temp->next;
            ++pos;
        }
        return -1; // Trả về -1 nếu không tìm thấy giá trị
    }
};

int main() {
    DoublyLinkedList myDoublyList;
    myDoublyList.initializeList();

    myDoublyList.insertAtLeftFront(3);
    myDoublyList.insertAtRightFront(7);
    myDoublyList.insertInMiddle(5, 1);
    myDoublyList.traverseLeft();

    myDoublyList.deleteAtLeftBack();
    myDoublyList.traverseLeft();

    myDoublyList.deleteAtRightBack();
    myDoublyList.traverseLeft();

    myDoublyList.insertInMiddle(8, 1);
    myDoublyList.deleteInMiddle(1);
    myDoublyList.traverseLeft();

    myDoublyList.traverseRight();

    int position = myDoublyList.searchNode(7);
    if (position != -1) {
        cout << "Node 7 được tìm thấy tại vị trí " << position << endl;
    } else {
        cout << "Node 7 không được tìm thấy trong danh sách.\n";
    }

    return 0;
}
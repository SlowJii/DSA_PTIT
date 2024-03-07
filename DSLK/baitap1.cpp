#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Định nghĩa cấu trúc Node
struct Node
{
    int data;
    Node *next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

// Lớp LinkedList
class LinkedList
{
private:
    Node *head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Hàm khởi tạo danh sách liên kết đơn
    void initializeList()
    {
        head = nullptr;
    }

    // Hàm chèn node vào đầu danh sách
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Hàm chèn node vào cuối danh sách
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Hàm chèn node vào vị trí xác định trong danh sách
    void insertAtPosition(int value, int pos)
    {
        Node *newNode = new Node(value);
        if (pos == 0 || head == nullptr)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < pos - 1 && temp != nullptr; ++i)
            {
                temp = temp->next;
            }
            if (temp != nullptr)
            {
                newNode->next = temp->next;
                temp->next = newNode;
            }
            else
            {
                cout << "Vị trí không hợp lệ.\n";
            }
        }
    }

    // Hàm loại bỏ node tại vị trí Pos trong danh sách
    void deleteAtPosition(int pos)
    {
        if (head == nullptr)
        {
            cout << "Danh sách rỗng.\n";
            return;
        }
        Node *temp = head;
        if (pos == 0)
        {
            head = head->next;
            delete temp;
        }
        else
        {
            for (int i = 0; i < pos - 1 && temp->next != nullptr; ++i)
            {
                temp = temp->next;
            }
            if (temp->next != nullptr)
            {
                Node *nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            }
            else
            {
                cout << "Vị trí không hợp lệ.\n";
            }
        }
    }

    // Hàm sửa đổi nội dung node trong danh sách
    void modifyNode(int oldValue, int newValue)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == oldValue)
            {
                temp->data = newValue;
                return;
            }
            temp = temp->next;
        }
        cout << "Không tìm thấy giá trị cần sửa đổi.\n";
    }

    // Hàm sắp xếp danh sách liên kết đơn
    void sortList()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        Node *current = head;
        Node *nextNode = nullptr;
        while (current != nullptr)
        {
            nextNode = current->next;
            while (nextNode != nullptr)
            {
                if (current->data > nextNode->data)
                {
                    swap(current->data, nextNode->data);
                }
                nextNode = nextNode->next;
            }
            current = current->next;
        }
    }

    // Hàm đảo ngược danh sách liên kết đơn
    void reverseList()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *nextNode = nullptr;
        while (current != nullptr)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }

    // Hàm tìm kiếm vị trí của node trong danh sách
    int searchNode(int value)
    {
        Node *temp = head;
        int pos = 0;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                return pos;
            }
            temp = temp->next;
            ++pos;
        }
        return -1; // Trả về -1 nếu không tìm thấy giá trị
    }

    // Hàm hiển thị nội dung trong danh sách
    void displayList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList myList;
    myList.initializeList();

    int start;
    cin >> start;
    myList.insertAtBeginning(start);

    int end;
    cin >> end;
    myList.insertAtEnd(end);

    int value, position;
    cin >> value >> position;
    myList.insertAtPosition(value, position);
    myList.displayList();

    int pos;
    cin >> pos;
    myList.deleteAtPosition(pos);
    myList.displayList();

    int oldValue, newValue;
    cin >> oldValue >> newValue;
    myList.modifyNode(oldValue, newValue);
    myList.displayList();

    myList.sortList();
    myList.displayList();

    myList.reverseList();
    myList.displayList();

    int mustfind;
    cin >> mustfind;
    int position = myList.searchNode(mustfind);
    if (position != -1)
    {
        cout << "Node " << mustfind << "được tìm thấy tại vị trí " << position << endl;
    }
    else
    {
        cout << "Node " << mustfind << "không được tìm thấy trong danh sách."<<endl;
    }

    return 0;
}
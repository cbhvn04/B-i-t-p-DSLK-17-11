#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Định nghĩa cấu trúc `Node`
struct Node {
    int value;
    struct Node *next;
};

// Hàm tạo một `Node` mới
struct Node* createNode(int val) {
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->value = val;
    temp->next = NULL;
    return temp;
}

// Hàm in danh sách liên kết
void printList(struct Node *head) {
    struct Node *current = head;
    printf(u8"\nDanh sách: ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}

// Hàm xóa đầu danh sách
struct Node* deleteHead(struct Node *head) {
    if (head == NULL) {
        printf(u8"\nDanh sách rỗng!");
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Hàm xóa cuối danh sách
struct Node* deleteTail(struct Node *head) {
    if (head == NULL) {
        printf(u8"\nDanh sách rỗng!");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

// Xóa phần tử đứng sau một giá trị XX
struct Node* deleteAfterValue(struct Node *head, int val) {
    if (head == NULL) {
        printf(u8"\nDanh sách rỗng!");
        return NULL;
    }
    struct Node *current = head;
    while (current != NULL && current->value != val) {
        current = current->next;
    }
    if (current == NULL) {
        printf(u8"\nKhông tìm thấy giá trị %d trong danh sách!", val);
        return head;
    }
    if (current->next == NULL) {
        printf(u8"\nKhông có phần tử sau giá trị %d để xóa!", val);
        return head;
    }struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

// Chương trình
int main() {
    SetConsoleOutputCP(CP_UTF8); // Đặt mã hóa UTF-8 cho console
    struct Node *head = NULL;
    // Tạo danh sách mẫu
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    printf(u8"\nDanh sách ban đầu:");
    printList(head);
    printf(u8"\n\nXóa đầu:");
    head = deleteHead(head); // Cập nhật head sau khi xóa đầu
    printList(head);
    printf(u8"\n\nXóa cuối:");
    head = deleteTail(head); // Cập nhật head sau khi xóa cuối
    printList(head);
    printf(u8"\n\nXóa phần tử sau giá trị 20:");
    head = deleteAfterValue(head, 20); // Cập nhật head sau khi xóa phần tử
    printList(head);
    printf(u8"\n");
    return 0;
}

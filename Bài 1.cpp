#include<stdio.h>
#include<stdlib.h>

// Định nghĩa cấu trúc `Node`
struct Node {
    int value;       // Đổi tên `data` thành `value`
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
    printf("\nDanh sách: ");
    while(current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}

// Hàm xóa đầu danh sách
struct Node* deleteHead(struct Node *head) {
    if(head == NULL) {
        printf("\nDanh sách rỗng!");
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Hàm xóa cuối danh sách
struct Node* deleteTail(struct Node *head) {
    if(head == NULL) {
        printf("\nDanh sách rỗng!");
        return NULL;
    }
    if(head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node *current = head;
    while(current->next->next != NULL) {
        current = current->next;}
    free(current->next);
    current->next = NULL;
    return head;
}

// Xóa phần tử đứng sau một giá trị XX
struct Node* deleteAfterValue(struct Node *head, int val) {
    if(head == NULL) {
        printf("\nDanh sách rỗng!");
        return NULL;
    }
    struct Node *current = head;
    while(current != NULL && current->value != val) {
        current = current->next;
    }if(current == NULL) {
        printf("\nKhông tìm thấy giá trị %d trong danh sách!", val);
        return head;
    }
    if(current->next == NULL) {
        printf("\nKhông có phần tử sau giá trị %d để xóa!", val);
        return head;
    }
    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

// Chương trình
int main() {
    struct Node *head = NULL;
    // Tạo danh sách mẫu
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    printf("\nDanh sách ban đầu:");
    printList(head);
    printf("\n\nXóa đầu:"); // Thực hiện xóa phần tử đầu tiên từ danh sách ban đầu
    printList(deleteHead(head));
    printf("\n\nXóa cuối:"); // Thực hiện xóa phần tử cuối cùng từ danh sách ban đầu
    printList(deleteTail(head));
    printf("\n\nXóa phần tử sau giá trị 20:"); // Thực hiện xóa phần tử sau giá trị 20
    printList(deleteAfterValue(head, 20));
    printf("\n");
    return 0;
}

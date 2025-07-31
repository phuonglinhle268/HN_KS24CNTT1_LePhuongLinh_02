#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[15];
    char email[50];
}Contact;

typedef struct TreeNode {
    Contact data;
    struct TreeNode *left;
    struct TreeNode* right;
}TreeNode;
TreeNode* createNode(Contact data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}
TreeNode* insert(TreeNode* root, Contact data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (strcmp(data.name, root -> data.name) < 0) {
        root -> left = insert(root -> left, data);
    } else if (strcmp(data.name, root -> data.name) > 0) {
        root -> right = insert(root -> right, data);
    }
    return root;
}

void inOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root -> left);
    printf("Ten: %s | So dien thoai: %s | Email: %s\n", root -> data.name, root->data.phone, root->data.email);
    inOrder(root -> right);
}
int main() {
    int choice;
    TreeNode* root = NULL;
    Contact contact;
    do {
        printf("\n---QUAN LI DANH BA---\n");
        printf("1. Them nguoi dung vao danh ba\n");
        printf("2. Hien thi danh ba theo ABC\n");
        printf("3. Tim nguoi dung theo ten\n");
        printf("4. Xoa nguoi theo ten\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                getchar();
                printf("Nhap ho ten: ");
                fgets(contact.name, 50, stdin);
                contact.name[strcspn(contact.name, "\n")] = 0;
                printf("Nhap so dien thoai: ");
                fgets(contact.phone, 15, stdin);
                contact.phone[strcspn(contact.phone, "\n")] = 0;
                printf("Nhap email: ");
                fgets(contact.email, 50, stdin);
                contact.email[strcspn(contact.email, "\n")] = 0;
                root = insert(root,contact);
                printf("Da them thanh cong\n");
                break;
            case 2:
                if (root == NULL) {
                    printf("Danh ba trong\n");
                } else {
                    printf("Danh ba: \n");
                    inOrder(root);
                }
                break;
            case 3:
                printf("Nhap ten can tim: ");
                fgets(contact.name, 50, stdin);
                contact.name[strcspn(contact.name, "\n")] = 0;
                break;
            case 4:
                printf("Nhap ten can xoa: ");
                fgets(contact.name, 50, stdin);
                contact.name[strcspn(contact.name, "\n")] = 0;
            case 5:
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    }while (choice != 5);
    return 0;
}

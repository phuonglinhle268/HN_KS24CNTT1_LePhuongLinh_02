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
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
}
TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root -> data) {
        root -> left = insert(root -> left, data);
    } else if (data > root -> data) {
        root -> right = insert(root -> right, data);
    } else {
        printf("Gia tri da ton tai\n");
    }
    return root;
}
int checkName(const char* newName) {
    TreeNode* current = root;
    while (current != NULL) {
        char tempNew[100], tempCurrent[100];
        strcpy(tempNew, newName);
        strcpy(tempCurrent, current -> data.name);

        for (int i = 0; tempNew[i]; i++) {
            tolower((unsigned char)tempNew[i]);
        }
        for (int i = 0; tempCurrent[i]; i++) {
            tolower((unsigned char)tempCurrent[i]);
        }
        if (strcmp(tempNew, temCurrent)==0) {
            return 1;
        }
        current = current -> left;
    }
    return 0;
}
void inOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root -> left);
    printf("%s\n", root -> data.name);
    inOrder(root -> right);
}
int main() {
    int choice;
    TreeNode* root = NULL;
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
                printf("Nhap ten: ");
                fgets(temp ,50, sdin);
                temp[strcspn(temp, "\n")] = '\0';
                printf("Nhap so dien thoai: ");
                fgets();
                printf("Nhap email: ");
                root = insert(root, value);
                printf("Da them thanh cong\n");
                break;
            case 2:
                printf("Nhap ten muon xoa: ");

                root = delete(root, value);
                break;
            case 5:
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    }while (choice != 5);
    return 0;
}

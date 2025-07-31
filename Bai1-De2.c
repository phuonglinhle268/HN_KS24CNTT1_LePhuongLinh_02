#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char string[100];
}Clipboard;

typedef struct Stack {
    Clipboard* clipboards;
    int capacity;
    int top;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack -> top = -1;
    stack -> clipboards = (Clipboard*)malloc(capacity * sizeof(Clipboard));
    return stack;
}
Clipboard createClipboard() {
    Clipboard clipboard;
    printf("Nhap doan van ban: ");
    fgets(clipboard.string, sizeof(clipboard.string), stdin);
    clipboard.string[strcspn(clipboard.string, "\n")] = 0;
    return clipboard;
}
void push(Stack* stack, Clipboard clipboard) {
    if (stack -> top == stack -> capacity - 1) {
        printf("Stack day\n");
        return;
    }
    stack -> top++;
    stack -> clipboards[stack -> top] = clipboard;
}
Clipboard pop(Stack* stack) {
    if (stack -> top == -1) {
        printf("Stack rong\n");
        return;
    }
    Clipboard clipboard = stack -> clipboards[stack -> top];
    stack -> top--;
    return clipboard;
}
int isEmpty(Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

void peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Clipboard hien tai la: %s\n", stack->clipboards[stack->top].string);
}
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack rong\n");
        return;
    }
    printf("\n-----Noi dung clipboard-----\n");
    for (int i=0l; i<= stack->top; i++) {
        printf("%d. %s\n", i+1, stack -> clipboards[i].string);
    }
}
int main() {
    int choice;
    Stack* clipboardStack = createStack(50);
    Stack* redoStack = createStack(50);
    do {
        printf("\n-----CLIPBOARD MANAGER-----\n");
        printf("1. Copy: sao chep doan van ban moi\n");
        printf("2. Paste: dan noi dung vua sao chep\n");
        printf("3. Undo: Hoan tac lenh sao chep gan nhat\n");
        printf("4. Redo: phuc hoi lenh vua undo\n");
        printf("5. Hien thi toan bo noi dung clipboard\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Clipboard clipboard = createClipboard();
                push(clipboardStack, clipboard);
                break;
            case 2:
                peek(clipboardStack);
                break;
            case 3:
                if (isEmpty(clipboardStack)) {
                    printf("Khong co clipboard\n");
                    break;
                }
                Clipboard currentCLipboard = pop(clipboardStack);
                push(redoStack, currentCLipboard);
                break;
            case 4:
                if (isEmpty(redoStack)) {
                    printf("Khong co noi dung\n");
                    break;
                }
                Clipboard redoClipboard = pop(redoStack);
                push(clipboardStack, redoClipboard);
                break;
            case 5:
                display(clipboardStack);
                break;
            case 6:
                printf("Thoat\n");
                break;
        }
    } while (choice != 6);
    return 0;
}







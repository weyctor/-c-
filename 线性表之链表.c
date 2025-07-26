#include <stdio.h>
#include <windows.h>

//定义书
typedef struct {
    char bookname[20];
    double price;
}book;

//自定义书名和价格
book newbook(void) {
    book newbook;
    char a[20];
    double b;
    printf_s("请输入书名和价格\n");
    printf_s("书名：");
    scanf_s("%s", a,20);
    printf_s("价格：");
    scanf_s("%lf", &b);
    strcpy(newbook.bookname,a);
    newbook.price = b;
    return newbook;
}

//定义链表
typedef struct node {
    book data;
    struct node *next;
    struct node *previous;
}Node;
// 定义包含头尾指针的结构体
typedef struct {
    Node* head;  // 头指针
    Node* tail;  // 尾指针
} List;

//初始化链表，head就是头
List* initlist() {
    List* a = (List*)malloc(sizeof(List));
    a->head->next = a->tail;
    a->tail->next = NULL;
    a->head->previous = NULL;
    a->tail->previous = a->head;
    return a;
}

//头插法,传入的参数为头部,p为要插入的链表元素
int insertHead(const List* L) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = newbook();
    p->next = L->head->next;
    p->previous = L->head;
    L->head->next->previous = p;
    L->head->next = p;
    return 1;
}

//尾插法,传入的参数为尾部，p为要插入的链表元素
int insertTail(const List* T) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = newbook();
    p->previous = T->tail->previous;
    p->next = T->tail;
    T->tail->previous->next = p;
    T->tail->previous = p;
    return 1;
}
//指定位置插入
int myinsert(const List* L) {
    Node *q = L->head;
    int a;
    int b = 0;
    printf_s("选择要插入的位置：");
    scanf_s("%d", &a);
    while (b < a-1) {
        q = q->next;
        b++;
        if (q == NULL) {
            return 0;
        }
    }
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = newbook();
    p->previous = q;
    p->next = q->next;
    q->next = p;
    q->previous = p->previous->previous;
    return 1;
}
//头遍历
void listNode(const List* L) {
    Node *p = L->head->next;
    while (p->next != NULL) {
        printf_s("书名：%s 价格：%lf\n", p->data.bookname, p->data.price);
        p = p->next;
    }
    printf_s("\n");
}
void freelist(List* L) {
    Node *p = L->head->next;
    while (p != NULL) {
        Node* next = p->next;
        free(p);
        p = next;
    }
    printf_s("\n");
    free(L->head);
    free(L->tail);
    free(L);
}
int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    List *list = initlist();
    insertHead(list);
    insertTail(list);
    insertTail(list);
    myinsert(list);
    listNode(list);
    free(list);
    return 0;
}
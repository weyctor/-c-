#include <stdio.h>
#include <windows.h>
#define maxnum 100
//图书结构体
typedef struct {
    char bookname[20];
    double price;
}book;
//顺序表结构体
typedef struct {
    book id[maxnum];
    int length;
}booklist;
//初始化顺序表,参数为某个顺序表
void initlist(booklist *l) {
    l -> length = 0;
}
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
//在尾部添加图书,两个参数分别为书，书所属的顺序表
int addbook(booklist *l) {

    if (l->length > maxnum) {
        printf_s("图书数量已达上限\n");
        return 0;
    }
    l->id[l->length] = newbook();
    l->length++;
    return 1;
}
void lookbook(booklist *l) {
    if (l->length == 0) {
        printf_s("对不起，目前没有图书\n");
    }
    for (int a = 0;a < l->length;a++) {
        printf_s("第%d本，书名：%s，价格：%.2lf\n", a+1, l->id[a].bookname, l->id[a].price);
        Sleep(800);
    }
}
//插入一本图书
int addbook2(booklist *l) {
    int a;
    printf_s("请输入要插入图书的位置：");
    scanf_s("%d", &a);
    for (int b=l->length-1; b>=a-1; b--) {
        l->id[b+1] = l->id[b];
    }
    if (l->length >= maxnum) {
        printf_s("图书数量已达上限\n");
        return 0;
    }
    if (a < 1 || a > l->length + 1) {
        printf_s("插入位置无效\n");
        return 0;
    }
    l->id[a-1] = newbook();
    l->length++;
    printf_s("插入成功！");
    return 1;
}
//删除一本图书
int delbook(booklist *l) {
    char a[20];
    printf_s("请输入要删除的图书的名字：");
    scanf_s("%s", a);
    for (int b = 0;b < l->length;b++) {
        if (strcmp(a, l->id[b].bookname) == 0) {
            for (;b < l->length-1;b++) {
                l->id[b] = l->id[b+1];
            }
            printf_s("删除成功！");
            l->length--;
            return 1;
        }
    }
    printf_s("删除失败~");
    return 0;
}
int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    booklist a;
    initlist(&a);
    int b;
    while (1) {
        b = 0;
        printf_s("\n请选择功能\n1.添加图书\n2.列出所有图书\n3.插入图书\n4.删除图书\n5.退出\n");
        scanf_s("%d", &b);
        switch (b) {
            case 1:addbook(&a);break;
            case 2:lookbook(&a);break;
            case 3:addbook2(&a);break;
            case 4:delbook(&a);break;
            case 5:goto loop;
            default:printf_s("请重新输入！");rewind(stdin);break;
        }
    }
    loop:
    return 0;
}
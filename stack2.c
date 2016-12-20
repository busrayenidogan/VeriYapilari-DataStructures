#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int sayi;
    struct stack *next;
};

struct stack *root=NULL;
void push(int x);
void pop();
void list();

int main()
{
    int secim,sayi;
    while(1)
    {
        printf("[1]Push()\n[2]Pop()\n[3]List\n[4]Exit\nSeçim : ");
        scanf("%d",&secim);

        switch(secim)
        {
            case 1:
                printf("Bir sayi giriniz : ");
                scanf("%d",&sayi);
                push(sayi);
                break;
            case 2:
                pop();
                break;
            case 3:
                list();
                break;
            case 4:
                exit(0);
            default:
                printf("Geçersiz işlem.\n");
        }
    }
}
void push(int x) //aslında bağlı listede basa eklemedir
{
    if (root == NULL)
    {
        root = (struct stack*)malloc(sizeof(struct stack));
        root->sayi=x;
        root->next=NULL;
    }
    else
    {
        struct stack *temp = (struct stack*)malloc(sizeof(struct stack));
        temp->sayi=x;
        temp->next=root;
        root=temp;
    }
}
void pop()
{
    if (root == NULL)
    {
        printf("Stack bos.\n");
    }
    else
    {
        struct stack *temp;

        temp = root;
        root = root->next;
        free(temp);
    }
}
void list()
{
    if (root == NULL)
    {
        printf("Stack bos.\n");
    }
    else
    {
        struct stack *temp=root;
        while (temp->next != NULL)
        {
            printf("--------\n");
            printf("  %d\n",temp->sayi);
            temp = temp->next;
        }
        printf("--------\n");
        printf("  %d\n",temp->sayi);
    }
}

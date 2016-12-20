#include <stdio.h>
#include <stdlib.h>
//stack

struct stack
{
    int sayi;
    struct stack *next;
};

struct stack *root=NULL,*ilk=NULL;

void push(int x);
void pop();
void yazdir();

int main()
{
    int secim,deger;

    while(1)
    {
        printf("[1]Ekleme\n[2]Silme\n[3]Listeleme\n[4]Çıkış\nSecim : ");
        scanf("%d",&secim);

        switch(secim)
        {
            case 1:
                printf("Bir sayi giriniz : ");
                scanf("%d",&deger);
                push(deger);
                break;
            case 2:
                pop();
                break;
            case 3:
                yazdir();
                break;
            case 4:
                exit(0);
                default:
                    printf("Gecersiz islem.\n");
        }
    }
}
void push(int x)
{
    struct stack *temp2;
    if (root == NULL)
    {
        root = (struct stack*)malloc(sizeof(struct stack));
        root->sayi=x;
        root->next=NULL;
        ilk=root;
    }
    else
    {
        temp2 = (struct stack*)malloc(sizeof(struct stack));
        temp2->sayi=x;
        root->next=temp2;
        temp2->next=NULL;
        root=temp2;
    }
}
void pop()
{
    struct stack *temp2=ilk,*onceki=ilk;
    if (root == NULL)
    {
        printf("Yigin zaten bos.\n");
    }
    else
    {
        while (temp2->next != NULL)
        {
            onceki=temp2;
            temp2 = temp2->next;
        }
        if (temp2->next == NULL)
        {
            if (root == onceki)
            {
                free(root);
                root=NULL;
            }
            else
            {
                onceki->next=NULL;
                root=onceki;
                free(temp2);
            }
        }
    }
}
void yazdir()
{
    struct stack *temp2=ilk;
    int i=1;
    if (root == NULL)
    {
        printf("Liste bos.\n");
    }
    else
    {
        printf("\n[Base]\n");
        while(temp2->next != NULL)
        {
            printf("%d.Sayi = %d\n",i++,temp2->sayi);
            temp2 = temp2->next;
        }
        printf("%d.Sayi = %d\n",i++,temp2->sayi);
        printf("\n[Top]\n");
    }
}

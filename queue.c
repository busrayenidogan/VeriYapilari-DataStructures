#include <stdio.h>
#include <stdlib.h>
#define BOYUT 10
//dizi ile dairesek kuyruk
struct kuyruk
{
    int son;
    int eleman[BOYUT];
};

struct kuyruk *root=NULL;
void enqueu(int x);
void yazdir();

int main()
{
    int deger,secim;

    while(1)
    {
        printf("[1]Ekle\n[2]Sil\n[3]Listele\n[4]Cikis\nSecim : ");
        scanf("%d",&secim);

        switch(secim)
        {
            case 1:
                printf("Bir sayi giriniz : ");
                scanf("%d",&deger);
                enqueu(deger);
                break;
            case 3:
                yazdir();
                break;
            case 4:
                exit(EXIT_FAILURE);
        }
    }
}
void enqueu(int x)
{
    struct kuyruk *temp2;

    if (root == NULL)
    {
        root = (struct kuyruk*)malloc(sizeof(struct kuyruk));
        root->son=0;
        root->eleman[root->son]=x;
    }
    else if (root->son == BOYUT-1)
    {
        printf("Kuyruk dolu.\n");
    }
    else
    {
        temp2 = (struct kuyruk*)malloc(sizeof(struct kuyruk));
        temp2->son +=1;
        temp2->eleman[temp2->son]=x;
        root=temp2;
    }
}
void yazdir()
{
    int i=1;
    if (root == NULL)
    {
        printf("Kuyruk bos.\n");
    }
    else
    {
        while (root->son != -1)
        {
            printf("%.d Sayi = %d\n",i++,root->eleman[root->son]);
            root->son -=1;
        }
    }
}

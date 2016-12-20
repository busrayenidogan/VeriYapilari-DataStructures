#include <stdio.h>
#include <stdlib.h>
//Cift bagli dairesel

struct liste
{
    int sayi;
    struct liste *prev;
    struct liste *next;
};

struct liste *ilk=NULL;

struct liste *basaEkle(struct liste *temp,int x);
struct liste *sonaEkle(struct liste *temp,int x);
struct liste *arayaEkle(struct liste *temp,int x);
struct liste *silme(struct liste *temp,int x);
void basiYazdir(struct liste *temp);
void sonuYazdir(struct liste *temp);

int main()
{
    struct liste *root=NULL;
    int secim,deger;

    while (1==1)
    {
        printf("[1]Basa Ekle\n[2]Sona Ekle\n[3]Silme\n[4]Basi Listele\n[5]Sonu Listele\n[6]Araya Ekle\nSecim : ");
        scanf("%d",&secim);

        switch (secim)
        {
            case 1:
                printf("Bir sayi giriniz : ");
                scanf("%d",&deger);
                root=basaEkle(root,deger);
                break;
            case 2:
                printf("Bir sayi giriniz : ");
                scanf("%d",&deger);
                root=sonaEkle(root,deger);
                break;
            case 3:
                printf("Silmek istediginiz sayiyi giriniz : ");
                scanf("%d",&deger);
                root=silme(root,deger);
                break;
            case 4:
                basiYazdir(root);
                break;
            case 5:
                sonuYazdir(root);
                break;
            case 6:
                printf("Bir sayi giriniz : ");
                scanf("%d",&deger);
                root=arayaEkle(root,deger);
                break;
                default:
                    printf("Geçersiz işlem.\n");
        }
    }
}
struct liste *basaEkle(struct liste *temp,int x)
{
   struct liste *temp2,*temp3;

   if (temp == NULL)
   {
        temp = (struct liste*)malloc(sizeof(struct liste));
        temp->sayi=x;
        temp->prev=temp;
        temp->next=temp;
        ilk=temp;

        return ilk;
   }
   else
   {
        temp3 = (struct liste*)malloc(sizeof(struct liste));
        temp3->sayi=x;
        temp2=ilk;
        while (temp2->prev != ilk)
        {
            temp2 = temp2->prev;
        }
        temp2->prev=temp3;
        temp3->next=temp2;
        temp3->prev=ilk;
        ilk->next=temp3;

        return ilk;
   }
}
struct liste *sonaEkle(struct liste *temp,int x)
{
    struct liste *temp2,*temp3;

    if (temp == NULL)
    {
        temp = (struct liste*)malloc(sizeof(struct liste));
        temp->sayi=x;
        temp->prev=temp;
        temp->next=temp;
        ilk=temp;

        return ilk;
    }
    else
    {
        temp3 = (struct liste*)malloc(sizeof(struct liste));
        temp3->sayi=x;
        temp2=ilk;
        while (temp2->next != ilk)
        {
            temp2 = temp2->next;
        }
        temp2->next=temp3;
        temp3->prev=temp2;
        temp3->next=ilk;
        ilk->prev=temp3;

        return ilk;
    }
}
struct liste *silme(struct liste *temp,int x)
{
    struct liste *temp2,*son;

    if (temp == NULL)
    {
        printf("Liste bos.\n");
        return ilk;
    }
    else
    {
        temp2=ilk;
        son=ilk;
        if (temp2->next == ilk && temp2->prev == ilk)
        {
            if (temp2->sayi == x)
            {
                free(temp2);
                ilk=NULL;
                return ilk;
            }
        }
        while (temp2->next != ilk)
        {
            if (temp2->sayi == x && temp2->prev == ilk) //bastan silme
            {
                    while (son->next != ilk)
                    {
                        son = son->next;
                    }
                    ilk=temp2->next;
                    temp2->next->prev=son;
                    son->next=temp2->next;
                    free(temp2);

                    return ilk;
            }
            else if (temp2->sayi == x)
            {
                temp2->prev->next=temp2->next;
                temp2->next->prev=temp2->prev;
                free(temp2);

                return ilk;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        if (temp2->next == ilk)
        {
            temp2->prev->next=ilk;
            ilk->prev=temp2->prev;
            free(temp2);

            return ilk;
        }
    }
}
void basiYazdir(struct liste *temp)
{
    struct liste *temp2;
    int i=1;

    if (temp == NULL)
    {
        printf("Liste bos.\n");
    }
    else
    {
        temp2=ilk;
        while (temp2->prev !=ilk)
        {
            temp2=temp2->prev;
        }
        while (temp2 !=ilk)
        {
            printf("%d. Sayi = %d\n",i++,temp2->sayi);
            temp2=temp2->next;
        }
        printf("%d. Sayi = %d\n",i++,temp2->sayi);
    }
}
void sonuYazdir(struct liste *temp)
{
    struct liste *temp2;
    int i=1;

    if (temp == NULL)
    {
        printf("Liste bos.\n");
    }
    else
    {
        temp2=ilk;
        while (temp2->next != ilk)
        {
            printf("%d. Sayi = %d\n",i++,temp2->sayi);
            temp2 = temp2->next;
        }
        printf("%d. Sayi = %d\n",i++,temp2->sayi);
    }
}
struct liste *arayaEkle(struct liste *temp,int x)
{
    struct liste *temp2,*temp3,*son;

    if (temp == NULL)
    {
        temp = (struct liste*)malloc(sizeof(struct liste));
        temp->sayi=x;
        temp->prev=temp;
        temp->next=temp;
        ilk=temp;

        return ilk;
    }
    else
    {
        temp3 = (struct liste*)malloc(sizeof(struct liste));
        temp3->sayi=x;
        temp2=ilk;
        son=ilk;
        while (temp2->next != ilk)
        {
            if (temp2->sayi > x) //basa ekle
            {
                temp3->next=temp2;
                temp2->prev=temp3;
                while (son->next != ilk)
                {
                    son = son->next;
                }
                temp3->prev=son;
                son->next=temp3;
                ilk=temp3;

                return ilk;
            }
            else if (temp2->sayi < x && temp2->next->sayi > x)
            {
                temp3->next=temp2->next;
                temp3->prev=temp2;
                temp2->next=temp3;
                temp3->next->prev=temp3;

                return ilk;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp2->next=temp3;
        temp3->prev=temp2;
        temp3->next=ilk;
        ilk->prev=temp3;
    }
}

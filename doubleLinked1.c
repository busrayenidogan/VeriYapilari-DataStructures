#include <stdio.h>
#include <stdlib.h>

struct liste
{
    int sayi;
    struct liste *next; //kendinden sonraki
    struct liste *prev; //kendinden onceki
};

struct liste *ilk=NULL;

struct liste *basaEkle(struct liste *temp,int x);
struct liste *sonaEkle(struct liste *temp,int x);
struct liste *silme(struct liste *temp,int x);
struct liste *siraliEkle(struct liste *temp,int x);
struct liste *arama(struct liste *temp,int x);
void sonuYazdir(struct liste *temp);
void basiYazdir(struct liste *temp);

int main()
{
    struct liste *root=NULL;
    int secim,deger;

    while (1==1)
    {
        printf("[1]Basa Ekle\n[2]Sona Ekle\n[3]Silme\n[4]Basi Listele\n[5]Sonu Listele\n[6]Arama\n[7]Eleman Sayma\n[8]Araya Ekleme\n[9]Liste Silme\n[10]Çıkış\nSecim : ");
        scanf("%d",&secim);

        switch(secim)
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
                printf("Silinecek sayiyi giriniz : ");
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
                printf("Aramak istediginiz sayiyi giriniz : ");
                scanf("%d",&deger);
                arama(root,deger);
                break;
            case 8:
                printf("Bir sayi giriniz : ");
                scanf("%d",&deger);
                root=siraliEkle(root,deger);
                break;
            case 10:
                exit(0);
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
        temp->sayi = x;
        temp->prev=NULL;
        temp->next=NULL;
        ilk=temp;

        return ilk;
    }
    else
    {
        temp3 = (struct liste*)malloc(sizeof(struct liste));
        temp3->sayi=x;
        temp2=ilk;
        while (temp2->prev !=NULL)
        {
            temp2 = temp2->prev;
        }
        if (temp2->prev == NULL)
        {
            temp2->prev=temp3;
            temp3->next=temp2;
            temp3->prev=NULL;

            return ilk;
        }
    }
}
struct liste *sonaEkle(struct liste *temp,int x)
{
    struct liste *temp2,*temp3;

    if (temp==NULL)
    {
        temp = (struct liste*)malloc(sizeof(struct liste));
        temp->sayi=x;
        temp->prev=NULL;
        temp->next=NULL;
        ilk=temp;
        return ilk;
    }
    else
    {
        temp3 = (struct liste*)malloc(sizeof(struct liste));
        temp3->sayi=x;
        temp2=ilk;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        if(temp2->next == NULL)
        {
            temp2->next=temp3;
            temp3->prev=temp2;
            temp3->next=NULL;
            return ilk;
        }
    }
}
struct liste *silme(struct liste *temp,int x)
{
    struct liste *temp2;

    if (temp==NULL)
    {
        printf("Liste bos.\n");
        return ilk;
    }
    else
    {
        temp2=ilk;
        if (temp2->next==NULL)
        {
            free(temp2);
            ilk=NULL;
            return ilk;
        }
        while(temp2->next !=NULL)
        {
            if (temp2->sayi == x && temp2->prev == NULL) //ilk eleman silme
            {
                ilk = temp2->next;
                temp2->next->prev=NULL;
                free(temp2);
                return ilk;
            }
            else if (temp2->sayi ==x)
            {
                temp2->prev->next = temp2->next;
                temp2->next->prev = temp2->prev;
                free(temp2);
                return ilk;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        if (temp2->sayi == x && temp2->next == NULL)
        {
            temp2->prev->next=NULL;
            free(temp2);
            return ilk;
        }
    }
}
void basiYazdir(struct liste *temp) // basa ekleme Yazdırma fonksiyonu
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
        while (temp2->prev !=NULL)
        {
            temp2=temp2->prev;
        }
        while (temp2->next !=NULL)
        {
            printf("%d. Sayi = %d\n",i++,temp2->sayi);
            temp2=temp2->next;
        }
        if (temp2->next == NULL)
        {
            printf("%d. Sayi = %d\n",i++,temp2->sayi);
        }
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
        while (temp2->next !=NULL)
        {
            printf("%d. Sayi = %d\n",i++,temp2->sayi);
            temp2=temp2->next;
        }
        if (temp2->next == NULL)
        {
            printf("%d. Sayi = %d\n",i++,temp2->sayi);
        }
    }
}
struct liste *siraliEkle(struct liste *temp,int x)
{
    struct liste *temp2,*temp3;

    if (temp == NULL)
    {
        temp = (struct liste*)malloc(sizeof(struct liste));
        temp->sayi=x;
        temp->next=NULL;
        temp->prev=NULL;
        ilk=temp;
        return ilk;
    }
    else
    {
        temp3 = (struct liste*)malloc(sizeof(struct liste));
        temp3->sayi=x;
        temp2=ilk;
        if (temp2->prev == NULL && temp2->next == NULL)//ikinci eleman ve son eleman
        {
             if (temp2->sayi < x)
            {
                temp2->next=temp3;
                temp3->next=NULL;
                temp3->prev=temp2;
                return ilk;
            }
            else if (temp2->sayi > x)
            {
                temp3->next=temp2;
                temp2->prev=temp3;
                temp3->prev=NULL;
                ilk=temp3;
                return ilk;
            }
        }
        temp2=ilk;
        while (temp2->next != NULL)//2 eleman ve daha fazlası
        {
            if (temp2->sayi < x && temp2->next->sayi > x)
            {
                temp3->next=temp2->next;
                temp3->prev=temp2;
                temp2->next=temp3;
                return ilk;
            }
            else if (temp2->sayi > x)//en basa ekleme
            {
                temp2->prev=temp3;
                temp3->next=temp2;
                temp3->prev=NULL;
                ilk=temp3;
                return ilk;
            }
            else
            {
                temp2=temp2->next;
            }
        }
        if(temp2->next == NULL)
        {
            temp2->next=temp3;
            temp3->prev=temp2;
            temp3->next=NULL;
            return ilk;
        }
    }
}
struct liste *arama(struct liste *temp,int x)
{
    struct liste *temp2;

    if (temp == NULL)
    {
        printf("Liste bos.\n");
        return;
    }
    else
    {
        temp2=ilk;
        while(temp2->next !=NULL || temp2->next ==NULL)
        {
            if(temp2->sayi == x)
            {
                printf("Sayi = %d\n",temp2->sayi);
                return;
            }
            else
            {
                temp2=temp2->next;
            }
        }
    }
}

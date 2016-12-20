#include <stdio.h>
#include <stdlib.h>

struct liste
{
    int sayi;
    struct liste *next;
};

struct liste *ilk=NULL;

struct liste *ekle(struct liste *temp,int x);
struct liste *silme(struct liste *temp,int x);
struct liste *arayaEkleme(struct liste*temp,int x);
struct liste *arama(struct liste *temp,int x);
//struct liste *listeSil(struct liste *temp);
void yaz(struct liste *temp);
int sayma(struct liste *temp);

int main()
{
    struct liste *bl=NULL;
    int secim,deger;

    while(1==1)
    {
        printf("[1]Ekleme\n[2]Silme\n[3]Listeleme\n[4]Arama\n[5]Eleman Sayma\n[6]Araya Ekleme\n[7]Liste Silme\n[8]Çıkış\nSeçim : ");
        scanf("%d",&secim);

        switch(secim)
        {
            case 1:
                printf("Bir sayi giriniz : ");
                scanf("%d",&deger);
                bl=ekle(bl,deger);
                break;
            case 2:
                printf("Silmek istediğiniz sayiyi giriniz : ");
                scanf("%d",&deger);
                bl=silme(bl,deger);
                break;
            case 3:
                yaz(bl);
                break;
            case 4:
                printf("Aramak istediğiniz sayiyi giriniz : ");
                scanf("%d",&deger);
                arama(bl,deger);
                break;
            case 5:
                printf("%d tane eleman bulunmaktadır.\n",sayma(bl));
                break;
            case 6:
                printf("Bir sayi giriniz : ");
                scanf("%d",&deger);
                bl=arayaEkleme(bl,deger);
                break;
            //case 7:
                //bl=listeSil(bl);
               // break;
            case 8:
                exit(0);
            default:
                printf("Geçersiz işlem\n");
        }
    }
    return 0;
}
struct liste *ekle(struct liste *temp,int x) //sıralıEkleme
{
    struct liste *temp2 = (struct liste*)malloc(sizeof(struct liste));
    if (temp==NULL)//ilk başta eleman yoksa
    {
        temp = (struct liste*)malloc(sizeof(struct liste));
        temp->sayi=x;
        temp->next=NULL;
        ilk=temp;
        return temp;
    }
    else
    {
        temp=ilk;
        while (temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp2->sayi=x;
        temp2->next=NULL;
        temp->next=temp2;
        return temp->next;
    }
}
struct liste *silme(struct liste *temp,int x)//
{
    struct liste *temp2,*temp3;
    if (temp == NULL)
    {
        printf("Liste bos\n");
        return ilk;
    }
    else
    {
        temp2=ilk;
        if(temp2->next == NULL) //tek düğüm varsa
        {
            if (temp2->sayi == x)
            {
                free(temp2);
                ilk=NULL;
                return ilk;
            }
            else
            {
                printf("Aradığınız eleman listede bulunmamaktadır.\n");
                return ilk;
            }
        }
        else
        {
            while(temp2->next != NULL)
            {
               if (temp2->sayi == x) //sadece ilk düğüm için geçerli
               {
                    temp3 = temp2;
                    temp2 = temp2->next;
                    free(temp3);
                    ilk=temp2;
                    return ilk;
               }
               else if(temp2->next->sayi == x)
                {
                    temp3=temp2->next;
                    temp2->next = temp2->next->next;
                    free(temp3);
                    return ilk;
                }
                else
                {
                    temp2 = temp2->next;
                }
            }
            free(temp2->next);
            temp2->next=NULL;
        }
    }
}

struct liste *arayaEkleme(struct liste*temp,int x) //temp ile bl yani en son adres geldi
{
    struct liste *temp2,*temp3;
    temp2 = (struct liste*)malloc(sizeof(struct liste));
    temp3 = (struct liste*)malloc(sizeof(struct liste));


    if (temp == NULL)//listede hiç eleman yok ise
    {
        temp2->sayi=x;
        temp2->next=NULL;
        ilk=temp2;
        return ilk;
    }
    else
    {
           if (temp->next==NULL) //bir tane düğüm var ise
           {
                if(temp->sayi > x)
                {
                    temp2->sayi=x;
                    temp2->next=temp;
                    ilk=temp2;
                    return ilk;
                }
                else
                {
                    temp2->sayi=x;
                    temp2->next=NULL;
                    temp->next=temp2;
                    return ilk;
                }
            }
           else
           {
                temp2=ilk;
                while (temp2->next != NULL) //sadece basa ve ortaya ekleme olur
                {
                    if (ilk->sayi > x) //basa ekleme
                    {
                        temp3->sayi=x;
                        temp3->next=ilk;
                        ilk=temp3;
                        return ilk;
                    }
                    else if (temp2->sayi < x && temp2->next->sayi > x)
                    {
                        temp3->sayi=x;
                        temp3->next=temp2->next;
                        temp2->next=temp3;
                        return ilk;
                    }
                    else
                    {
                        temp2 = temp2->next;
                    }
                }
                temp3->sayi=x;
                temp3->next=NULL;
                temp2->next=temp3;
                return ilk;
           }
    }

}
void yaz(struct liste *temp)
{
    struct liste *temp2=ilk;
    int i=1;

    if (temp == NULL)
    {
        printf("Liste bos.\n");
    }
    else
    {
        while (temp2 !=NULL)
        {
            printf("%d. Sayi = %d\n",i++,temp2->sayi);
            temp2 = temp2->next;
        }
    }
}
struct liste *arama(struct liste *temp,int x)
{
    struct liste *temp2=ilk;

    while (temp2 != NULL)
    {
        if (temp2->sayi == x)
        {
            printf("Aradığınız sayı %d bulundu !\n",temp2->sayi);
            return ilk;
        }
        else
        {
            temp2 = temp2->next;
        }
    }
    printf("Aradığınız sayı listemizde bulunmamaktadır.\n");
}
int sayma(struct liste *temp)
{
    struct liste *temp2=ilk;
    int sayac=0;

    while (temp2 != NULL)
    {
        sayac++;
        temp2 = temp2->next;
    }
    return sayac;
}
/*struct liste *listeSil(struct liste *temp)
{
    struct liste *temp2=ilk,*temp3;

    if (temp2 == NULL)
    {
        printf("Liste bos \n");
        return ilk;
    }
    else
    {
        while(temp2 != NULL)
        {
            temp3=temp2;
            temp2 = temp2->next;
            free(temp3);
        }
        return ilk;
    }
}*/

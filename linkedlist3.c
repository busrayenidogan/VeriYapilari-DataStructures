#include <stdio.h>
#include <stdlib.h>
//tek bağlı dairesel liste
struct liste
{
    int sayi;
    struct liste *next;
};

struct liste *ilk=NULL;

struct liste *basaEkle(struct liste *temp,int x);
struct liste *sonaEkle(struct liste *temp,int x);
struct liste *silme(struct liste *temp,int x);
struct liste *arama(struct liste *temp,int x);
struct liste *sayma(struct liste *temp);
struct liste *arayaEkle(struct liste *temp,int x);
void yazdir(struct liste *temp);

int main()
{
    struct liste *root=NULL;
    int deger,secim,a;

    while(1==1)
    {
        printf("[1]Basa Ekleme\n[2]Sona Ekleme\n[3]Silme\n[4]Listeleme\n[5]Arama\n[6]Eleman Sayma\n[7]Araya Ekleme\n[8]Liste Silme\n[9]Çıkış\nSeçim : ");
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
                yazdir(root);
                break;
            case 5:
                printf("Aramak istediğiniz sayiyi giriniz : ");
                scanf("%d",&deger);
                arama(root,deger);
                break;
            case 6:
                root=sayma(root);
                break;
            case 7:
                printf("Bir sayi giriniz : ");
                scanf("%d",&deger);
                root=arayaEkle(root,deger);
                break;
            case 9:
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
        temp2 = (struct liste*)malloc(sizeof(struct liste));
        temp2->sayi=x;
        temp2->next=temp2;
        ilk=temp2;

        return ilk;
    }
    else
    {
        temp3 = (struct liste*)malloc(sizeof(struct liste));
        temp3->sayi=x;
        temp2=ilk;
        while (temp2 ->next != ilk)
        {
            temp2=temp2->next;
        }
        temp3->next=ilk;
        temp2->next=temp3;
        ilk=temp3;

        return temp3;
    }
}
struct liste *sonaEkle(struct liste *temp,int x)
{
    struct liste *temp2,*temp3;

    if (temp == NULL)
    {
        temp2 = (struct liste*)malloc(sizeof(struct liste));
        temp2->sayi =x;
        temp2->next=temp2;
        ilk=temp2;

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
        temp3->next=ilk;
        temp2->next=temp3;

        return ilk;
    }
}
struct liste *silme(struct liste *temp,int x)
{
    struct liste *temp2,*son,*bironceki,*temp3;

    if(temp == NULL)
    {
        printf("Liste bos.\n");
        return ilk;
    }
    else
    {
        temp2=ilk;
        if (temp2->next ==ilk)
        {
            if (temp2->sayi == x)
            {
                free(temp2);
                ilk=NULL;
                return ilk;
            }
            else
            {
                printf("Aradiginiz eleman listede yoktur.\n");
                return ilk;
            }
        }
        else
        {
            while (temp2->next != ilk)
            {
                if (temp2->sayi == x) //birden fazla düğümde baştan silme
                {
                    son=ilk;
                    while (son->next != ilk)
                    {
                        son = son->next;
                    }
                    son->next=temp2->next;
                    ilk=temp2->next;
                    free(temp2);
                    return ilk;
                }
                else if(temp2->next->sayi == x)
                {
                    temp3=temp2->next;
                    temp2->next=temp2->next->next;
                    free(temp3);
                    return ilk;
                }
                else
                {
                    bironceki=temp2;
                    temp2 =temp2->next;
                }
            }
            if (temp2->sayi == x) //birden fazla düğümde sondan silme
            {
                bironceki->next=ilk;
                free(temp2);
                return ilk;
            }
        }
    }
}
void yazdir(struct liste *temp)
{
    struct liste *temp2=ilk;
    int i=1;

    if (temp2 == NULL)
    {
        printf("Liste bos.\n");
    }
    else if (temp2->next == ilk) //ilk eleman
    {
        printf("%d. Sayi = %d\n",i++,temp2->sayi);
    }
    else
    {
        while (temp2->next != ilk)
        {
            printf("%d. Sayi = %d\n",i++,temp2->sayi);
            temp2 = temp2->next;
        }
        if (temp2->next == ilk)
        {
            printf("%d. Sayi = %d\n",i++,temp2->sayi);
        }
    }
}
struct liste *arama(struct liste *temp,int x)
{
    struct liste *temp2=ilk;

    if (temp2 == NULL)
    {
        printf("Liste bos.\n");
        return ilk;
    }
    else
    {
        while (temp2->next != ilk)
        {
            if (temp2->sayi == x)
            {
                printf("Sayi = %d\n",temp2->sayi);
                return ilk;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        if (temp2->sayi == x)
        {
            printf("Sayi = %d\n",temp2->sayi);
            return ilk;
        }
    }
    printf("Aradıgınız sayi listemizde bulunmamaktadır.\n");
    return ilk;

}
struct liste *sayma(struct liste *temp)
{
    struct liste *temp2=ilk;
    int sayac=0;

    if(temp2 == NULL)
    {
        printf("Eleman sayisi = 0\n");
        return ilk;
    }
    else
    {
        sayac =1;
        if (temp2->next ==ilk)
        {
            printf("Eleman sayisi = %d\n",sayac);
            return ilk;
        }
         while (temp2->next != ilk)
        {
            temp2 = temp2->next;
             sayac++;
        }
        printf("Eleman sayisi = %d\n",sayac);
        return ilk;
    }
}
struct liste *arayaEkle(struct liste *temp,int x)
{
    struct liste *temp2,*temp3,*son;

    if (temp == NULL)
    {
        temp = (struct liste*)malloc(sizeof(struct liste));
        temp->sayi =x;
        temp->next=temp;
        ilk=temp;
        return ilk;
    }
    else
    {
        temp2=ilk;
        temp3 = (struct liste*)malloc(sizeof(struct liste));
        temp3->sayi = x;
        if (temp2->next == ilk)
        {
            if (temp2->sayi < x)
            {
                temp2->next = temp3;
                temp3->next = temp2;
                return ilk;
            }
            else
            {
                temp3->next=temp2;
                temp2->next=temp3;
                ilk=temp3;
                return ilk;
            }
        }
        else
        {
            while (temp2->next != ilk) // birden fazla düğümlerde
            {
                if (temp2->sayi > x) //ilk düğüm ise
                {
                    son=ilk;
                    while (son->next != ilk)
                    {
                        son = son->next;
                    }
                    temp3->next=temp2;
                    son->next=temp3;
                    ilk=temp3;
                    return ilk;
                }
                else if (temp2->sayi < x && temp2->next->sayi > x) //arada ise
                {
                    temp3->next = temp2->next;
                    temp2->next = temp3;
                    return ilk;
                }
                else
                {
                    temp2 = temp2->next;
                }
            }
            if (temp2->sayi < x)
            {
                temp2->next =temp3;
                temp3->next=ilk;
                return ilk;
            }
        }
    }
}

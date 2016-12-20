#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * ilk=NULL;

struct node *basaEkle(struct node *head,int sayi);
struct node *sonaEkle(struct node *head,int sayi);
struct node *silme(struct node *head,int sayi);
void yazdir(struct node *head);
int elemanSay(struct node *head);
int aramaYap(struct node *head,int sayi);

int main()
{
    struct node *head=NULL;
    int secim,deger,x;

    while(1==1)
    {
        printf("[1]Başına eleman ekle\n[2]Sona eleman ekle\n[3]Bilgi yazdır\n[4]Eleman sayma\n[5]Arama\n[6]Silme\n[]Cıkıs\nSeciminiz : ");
        scanf("%d",&secim);

        switch(secim)
        {
            case 1:
                printf("Bir sayi giriniz : ");
                scanf("%d",&deger);
                head=basaEkle(head,deger);
                break;
            case 2:
               printf("Bir sayi giriniz : ");
               scanf("%d",&deger);
               head=sonaEkle(head,deger);
               break;
            case 3:
                yazdir(head);
                break;
            case 4:
                x=elemanSay(head);
                printf("%d tane elaman var\n",x);
                break;
            case 5:
                printf("Aramak istediğiniz degeri giriniz : ");
                scanf("%d",&deger);
                if (aramaYap(head,deger)%2==0)
                    printf("Aradığınız değer bulunnamadı !\n");
                else
                   printf("Aradığınız değer bulundu \n");
                break;
            case 6:
                printf("Silmek istediğiniz degeri giriniz : ");
                scanf("%d",&deger);
                head=silme(head,deger);
                break;
            case 7:
                exit(0);
                default:
                    printf("Yanlış seçim !");
        }
    }


    return 0;
}
struct node *basaEkle(struct node *head,int sayi)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));// önce gecici olarak temp değişkeni oluşturup yer ayırdık

    temp->data=sayi; //bu değişkene kullanıcının girdiği degeri atadık
    temp->next=head; // tempin bir sonraki adresinide heade işaret ettik
    head=temp; //eğer headde hiç bir şey yoksa zaten ilk eleman eklemedir
    ilk=temp;

    return head;
}
struct node *sonaEkle(struct node *head,int sayi)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node)); //once gecici bir degisken için yer ayırıyoruz

    temp->data=sayi; //kullanıcının girdiği degeri atiyoruz
    temp->next=NULL;
    head->next=temp; // bize gönderilen listenin bir sonraki adresine bu gecici yeri ekliyoruz

    return head->next; //listenin bir sonraki elemanını adres olarak geri gönderiyoruz
}
void yazdir(struct node *head)
{
    struct node *temp = ilk;

    while(temp != NULL)
    {
        printf("Deger = %d\n",temp->data);
        temp = temp->next;
    }

}
int elemanSay(struct node *head)
{
    struct node *temp=ilk;
    int i=0;

    while(temp !=NULL)
    {
        i++;
        temp = temp->next;
    }
    return i;

}
int aramaYap(struct node *head,int sayi)
{
    struct node *temp=ilk;

    while(temp !=NULL)
    {
        if (temp->data==sayi)
        {
            return 1;
        }
        else
        {
            temp = temp->next;
        }
    }
    return 0;
}
struct node *silme(struct node *head,int sayi)
{
    struct node *temp;
    if (head==NULL)//hiçbir eleman yok ise 1)Önce liste dolu mu boş mu diye baktık
    {
        printf("Liste BOŞ.\n");
        return ;
    }
        temp=head;
        if (head->data==sayi)//ilk düğümdeki ilk deger mi?2)Dolu olduğunu anladık bu sefer ilk düğümdeki ilk eleman mı
        {                    //diye baktık
            head=head->next; //eğer tek düğüm iste head->next=NULL dur
            free(temp);

        }
        else if (head->next==NULL) //tek düğüm mü 3)İlk düğümde degerin olmadığını ama tek düğüm olup olmadığına baktık
        {
            printf("İlk düğümde silinecek eleman yok\n");
            return head;
        }
        else //tek düğüm ve fazlası için
        {
            while(temp->next->data != sayi)//4)ilk düğümün dolu boş ve değer olup olmamasını kontrol ettik bir sonraki
            {                              //eleman için kontrollerimize başladık
                if (temp->next->next==NULL) //Döngüde baktık ilk başta temp->next->data != sayi mi ? DEĞİL.
                {                           //o zaman buraya kadar geldiğimiz listede silinecek deger yoktur
                    printf("Listede silinecek eleman bulunamamıştır.\n");
                    return head;
                }
                temp = temp->next;//eğer temp->next->next !=NULL ise listenin bir sonraki elemanını kontrol ederiz.
            }
            struct node *temp2 = temp->next;//silinecek adresi gecici adrese atadık
            temp->next=temp->next->next;
            free(temp2);
        }
return head;


}

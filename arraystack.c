#include <stdio.h>
#include <stdlib.h>

#define BOYUT 50

void push(int x);
int pop(void);
void listele();

int *enAlt,*enUst;
int yigin[BOYUT];

int main()
{
    enAlt=yigin;//yiginin adresini atadık
    enUst=yigin;
    int deger,secim;

    while(1)
    {
        printf("[1]Ekle\n[2]Silme\n[3]Listeleme\n[4]Cıkış\nSecim : ");
        scanf("%d",&secim);

        switch(secim)
        {
            case 1:
                printf("Bir sayi giriniz : ");
                scanf("%d",&deger);
                push(deger); //yigina eklenicek veriyi gonderdik
                break;
            case 2:
                printf("Silinen deger = %d\n",pop());
                break;
            case 3:
                listele();
                break;
                default:
                printf("Geçersiz işlem");
        }
    }
}
void push(int x)
{
    if (enUst+1 == (enAlt+BOYUT)) //enUste bir tane daha deger eklemek istedigimizde taban yani 0x0+0x50 olursa stack dolu
    {
        printf("Yigin dolu.");
        exit(EXIT_FAILURE);
    }
    else
    {
        *enUst=x; //enust yiginin adresini tutuyor ve enuste eklenecek sayiyi atiyoruz
        enUst++; //dizi indexini arttırdık
    }
}
int pop(void)
{
    if (enAlt == enUst)
    {
        printf("Yigin bos.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        enUst--;//eksiltmemizin sebebi push fonksiyonundan cıkmadan once bir arttırıyoruz.
        int deger=*enUst;
        return deger;
    }
}
void listele()
{
    printf("\n[EnAlt]\n");
    int *temp=yigin;
    while (temp<enUst)
    {
        printf("%d\n",*temp);
        temp++;
    }
    printf("\n[EnUst]\n");
}

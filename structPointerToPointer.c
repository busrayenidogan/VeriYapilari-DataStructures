#include <stdio.h>
#include <stdlib.h>

struct deneme
{
    char **p;
};
void aa(struct deneme *temp);
char a[4][10]={"askdjk","sdşksm","sdmk","sdö"};
int main()
{
    struct deneme *root;
    root = (struct deneme*)malloc(sizeof(struct deneme));

    aa(root);
    printf("%s",root->p[0]);

    return 0x0;
}
void aa(struct deneme *temp)
{
    int i;
    temp->p = (char*)malloc(sizeof(char)*4);

    for (i=0; i<4; i++) //4 satır için
    {
        *(temp->p+i)= malloc(30);
        sprintf(*(temp->p+i),"%s",a[i]);
    }
    for (i=0; i<4; i++)
    {
        printf("%d : %s\n",i,temp->p[i]);
    }
}

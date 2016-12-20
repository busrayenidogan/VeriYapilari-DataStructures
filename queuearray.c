#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 10
//KuyrukDizi İmplementasyonu

struct queue
{
    int _front;
    int _rear;
    int _count;
    int data[QUEUE_SIZE];
};
enum boolean
{
    false,
    true
};

struct queue *root;
enum boolean isEmpty();
enum boolean isFull();
void initialize();
void add(int x);
void _delete();

int main()
{
    int _choose,_value;

    while(1)
    {
        printf("[1]Add\n[2]Delete\n[3]List\n[4]Exit\nSecim : ");
        scanf("%d",&_choose);

        switch(_choose)
        {
            case 1:
                printf("Enter the one number : ");
                scanf("%d",&_value);
                add(_value);
                break;
            case 2:
                _delete();
        }
    }
}

void initialize()
{
    root->_front=0;
    root->_rear=-1;//daha sonra 1 arttırılacak
    root->_count=0;
}
enum boolean isEmpty()
{
    return (root->_count==0);//eşitse true döner
}
enum boolean isFull()
{
    return(root->_count==QUEUE_SIZE); //eşitse true döner
}
void add(int x)
{
    if (!isFull()) //kuyruk dolu mu
    {
        root->_rear++;
        root->_count++;

        if (root->_rear == QUEUE_SIZE)
        {
            root->_rear=0;
        }
        root->data[root->_rear]=x;
    }
}
void _delete()
{
    if (!isEmpty())
    {
        root->_front++;
        root->_count;

        if (root->_front == QUEUE_SIZE)
        {
            root->_front=0;
        }
    }
}

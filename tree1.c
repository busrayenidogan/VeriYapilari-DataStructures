#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int _data;
    struct tree *_left;
    struct tree *_right;
};
struct tree *_first=NULL;
struct tree *_createNode(int _y);
struct tree *_insert(struct tree *_temp,int _x);
struct tree *_delete(struct tree *_temp,int x);
struct tree *_search(struct tree *_temp,int x);
void _preOrder(struct tree *_temp);
void _inOrder(struct tree *_temp);
void _postOrder(struct tree *_temp);
void _mirror(struct tree *_temp);
int _nodeCounter(struct tree *_temp);
int _heightTree(struct tree *_temp);
int _minValue(struct tree *_temp);
int _maxValue(struct tree *_temp);
int _total(struct tree *_temp);

int main()
{
    struct tree *_root=NULL;
    int _choose,_value;

    while(1)
    {
        printf("[1]Add\n[2]Delete\n[3]List\n[4]Mirror\n[5]Number of node of tree \n[6]High of tree\n[7]Search\n[8]Min Value\n[9]Max Value\n[10]Total\n[11]Exit\nChoose : ");
        scanf("%d",&_choose);

        switch(_choose)
        {
            case 1:
                printf("Enter the number : ");
                scanf("%d",&_value);
                _root=_insert(_root,_value);
                break;
            case 2:
                printf("Enter the number : ");
                scanf("%d",&_value);
                _root=_delete(_root,_value);
                break;
            case 3:
                printf("-- Preorder --\n");
                _preOrder(_root);
                printf("\n-- Inorder -- \n");
                _inOrder(_root);
                printf("\n-- Postorder --\n");
                _postOrder(_root);
                printf("\n");
                break;
            case 4:
                _mirror(_root);
                break;
            case 5:
                printf("Number of node of tree  : %d\n",_nodeCounter(_root));
                break;
            case 6:
                printf("High of tree : %d\n",_heightTree(_root));
                break;
            case 7:
                printf("Enter the number : ");
                scanf("%d",&_value);
                _root=_search(_root,_value);
                break;
            case 8:
                printf("Min Value = %d\n",_minValue(_root));
                break;
            case 9:
                printf("Max Value = %d\n",_minValue(_root));
                break;
            case 10:
                printf("Toplam : %d\n",_total(_root));
                break;
            case 11:
                exit(0);
        }
    }
}
struct tree *_insert(struct tree *_temp,int _x)
{
    if (_temp != NULL) //kök yada node yoksa
    {
        if (_x < _temp->_data)
        {
            _temp->_left = _insert(_temp->_left,_x);
        }
        else
        {
            _temp->_right = _insert(_temp->_right,_x);
        }
    }
    else
    {
        _temp=_createNode(_x);
    }
    return _temp;
}
struct tree *_createNode(int _y)
{
    struct tree* _temp = (struct tree*)malloc(sizeof(struct tree));
    _temp->_data=_y;
    _temp->_left=NULL;
    _temp->_right=NULL;
    //_first=_temp;
    return _temp;
}
void _preOrder(struct tree *_temp)
{
    if (_temp != NULL)
    {
        printf("%3d ",_temp->_data);
        _preOrder(_temp->_left);
        _preOrder(_temp->_right);
    }
}
void _inOrder(struct tree *_temp)
{
    if (_temp != NULL)
    {
        _inOrder(_temp->_left);
        printf("%3d ",_temp->_data);
        _inOrder(_temp->_right);
    }
}
void _postOrder(struct tree *_temp)
{
    if (_temp != NULL)
    {
        _postOrder(_temp->_left);
        _postOrder(_temp->_right);
        printf("%3d ",_temp->_data);
    }
}
void _mirror(struct tree *_temp)
{
    if (_temp == NULL)
    {
        return;
    }
    else
    {
        struct tree *_temp2;
        _mirror(_temp->_left);
        _mirror(_temp->_right);
        _temp2 = _temp->_left;
        _temp->_left = _temp->_right;
        _temp->_right = _temp2;
    }
}
int _nodeCounter(struct tree *_temp)
{
    if (_temp == NULL)
    {
        return 0;
    }
    else
    {
        return _nodeCounter(_temp->_left) + 1 + _nodeCounter(_temp->_right);
    }
}
int _heightTree(struct tree *_temp)
{
    if (_temp == NULL)
    {
        return -1;
    }
    else
    {
        int _left_height,_right_height;

        _left_height = _heightTree(_temp->_left);
        _right_height = _heightTree(_temp->_right);

        if (_left_height > _right_height)
        {
            return _left_height + 1;
        }
        else
        {
            return _right_height + 1;
        }
    }
}
struct tree *_delete(struct tree *_temp,int x)
{
    struct tree *_temp2,*_temp3;
    if (_temp == NULL)
    {
        return NULL;
    }
    if (_temp->_data == x)
    {
        if (_temp->_left == _temp->_right) //aranan düğümün yani x in çocukları yoksa yani ikiside null ise
            {
                free(_temp);
                return NULL;
            }
            else
            {
                if ( _temp->_left == NULL)//aranan düğümün sol çocugu yok fakat sag cocugu var
                {
                    _temp2 = _temp->_right;//aranan değerin sağ çocugu NULL
                    free(_temp);
                    return _temp2;
                }
                else if (_temp->_right == NULL) //diyelim ki rootu silicem ama sol cocukgu var o zaman
                {
                    _temp2=_temp->_left;// sol cocugun adresini degiskene atarız
                    free(_temp);//rootu sileriz
                    return _temp2;//sol cocugun adresinide donus degeri olarak dondururuz
                }
                else //burda iki durum söz konusu sol cocugun en buyugu basa gelebilir yada sag cocugun en kucugu
                {
                    _temp2=_temp3=_temp->_right;// sol ve sağ çocugun adresini ata

                    while (_temp->_right != NULL) //sag cocugun en kucugunu bulana kadar ilerliyoruz
                    {
                        _temp2 = _temp2->_left;
                    }
                    _temp2->_left = _temp->_left;//sag cocugun en kucugune elimizdeki sol degerini atıyoruz
                    free(_temp);//ve silmek istedigimiz kök degerini siliyoruz
                    return _temp3;
                }
            }
    }
    else if (_temp->_data < x)
    {
        _temp->_right = _delete(_temp->_right,x);
    }
    else
    {
        _temp->_left = _delete(_temp->_left,x);
    }
        return _temp;
}
struct tree *_search(struct tree *_temp,int x)
{
    if (_temp != NULL)
    {
        if (_temp->_data == x)
        {
            printf("Wanted = %d !\n",_temp->_data);
            return _temp;
        }
        else if (_temp->_data < x)
        {
             _search(_temp->_right,x);
        }
        else
        {
             _search(_temp->_left,x);
        }
    }
    return NULL;
}
int _minValue(struct tree *_temp)
{
    if (_temp != NULL)
    {
        while (_temp->_left != NULL)
        {
            _temp = _temp->_left;
        }
        return _temp->_data;
    }
    else
    {
        return 0;
    }
}
int _maxValue(struct tree *_temp)
{
    if (_temp != NULL)
    {
        while (_temp->_right != NULL)
        {
            _temp = _temp->_right;
        }
        return _temp->_data;
    }
    else
    {
        return 0;
    }
}
int _total(struct tree *_temp)
{
   
    if (_temp != NULL)
    {
        return _temp->_data+_total(_temp->_left)+_total(_temp->_right);
    }
    else
    {
        return 0;
    }
}

#include <stdio.h>
#include <stdlib.h>
// head ka case temp->next if NULL and NULL se acessing something head and rear ek ho tab ka case
typedef struct node
{
    int data;
    struct node *next;
} nd;
nd *head = NULL;
nd *rear = NULL;
nd *create_new_node()
{
    nd *new_node = (nd *)malloc(sizeof(nd));
    printf("Enter node data\n");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    return new_node;
}
void insert_end()
{
    nd *new_node = create_new_node();
    if (head == NULL)
    {
        head = new_node;
        rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = rear->next;
    }
}
void insert_front()
{
    nd *new_node = create_new_node();
    if (head == NULL)
    {
        head = new_node;
        rear = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}
void insert_position()
{
    nd *new_node = create_new_node();
    int pos;
    printf("Enter the position (not index) at which to insert\n");
    scanf("%d", &pos);
    if (pos == 1)
    {
        if (head == NULL)
        {
            head = new_node;
            rear = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
    }
    else
    {
        int cnt = 1;
        nd *temp = head;
        nd *prev;
        while (cnt != pos && temp != NULL) // here the below said error(900) does not occur bcz yaha NULL ka data access hi nahi kiya ja raha
        {
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        if (cnt == pos)
        {
            new_node->next = prev->next;
            prev->next = new_node;
        }
        else if (temp == NULL)
        {
            printf("Position invali\n");
        }
    }
}
void insert_before()
{
    nd *new_node = create_new_node();
    int ele;
    printf("Enter the element before which to insert\n");
    scanf("%d", &ele);
    nd *temp = head;
    nd *prev = NULL;
    if (head == NULL)
    {
        printf("No element\n"); // yeh condition jab empty sll mei insertion ho tab kaam ayega
        return;
    }
    while (temp->data != ele && temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp->data == ele)
    {
        if (temp == head) // agar temp head hai tho prev NULL hai na to prev->next = new_node; yeh error denga
        {
            new_node->next = head;
            head = new_node;
            return;
        }
        new_node->next = prev->next;
        prev->next = new_node;
    }
    else if (temp->next == NULL)
    {
        printf("No such element\n");
    }
}
void insert_after()
{
    nd *new_node = create_new_node();
    int ele;
    printf("Enter the element after which to insert\n");
    scanf("%d", &ele);
    nd *temp = head;
    nd *prev = NULL;
    if (head == NULL)
    {
        printf("No element\n"); // yeh condition jab empty sll mei insertion ho tab kaam ayega
        return;
    }
    while (temp->data != ele && temp->next != NULL) // (900)here temp is update to temp next which if it is NULL and next time checking happens for NULL ka data which is wrong
    {
        temp = temp->next;
    }
    if (temp->data == ele)
    {
        new_node->next = temp->next;
        temp->next = new_node;
    }
    else if (temp->next == NULL)
    {
        printf("no such element\n");
    }
}
void delete_front()
{
    if (head == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        nd *d = head;
        if (head == rear)
        {
            rear = NULL;
        }
        head = head->next;
        printf("Deleting %d\n", d->data);
        free(d);
    }
}
void delete_end()//dlete karne keliye previous chahiye
{
    if (head == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        nd *d = rear;
        if (head == rear)
        {
            head = NULL;
            rear = NULL;
        }
        else
        {
            nd* temp=head;
            while(temp->next!=rear)
            {
                temp=temp->next;
            }
            temp->next=NULL;
            rear=temp;
        }
        printf("Deleting %d\n", d->data);
        free(d);
    }
}
void delete_before()//head delete ho rahi ho tho
{
    int ele;
    printf("Enter the element before which to deleted\n");
    scanf("%d", &ele);
    nd *temp = head;
    nd *prev = NULL;
    if(head==NULL)//koi element na ho tho
    {
        printf("Empty\n");
        return;
    }
    if(head->data==ele)
    {
        printf("No elements before\n");
        return;
    }
    while (temp->data != ele && temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp->data == ele)
    {
        nd *d = temp;
        printf("Deleting %d\n", d->data);
        prev->next = temp->next;
        free(d);
    }
    else if (temp->next == NULL)
    {
        printf("Invalid\n");
    }
}
void delete_after()//rear ke badh kuch nahi hai na
{
    int ele;
    printf("Enter the element after which to deleted\n");
    scanf("%d", &ele);
    nd *temp = head;
    if(head==NULL)//koi element na ho tho
    {
        printf("Empty\n");
        return;
    }
    while (temp->data != ele && temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->data == ele && temp->next != NULL)
    {
        nd *d = temp->next;
        temp->next = temp->next->next;
    }
    else if(temp==rear)
    {
        printf("No element after\n");
        return;
    }
    else if (temp->next == NULL)
    {
        printf("Invalid\n");
    }
}
void delete_position()
{
    int pos;
    printf("Enter position at which to delete\n");
    scanf("%d", &pos);
    nd *temp = head;
    nd *prev;
    int cnt = 1;
    if(head==NULL)//koi element na ho tho
    {
        printf("Empty\n");
        return;
    }
    if (pos == 1)
    {
        delete_front();
    }
    else
    {
        while (cnt != pos && temp != NULL)
        {
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        if (cnt == pos)
        {
            prev->next = temp->next;
        }
        else if (temp == NULL)
        {
            printf("Invalid\n");
        }
    }
}
void display()
{
    nd *temp = head;
    if (head == NULL)
    {
        printf("No elements in sll\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void main()
{
    printf("Enter\n1 to insert elements at end\n2 to insert elements at front\n3 to insert elements at a position\n4 to insert elements before a given node\n5 to insert elements after a given node\n6 to delete elements from front\n7 to delete elements from end\n8 to delete elements before given element\n9 delete elements after given element\n10 to delete elements at given position\n11 to display sll\n");
    int op;
    char ch = 'y';
    while (ch == 'y')
    {
        printf("Enter options from 1 to 11\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            insert_end();
            break;
        case 2:
            insert_front();
            break;
        case 3:
            insert_position();
            break;
        case 4:
            insert_before();
            break;
        case 5:
            insert_after();
            break;
        case 6:
            delete_front();
            break;
        case 7:
            delete_end();
            break;
        case 8:
            delete_before();
            break;
        case 9:
            delete_after();
            break;
        case 10:
            delete_position();
            break;
        case 11:
            display();
            break;
        default:
            printf("Invalid choice\n");
        }
        printf("Continue\n");
        scanf(" %c", &ch);
    }
}
#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *root = NULL;

struct queue
{
    struct tree *address;
    struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;

struct stack
{
    struct tree *loc;
    struct stack *next;
};

struct stack *top1 = NULL;
struct stack *top2 = NULL;

struct tree *create_node(struct tree *root, int x);
struct tree *create_tree(struct tree *root, int n, int i, int a[n]);
void level_order(struct tree *temp);

void zigzag_order(struct tree *temp);
void enqueue(struct tree *ptr);
struct tree *dequeue();
int QueueIsEmpty();

struct stack *push(struct tree *temp, struct stack *head);
struct tree *pop();

void inorder(struct tree *root);

int main()
{

    int n;
    printf("Enter the number of integers \n");
    scanf("%d", &n);

    int a[n], i;
    printf("Enter %d integers \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    root = create_tree(root, n, 0, a);
    struct tree *ptr = root;
    // inorder(ptr);
    printf(" LEVEL ORDER IS : ");
    level_order(ptr);
    printf("\n");

    printf(" ZIGZAG ORDER IS : ");
    zigzag_order(ptr);
    printf("\n");

    return (0);
}

struct tree *create_node(struct tree *root, int x)
{
    struct tree *temp = (struct tree *)malloc(sizeof(struct tree));

    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    return (temp);
}

struct tree *create_tree(struct tree *root, int n, int i, int a[n])
{
    struct tree *temp1 = NULL;

    if (i < n)
    {
        temp1 = create_node(root, a[i]);
        temp1->left = create_tree(root, n, 2 * i + 1, a);
        temp1->right = create_tree(root, n, 2 * i + 2, a);
    }
    return (temp1);
}

void level_order(struct tree *temp)
{
    temp = root;

    enqueue(temp);

    while (front != NULL && rear != NULL)
    {
        temp = dequeue();

        printf(" %d ", temp->data);

        if (temp->left != NULL)
        {
            enqueue(temp->left);
        }

        if (temp->right != NULL)
        {
            enqueue(temp->right);
        }
    }
}

void zigzag_order(struct tree *temp)
{
    int flag = 0;

    temp = root;
    struct tree *ptr = NULL;

    top1 = push(temp, top1);

    while (top1 != NULL)
    {
        ptr = pop();

        printf(" %d ", ptr->data);

        if (flag == 0)
        {
            if (ptr->left != NULL)
            {
                top2 = push(ptr->left, top2);
            }

            if (ptr->right != NULL)
            {
                top2 = push(ptr->right, top2);
            }
        }

        else
        {
            if (ptr->right != NULL)
            {
                top2 = push(ptr->right, top2);
            }

            if (ptr->left != NULL)
            {
                top2 = push(ptr->left, top2);
            }
        }

        if (top1 == NULL)
        {
            if (flag == 1)
            {
                flag = 0;
            }

            else if (flag != 1)
            {
                flag = 1;
            }

            struct stack *temp11 = NULL;
            temp11 = top1;
            top1 = top2;
            top2 = temp11;
        }
    }
}

void enqueue(struct tree *ptr)
{
    struct queue *temp1 = (struct queue *)malloc(sizeof(struct queue));

    if (front == NULL && rear == NULL)
    {
        temp1->address = ptr;
        temp1->next = NULL;
        front = temp1;
        rear = front;
    }

    else
    {
        temp1->address = ptr;
        temp1->next = NULL;
        rear->next = temp1;
        rear = temp1;
    }
}

struct tree *dequeue()
{
    struct tree *temp1 = (struct tree *)malloc(sizeof(struct tree));
    struct queue *temp = front;

    if (front == rear)
    {
        rear = NULL;
    }

    temp1 = temp->address;
    front = front->next;
    free(temp);

    return (temp1);
}

int QueueIsEmpty()
{
    if (front == NULL && rear == NULL)
        return (0);
}

struct stack *push(struct tree *temp, struct stack *head)
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));

    if (head == NULL)
    {
        ptr->loc = temp;
        ptr->next = NULL;

        head = ptr;
    }

    else
    {
        ptr->loc = temp;
        ptr->next = head;
        head = ptr;
    }

    return (head);
}

struct tree *pop()
{
    struct tree *z = NULL;
    struct stack *y = top1;

    z = y->loc;

    top1 = top1->next;
    free(y);

    return (z);
}

void inorder(struct tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
}
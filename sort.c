/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* start = NULL;

//I dont want to traverse for add an item last position, i will use last->next
struct node* last = NULL;
struct node* temp;

struct node* createNode(int x)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void addLast(int y)
{
    struct node* hodor = createNode(y);
    if(start == NULL)
    {
        start = hodor;
        last = hodor;
    }
    else
    {
        last->next = hodor;
        last = hodor;
    }
}

void printLinked()
{
    temp = start;
    while(temp->next != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

void swapNode(struct node *x, struct node *y)
{
    int temp = x->data;
    x->data = y->data;
    y->data = temp;
}

void selectionLinked()
{
    struct node* curr_node;
    struct node* next_node;
    //
    struct node* temp_node;
    curr_node = start;

    while(curr_node != NULL)
    {
        next_node = curr_node->next;
        //
        temp_node = curr_node;
        while(next_node != NULL)
        {
            if(temp_node->data > next_node->data)
            {
                //
                temp_node = next_node;
                //swapNode(curr_node, next_node);
            }
            next_node = next_node->next;
        }
        swapNode(curr_node, temp_node);
        curr_node = curr_node->next;
    }
}



int main()
{
    int choise;
    // printf("\n How many numbers do you want to create ... ");
    // scanf("%d", &choise);
    addLast(5);
    addLast(4);
    addLast(3);
    addLast(2);
    addLast(1);
    selectionLinked();
    printLinked();

}

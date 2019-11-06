#include<stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head;
void Finsert(int x)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data= x;
    //temp->next = NULL;
   // if(head!=NULL)
        temp->next=head;
    head=temp;
}
void Rinsert(int x)
{
    struct node* temp ;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    struct node* itr = head;
    while(itr!=NULL)
    {
        itr=itr->next;
    }
    itr->next=temp;
}
void Minsert(int x)
{

}
void Display()
{
    struct node* temp = head;
    printf("List is : ");
    while(temp!=NULL)
    {
        printf(" %d" , temp->data);
        temp= temp->next;
    }
    printf("\n");
}
int main()
{
    int n,i,x, choice;
    head=NULL;// list is empty
    printf("How many number you want to insert? \n");
    scanf("%d" , &n);
    for (int i = 0; i <n ; ++i) {
        printf("Enter number : \n");
        scanf("%d", &x);
        choices:
        printf("Where you want to insert\n1. In Front  2. In Middle  3. In Rear\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                Finsert(x);
                Display();
                break;
            }
            case 2:
            {
                Minsert(x);
                Display();
                break;
            }
            case 3:
            {
                Rinsert(x);
                Display();
                break;
            }
            default: printf("***Choose correct option***\n");
            goto choices;

        }

    }
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int roll_no;
    float cgpa;
    char name[50];
    struct node* next;
};

struct node *last=NULL;

struct node input()
{
    struct node temp;
    printf("\n\n>>>***ENTER FOLLOWING DETAILS***<<<\n");
    printf("---------------------------------------\n\n");
    getchar();
    printf("Enter your Roll number : \n");
    scanf("%d", &temp.roll_no);
    getchar();
    printf("Enter your name : \n");
    gets(temp.name);
    printf("Enter your CGPA : \n");
    scanf("%f" , &temp.cgpa);
    return temp;
}
void front_insert(struct node temp )
{
    int i;
    struct node* temp1 =(struct node* ) malloc(sizeof(struct node));
    temp1->name[0] = '\0';
    for(i=0 ; i<strlen(temp.name) ; i++)
    {
        temp1->name[i] = temp.name[i];
    }
    //because i'm getting some extra part in string at the end
    temp1->name[i]='\0';
    temp1->cgpa = temp.cgpa;
    temp1->roll_no = temp.roll_no;

    if(last==NULL)
    {
        last = temp1;
        last->next = last;
        return;
    }
    temp1->next = last->next;
    last->next = temp1;

}
void middle_insert(struct node temp , int pos)
{
    int i;
    struct node* temp1 = (struct node* )malloc(sizeof(struct node));
    temp1->name[0] = '\0';
    for(i=0 ; i<strlen(temp.name) ; i++)
        temp1->name[i] = temp.name[i];

    //because i'm getting some extra part in string at the end
    temp1->name[i]='\0';

    temp1->cgpa = temp.cgpa;
    temp1->roll_no = temp.roll_no;
    temp1->next = NULL;
    struct node* itr = last->next;
    if(pos==1)
    {
        temp1->next = last->next;
        last->next = temp1;
        return;
    }
    for(int i=1 ; i<= pos - 2; i++)
    {
        itr = itr->next;
    }
    if(itr==last)
    {
        temp1->next = last->next;
        itr->next = temp1;
        last = temp1;
        return;
    }
    temp1->next = itr->next;
    itr->next = temp1;

}
void rear_insert(struct node temp)
{
    int i;
    struct node* temp1 = (struct node* )malloc(sizeof(struct node));
    temp1->name[0] = '\0';
    for(i=0 ; i<strlen(temp.name) ; i++)
        temp1->name[i] = temp.name[i];

    temp1->name[i] = '\0';
    temp1->cgpa = temp.cgpa;
    temp1->roll_no = temp.roll_no;
    temp1->next=NULL;

    struct node* itr = last;

    if(last==NULL)
    {
        last=temp1;
        last = last->next;
        return;
    }
    while(itr->next!=NULL)
    {
        itr = itr->next;
    }
    itr->next = temp1;
    last = temp1;
}




void display()
{

    if(last==NULL)
    {
        printf("\nLIST IS EMPTY\n");
        return;
    }
    struct node *temp = last->next;
    do
    {
        printf("----------------------------------\n");
        printf("\nROLL NO. : %d\n" , temp->roll_no);
        printf("\nNAME     : %s\n", temp->name);
        printf("\nCGPA     : %.2f\n" , temp->cgpa);
        printf("\n----------------------------------\n");
        temp = temp->next;
    }while(temp!=last->next);
}

void front_deletion()
{
    struct node* temp = last->next;
    temp = temp->next;
    last = temp;

}

void middle_deletion(int pos)
{
    if(pos==1)
    {
        if(last->next==last)
        {
//            printf("last == last->next\n");
            last= NULL;
            return;
        }
//        printf("in last\n");
        last->next=last->next->next;
        return;
    }
    struct node* itr = last->next;
    for(int i=1 ; i<= pos - 2 ; i++)
    {
        itr = itr->next;
    }
    if(itr->next==last)
    {
        itr->next = last->next;
        last = itr;
        return;
    }

    itr->next = itr->next->next;

}

void rear_deletion()
{
    struct node* itr = last->next;
    //again it is not working
    if(last->next==last)
    {
//        printf("%d %d\n" , last , last->next);
        last = NULL;
        return;
    }
    while (itr->next->next!=last->next)
    {
        itr= itr->next;
    }

    itr->next= last->next;
    last = itr;
}


void search_byRoll(int roll)
{
    struct node* temp = last->next;
    printf("\n");
    do
    {
        if(temp->roll_no==roll)
        {
            printf("ROLL NO. \"%d\" found with NAME : \"%s\" and CGPA : \"%.2f\"\n" , temp->roll_no ,  temp->name , temp->cgpa);
            return;
        }
        temp = temp->next;
    }while(temp!=last->next);
    printf("Roll NO. : \"%d\" Not found\n" , roll);
}

void search_byCGPA(float cg)
{
    struct node* temp = last->next;
    int flag = 1;
    printf("\n");
    do
    {
        if(temp->cgpa==cg)
        {
            printf("CGPA : \"%.2f\" found with NAME : \"%s\" and ROLL NO. :\"%d\"\n" , cg  , temp->name , temp->roll_no );
            flag = 0;
        }
        temp = temp->next;
    }while(temp!=last->next);
    if(flag)
    {
        printf("No student Found with \"CGPA\" %.2f\n" , cg);
    }

}

void search_byName(char s[] )
{
    struct node* temp = last->next;
    int flag = 1;
    printf("\n");
    do
    {
        if(strcmp(temp->name , s)==0)
        {
            printf("NAME : \"%s\" found with ROLL NO. : \"%d\" and CGPA : \"%.2f\"\n"  , s , temp->roll_no, temp->cgpa );
            flag = 0;
        }

        temp = temp->next;
    }while(temp!=last->next);
    if(flag)
    {
        printf("No student Found with NAME : \"%s\"\n" , s);
    }

}



//driven program
int main()
{
    struct node temp;
    while(1)
    {

        printf("\nEnter your choice \n");
        printf("1.Insertion  2.Deletion  3.Display  4.Searching   5.Exit\n");
        int choice ;
        scanf("%d" , &choice);
        switch(choice)
        {
            case 1:
            {
                again:
                printf("1.Front Insertion  2.Middle Insertion  3.Rear Insertion\n");
                int another_choice;
                scanf("%d", &another_choice);
                switch(another_choice)
                {
                    case 1:
                    {
                        temp = input();
                        front_insert(temp);
                        break;
                    }
                    case 2:
                    {
                        temp =input();
                        printf("Enter position where you want to insert\n");
                        int pos;
                        scanf("%d" , &pos);
                        middle_insert(temp , pos);
                        break;
                    }
                    case 3:
                    {
                        temp =input();
                        rear_insert(temp);
                        break;
                    }
                    default:
                    {
                        printf("Please...choose correct choice for insertion \n");
                        goto again;
                    }
                }
                break;
            }
            case 2:
            {
                back:
                printf("1.Front Deletion  2.Middle Deletion  3.Rear Deletion \n");
                int another_choice;
                scanf("%d" ,&another_choice);
                if(another_choice==1)
                {
                    front_deletion();
                }
                else if(another_choice==2)
                {
                    printf("Enter position from where you want to delete\n");
                    int pos;
                    scanf("%d" , &pos);
                    middle_deletion(pos);
                }
                else if(another_choice==3)
                {
                    rear_deletion();
                }
                else{
                    printf("Please... choose correct choice for Deletion \n");
                    goto back;
                }
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                fback:
                printf("1.By Roll number   2.By name   3.By CGPC \n");
                int another_choice;
                scanf("%d" ,&another_choice);
                if(another_choice==1)
                {
                    printf("Which \"ROLL NO\" you want to find out\n");
                    int roll;
                    scanf("%d" , &roll);
                    search_byRoll(roll);
                }
                else if(another_choice==2)
                {
                    printf("Which \"NAME\" of students you want to find out\n");
                    getchar();
                    char s[50];
                    gets(s);
                    search_byName(s);
                }
                else if(another_choice==3)
                {
                    printf("which \"CGPA\" of students you want to find out\n");
                    float cg;
                    scanf("%f" , &cg);
                    search_byCGPA(cg);
                }
                else{
                    printf("Please...choose correct choice for Searching\n");
                    goto fback;
                }
                break;
            }
            case 5:
            {
                exit(0);
            }
            default:
            {
                printf("Please...Enter correct choice\n");
                break;
            }
        }
    }
}

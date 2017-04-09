#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

typedef struct node
{
    int info;
    int pty;
    struct node *next;
}n1;


void *enqueue(n1 **rear,n1 **front)
{
    n1 *ptr ,*temp,*a;
    ptr=(n1*)malloc(sizeof(n1));
    temp=(n1*)malloc(sizeof(n1));
    printf("enter values ");
    scanf("%d",&ptr->info);
    printf("Enter priority of queue \n");
    scanf("%d",&ptr->pty);
    ptr->next=NULL;
    if(*rear==NULL)
        *front=*rear=ptr;
    else
    {temp=*front;
        while(temp!=NULL)
        {
            if(temp->pty<ptr->pty)
            {a=temp;
            temp=temp->next;}
             else break;
        }
        if(temp==NULL)
            a->next=ptr;
        else
        {a->next=ptr;
        ptr->next=temp;}

    }

}

void *dequeue(n1 **rear,n1 **front)
{
    n1 *ptr;
    ptr=(n1*)malloc(sizeof(n1));
    ptr=*front;
    if(*front==*rear)
        printf("queue is empty");
    else
    {
        printf("%d\n",ptr->info);
        *front=(*front)->next;
        ptr->next=NULL;
        free(ptr);

    }
}
void display(n1 *front)
{
    while(front!=NULL)
    {
        printf("%d\n",front->info);
        front=front->next;
    }
}



int main()
{ system("cls");

  n1 *front=NULL;
  n1 *rear=NULL;
  int choice;
  while(1)
  {
   printf("Enter the choice\n1:to enter value\n2:to delete value\n3:display\n4:to exit");
   scanf("%d",&choice);
   if(choice==1)
       enqueue(&rear,&front);

   if(choice==2)
       dequeue(&rear,&front);

   if(choice==3)
       display(front);

   if(choice==4)
      exit(0);
  }
  return;
}

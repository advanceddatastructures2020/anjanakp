#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
struct node *prev;
struct node *next;
int data;
};
struct node *head;
void insertion_begining();
void insertion_last();
void insertion_specified();
void display();
void main()
{
int choice=0;
clrscr();;
while(choice!=9)
{
printf("\n************MAIN MENU************\n");
printf("Choice one option from the following list....\n");
printf("\n==============================================\n");
printf("\n 1.Insert in the begining\n 2.Insert at the end\n 3.Insert at any random location\n 4.Delete from begining\n 5.Delete from the end\n 6.Delete the node after the given data\n 7.Search\n 8.Display\n 9.Exit\n") ;
printf("\n Enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
insertion_begining();
break;
case 2:
insertion_last();
break;
case 3:
insertion_specified();
break;
case 8:
display();
break;
case 9:
exit(0);
break;
default:
printf("Please enter valid choice...");
}
}
getch();
}
void insertion_begining()
{
struct node *ptr;
int item;
ptr=(struct node *)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("\n OVERFLOW");
}
else
{
printf("Enter item value:");
scanf("%d",&item);
if(head==NULL)
{
ptr->next=NULL;
ptr->prev=NULL;
ptr->data=item;
head=ptr;
}
else
{
ptr->data=item;
ptr->prev=NULL;
ptr->next=head;
head->prev=ptr;
head=ptr;
}
printf("\n Node inserted\n");
}
}
void insertion_last()
{
struct node *ptr,*temp;
int item;
ptr=(struct node *)malloc(sizeof(struct node)) ;
if(ptr==NULL)
{
printf("\n OVERFLOW");
}
else
{
printf("\n Enter value:");
scanf("%d",&item);
ptr->data=item;
if(head==NULL)
{
ptr->next=NULL;
ptr->prev=NULL;
head=ptr;
}
else
{
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=ptr;
ptr->prev=temp;
ptr->next=NULL;
}
}
printf("\n Node inserted\n");
}
void insertion_specified()
{
struct node *ptr,*temp;
int item,loc,i;
ptr=(struct node *)malloc(sizeof(struct node)) ;
if(ptr==NULL)
{
printf("\n OVERFLOW");
}
else
{
temp=head;
printf("Enter the location:");
scanf("%d",&loc) ;
for(i=0;i<loc;i++)
{
temp=temp->next;
if(temp==NULL)
{
printf("There are less than %d elements",loc) ;
return;
}
}
printf("Enter value:");
scanf("%d",item);
ptr->data=item;
ptr->next=temp->next;
ptr->prev=temp;
temp->next=ptr;
temp->next->prev=ptr;
printf("%d Node inserted");
}
}
void display()
{
struct node * ptr;
printf("\n Printing values....\n");
ptr=head;
while(ptr!=NULL)
{
printf("%d\n",ptr->data);
ptr=ptr->next;
}
}






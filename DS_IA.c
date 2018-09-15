#include<stdio.h>
#include<stdlib.h>

/*PROBLEM STATEMENT: 

Count all the duplicate elements present in the linked list, remove the duplicates(single element and multiple elements) and sort the linked list.

PROBLEM SOLUTION CONTRIBUTORS: 

1. Nikhil Bhardwaj (1711068)
2. Arghyadeep Das (1711072)
3. Chirag Jethwa (1711085)
4. Arnav Mankad (1711093)
5. Jaydeep Pawar (1711102)
*/

typedef struct node //node of the linked list to store integer type data.
{
    int data; //integer type data to be stored
    struct node *next; //pointer of struct node type to point to next node
}NODE;

NODE *end; //end pointer
NODE *start; //start pointer
int count=0;
int max=0;

int insert(int x,int position) //function to insert an element at specified position, both provided by user.
{
    NODE *ptr,*p;
    int i;
    ptr=(NODE*)malloc(sizeof(NODE)); //memory allocation for a new node
    ptr->data=x; //storing data in the newly created node
    ptr->next=NULL; 
    if(x>max)
        max=x; //identifying the largest element entered
    if(ptr==NULL)
        return 0;
    else if(count==0)
        start=end=ptr; //error handling while entering first node
    else if(position>count)
    {
        end->next=ptr;
        end=ptr;
        end->next=NULL;
    }
    else if(position<=1)
    {
        ptr->next=start;
        start=ptr;
    }
    else   //enter the element at the specified position by reshuffling the link
    {
      p=start;
      for(i=1;i<position-1;i++)
      {
          p=p->next;
      }
      ptr->next=p->next;
      p->next=ptr;
    }
    count++;
    return 1;
}

void duplicate() //function to identify the duplicates and count their number of occurences. 
{
    NODE *p;
    int temp,i,rpt, flag=0;
    for(i=0;i<=max;i++)
    {
        p=start;
        rpt=0;
        while(p!=NULL)
        {
            if(i==p->data) //if value matches the current node data, increment rpt counter.
            {
                rpt++;
                temp=i;
            }
            p=p->next;
        }
        if(rpt!=0 && rpt!=1){ //check for repeat elements and print them
            printf("%d is repeated %d times.\n",temp,rpt);
            flag=1;
            }
    }
    if(flag==0) //if no duplicates
    printf("\nNo duplicates in linked list hurray!\n");
}

void sort() //function to first remove the duplicates and then sort the linked list
{
    NODE *s,*q,*p;
    int i,j;
    int temp;
    s=start;
    //Removing duplicates first
    while(s!=NULL)
    {
      p=s;
      q=s->next;
      while(q!=NULL)
      {
          if(q->data==s->data)
          {
            if(q==end) //checking if repeat element is the last node data
                {
                p->next=NULL;
                end=p;
                }
            else{ //skip over the repeat element and connect to next node
                p->next=q->next;
              }
            free(q); //release the memory for repeat node
            q=p->next; 
          }
          else
          {
            p=p->next;
            q=q->next;
          }
      }
      s=s->next;
    }
    //Now that duplicates have been removed, we now sort the linked list using bubble sort
    for(j=1;j<=count;j++)
    {
        for(i=1;i<=count;i++)
        {
            p=start;
            q=start->next;
            while(q!=NULL)
            {
                if(p->data>q->data) //swapping data of adjacent nodes
                {
                    temp=p->data;
                    p->data=q->data;
                    q->data=temp;
                }
                q=q->next;
                p=p->next;
            }
        }
    }
    printf("The duplicates were removed and the linked list is sorted.");
}

void traverse() //function to traverse the linked list
{
    int i;
    NODE *p;
    p=start;
    printf("The elements present in the linked list are: \n");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void main(){  //driver function

    int option,x,position;
    printf("Welcome!\n");
    do{
        printf("\n1. Insert an element\n2. Find duplicates\n3. Remove duplicates and sort the linked list\n4. Traverse the linked list\n5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("\nEnter the element to be inserted along with position:\n");
                scanf("%d %d",&x,&position);
                if(insert(x,position))
                    printf("Operation successful.\n");
                else
                    printf("Memory full!\n");
                break;
            case 2:
                duplicate();
                break;
            case 3:
                sort();
                break;
            case 4:
                traverse();
                break;
            case 5:
                exit(1);
            default:
                printf("\nPlease enter a valid option. Thank you.");
        }
    }while(option!=5);
}

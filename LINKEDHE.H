//******************************************************************
//                      BTECH (CS) 2ND YEAR DS PROJECT 
                          Header files created by-:
//                      VIDHI SINGH and PRERNA MOHAN-1812824
//******************************************************************
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void display();
int siz;
struct node{
int info;
struct node *next;
};
typedef struct node *NODE;
NODE s;
NODE insertf(NODE  s,int x)
{
NODE temp;
temp=(NODE )malloc(sizeof(struct node));

temp->info=x;
temp->next=NULL;
if(s==NULL)
s=temp;
else
{
temp->next=s;
s=temp;
}
return(s);
}
NODE insertl(NODE s,int x)
{
NODE temp,t;
temp=(NODE)malloc(sizeof(struct node ));
temp->info=x;
temp->next=NULL;

  if( s==NULL)
 s=temp;
 else
 {
 for(t=s;t->next!=NULL;t=t->next);
     t->next=temp;
 }
return(s);
 }
NODE create_node(NODE temp,int x)
{

temp=(NODE)malloc(sizeof(struct node ));
temp->info=x;
temp->next=NULL;
return (temp);
}
int size()
{

NODE temp;
for(temp=s,siz=1;temp!=NULL;siz++,temp=temp->next)  ;
/*{  ++i;
printf("%d \n ",i);
} */
return (--siz);
}

NODE insertsp(NODE s,int x,int pos)
 {
 NODE temp,t;
   int i,l;
   l=size();
 if(pos>1&&pos<=l)
 {
     temp= create_node(  temp,x);
      for(t=s,i=1;i<pos-1;i++,t=t->next) ;
      temp->next=t->next;
      t->next=temp;
}
      else
      printf("\nInvalid Insertion\n");
return(s);
}
NODE insertmid(NODE s,int num)
{
int x=size();
if(x%2==0)
{
x=x/2+1;
insertsp(s,num,x+1);
}
else
insertsp(s,num,x/2);
return(s);
}

NODE deletef(NODE s)
{
NODE t;int x;
if(s==NULL)
printf("\n No node\n");
else
{  t=s;
   x=t->info;
   s=t->next;
   printf("\n%d deleted\n",x);
   }
return(s);
   }
NODE deletel(NODE s)
{
NODE p,t;   int x;
if(s==NULL)
printf("\nNo node \n");
else
{
for(t=s;t->next!=NULL;p=t,t=t->next);
p->next=NULL;
  x=t->info;
free(t);
printf("\n%d deleted\n",x);
}
  return(s);
}



NODE deletesp(NODE s,int pos)
{
int i;
NODE p,t,j;
for( i=1,t=s;i<pos;i++, p=t,t=t->next) ;
j=t;
  printf("\n%d deleted\n",j->info);
  p->next=t->next;
  free(j);
return(s);
}
NODE search(NODE s,int x)
 {
 NODE t;
 for(t=s;t!=NULL;t=t->next)
{
 if(x==t->info)
 {
printf("\nSearched\n");
  }
}
printf("\nNot searched\n");
return(s);
}
/*void main()
{
int x=0,n,pos;
clrscr();
do
{
printf("enter 1 to exit, 2 to insertf 3 to insertl, 4 to display,5 size,6 insertsp,7-deletef,8-deletel,9-deletesp,10-sort,11-search,12-insertmid");
scanf("%d",&n);
switch(n)
{
case 12:
printf("enter the num");
scanf("%d",&x);
insertmid(x);
break;
case 2:
printf("enter the number");
scanf("%d",&x);
insertf(x);
break;
case 3:
 printf("enter the number");
scanf("%d",&x);
insertl(x);
break;
case 4:
display();
break;
case 5:
x=size();
printf("\n\n\n%d",x);
break;
case 6:
printf("enter the number and pos");
scanf("%d %d",&x,&pos);
insertsp(x,pos);
break;
case 7:
x=deletef();
printf("%d",x);
break;
case 8:
x=deletel();
printf("number deleted %d ",x);
break;
case 9:
printf("enter the position");
scanf("%d",x);
deletesp(x);
break;
case 10:
sort();
break;
case 11:
printf("enter the element to be searched");
scanf("%d",&x);
x=search(x);
if(x==0)
printf("searched");
else
printf("not searched");
break;
case 12:
reversal();
break;


}}while(n!=1 );
getch();
}*/
void display(NODE s)
{
NODE t;
if(s==NULL)
printf("\nEmpty\n");
else
{
printf("\nThe elements are:\n");
for(t= s; t!=NULL;t=t->next)
printf("%d\n",t->info);
}

}




NODE sort(NODE start)
{
NODE p,t;
int x;
if(start==NULL)
{
printf("No Element to be sorted\n");
}
else
{
for(t=start;t->next!=NULL;t=t->next)
    for(p=t;p->next;p=p->next)
	  if(t->info>t->info)
	    {
	       x=t->info;
	       t->info=p->info;
	       p->info=x;
	    }
}
return start;
}
void help_linkedlist()
{
printf("    ******************************************************************\n");
printf("                             Header files created by\n");
printf("                          VIDHI SINGH and PRERNA MOHAN\n");
printf("    ******************************************************************\n");
printf("\nTo create a linkedlist just intialize a starting node by declaring a local initial node of pointer type using:NODE name_of_the_node");
printf("\nTo insert an element at end of the linkedlist:\nFunction used:name_of_node=insertl(name_of_node,name_of_integer_variable)");
printf("\nTo insert an element at starting of the linkedlist:\nFunction used:name_of_node=inserts(name_of_node,name_of _integer_variable)");
printf("\nTo insert an element at specified position of the linkedlist:\nFunction used:name_of_node=insertsp(name_of_node,name_of _integer_variable)");
printf("\nTo insert an element at middle of linkedlist:\nFunction used:name_of_node=insertmid(name_of_node,name_of_integer_variable)");
printf("\nTo delete an element from the end of the linkedlist:\nFunction used:name_of_node=deletel(name_of_node)");
printf("\nTo delete an element from the starting of the linkedlist:\nFunction used:name_of_node=deletef(name_of_node)");
printf("\nTo delete an element from the specified position of the linkedlist:\nFunction used: name_of_node=deltesp(name_of_node,position)");
printf("\nTo sort the linkedlist in ascending order:\nFunction used:name_of_node=sort(name_of_node)");
printf("\nTo dispaly the size of the linked list:\nFunction used:name_of_node=size(name_of_node)");
}
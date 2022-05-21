#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
#include<string.h>
#define WOMAN 0
#define MAN 1
struct person
{char name[15];
 int sex; 
 char number[15];
 char addr[20];
};

typedef struct nodes
{struct person data;
 struct nodes *next;
}node;

int main()
{void makemenu();
 void function1(node *h);
 void function2(node *h);
 void function3(node *h);
 void function4(node *h);
 void function5(node *h);
 void function6(node *h);
 void copyright();
	int choice;
	node *h;
	h=(node*)malloc (sizeof(node));
	h->next=0;
	while(1)
    {makemenu();
	scanf("%i",&choice);
	if(choice==0) break;
	else if(choice==1) function1(h);
	else if(choice==2) function2(h);
    else if(choice==3) function3(h);
	else if(choice==4) function4(h);
	else if(choice==5) function5(h);
	else if(choice==6) function6(h);
    else if(choice==8) copyright();
	else {printf("error\n");}
	 system("PAUSE");
	}
	return 0;
} 
//主函数
void makemenu()
{printf("---------------------------------------------------------------\n");
 printf("                       Address list                       \n");
 printf("1.display all           2.add info           3.revise info\n");
 printf("4.search people         5.filter             6.delate\n"); 
 printf("                        0.exit                       \n"); 
 printf("---------------------------------------------------------------\n");
 printf("                  copyright by carlsberg                       \n"); 
 printf("input the function number and press 'Enter':");
	return;
}

void function1(node *h)
{if(h->next==0)
	{printf("\nno infomation in the list now\n\n");}
 else
 {h=h->next;
	 while(h->next!=0)
 { printf("%-15s",h->data.name);
	 if(h->data.sex==WOMAN) {printf("woman\t");}
	 else if(h->data.sex==MAN) {printf("man\t");}
 printf("%-15s",h->data.number);
 printf("%s\n",h->data.addr);
 h=h->next;
 }
 printf("%-15s",h->data.name);
 if(h->data.sex==WOMAN) {printf("woman\t");}
 else if(h->data.sex==MAN) {printf("man\t");}
 printf("%-15s",h->data.number);
 printf("%s\n",h->data.addr);
 }
 return;
}

void function2(node *h)
{ while(h->next!=NULL)
{h=h->next;}
 h->next=(node*)malloc (sizeof(node));
 printf("input name: ");
 scanf("%s",&h->next->data.name);
 printf("input sex:(women with 0,man with1) ");
 scanf("%i",&h->next->data.sex);
 printf("input phone number: ");
 scanf("%s",&h->next->data.number);
 printf("input address: ");
 scanf("%s",&h->next->data.addr);
 h->next->next=NULL;
 printf("susccessfully added\n");
 return;
}

void function3(node *h)
{int i=1,j;
 node *head;
 head=h;
	if(h->next==0)
	{printf("\nno infomation in the list now\n\n");}
 else
 {	 h=h->next;
	 while(h->next!=0)
	 { printf("%i:",i);
	   i++;
		 printf("%-15s",h->data.name);
	 if(h->data.sex==WOMAN) {printf("woman\t");}
	 else if(h->data.sex==MAN) {printf("man\t");}
 printf("%-15s",h->data.number);
 printf("%s\n",h->data.addr);
 h=h->next;
 }
	 printf("%i:",i);
 printf("%-15s",h->data.name);
 if(h->data.sex==WOMAN) {printf("woman\t");}
 else if(h->data.sex==MAN) {printf("man\t");}
 printf("%-15s",h->data.number);
 printf("%s\n",h->data.addr);
 printf("revise number:");
 scanf("%i",&j);
 for(i=0;i<j;i++)
	 {head=head->next;}
 printf("1.name 2.sex 3.phone number 4.address\nyou want to revise:");
 scanf("%i",&j);
 if(j==1)
 {printf("revise to:");
 scanf("%s",head->data.name);
 }
 else if(j==2&&head->data.sex==0) head->data.sex=1;
 else if(j==2&&head->data.sex==1) head->data.sex=0;
 else if(j==3)
 {printf("revise to:");
 scanf("%s",head->data.number);
 }
 else if(j==4)
 {printf("revise to:");
 scanf("%s",head->data.addr);
 }
 }
 printf("susccessfully\n");
 return;
}

void function4(node *h)
{int i=1,j;
 node *head;
 head=h;
 if(h->next==0)
	{printf("\nno infomation in the list now\n\n");}
  else
  {   h=h->next;
	 while(h->next!=0)
	 { printf("%i:",i);
	   printf("%s\n",h->data.name);
	   i++;
	   h=h->next;
	 }
	   printf("%i:",i);
	   printf("%s\n",h->data.name);
       printf("get the information of number:");
	 scanf("%i",&j);
     for(i=0;i<j;i++)
	 {head=head->next;}
	 printf("%-15s",head->data.name);
     if(head->data.sex==WOMAN) {printf("woman\t");}
     else if(head->data.sex==MAN) {printf("man\t");}
     printf("%-15s",head->data.number);
     printf("%s\n",head->data.addr);
	 printf("successfully got");
	 return;
	}
}


void function5(node*h)
{void sexjudge(node *h,int x);
 void addrjudge(node *h);
 int x;
  if(h->next==0)
 {printf("\nno information in the list now\n\n"); }
else
{printf("1.sex 2.address\nfilter:");
  scanf("%i",&x);
     if(x==1)
	 {
	  printf("0.woman 1.man\nyou want to filter:");
      scanf("%i",&x);
      sexjudge(h,x);
	 }
	 else if(x==2)
	 {addrjudge(h);}
	 else{printf("error\n");
	      return;
	 }
	 
}
return;
}


void function6(node *h)
{int i=1,j;
 node *head;
 head=h;
 if(h->next==0)
	{printf("\nno information in the list now\n\n");}
  else
  {   h=h->next;
	 while(h->next!=0)
	 { printf("%i:",i);
	   printf("%s\n",h->data.name);
	   i++;
	   h=h->next;
	 }
	   printf("%i:",i);
	   printf("%s\n",h->data.name);
	 printf("delate number:");
	 scanf("%i",&j);
     for(i=1;i<j;i++)
	 {head=head->next;}
    head->next=head->next->next;
  }
  printf("successfully delated\n");
     return;
}

void sexjudge(node *h,int x)
{int num=0;
  h=h->next;
  while(h->next!=0)
  {    if(h->data.sex==x)
  { printf("%-15s",h->data.name);
  if(h->data.sex==WOMAN) {printf("woman\t");}
  else if(h->data.sex==MAN) {printf("man\t");}
       printf("%-15s",h->data.number);
       printf("%s\n",h->data.addr);
    num++;
  }
       h=h->next;
  }
     if(h->data.sex==x)
  { printf("%-15s",h->data.name);
       if(h->data.sex==WOMAN) {printf("woman\t");}
       else if(h->data.sex==MAN) {printf("man\t");}
       printf("%-15s",h->data.number);
       printf("%s\n",h->data.addr);
    num++;
	 }
	 if(num==0)
   {printf("there is no such a people\n");
          return;
    }
   else printf("successfully got\n");
 }

 void addrjudge(node *h)
 {char ad[30][20];
   int i,j=0;
   node *head;
   head=h;
 for(i=0;i<30;i++)
   for(j=0;j<20;j++)
   {ad[i][j]=0;}
   h=h->next;
   j=0;
  while(h->next!=0)
  {for(i=0;i<30;i++)
  {if(strcmp(h->data.addr,ad[i])==0) break;
   else if(strcmp(h->data.addr,ad[i])!=0&&i==29)
    {strcpy(ad[j],h->data.addr);
     j++;}
  }
  h=h->next;
  }
  for(i=0;i<30;i++)
  {if(strcmp(h->data.addr,ad[i])==0) break;
   if(strcmp(h->data.addr,ad[i])!=0&&i==29)
    {strcpy(ad[j],h->data.addr);
     j++;}
  }
  i=0;
  for(i=0;i<30;i++)
  {if(ad[i][0]!=0)
  printf("%i:%s\n",i+1,ad[i]);
  }
  printf("input the address you want to search for:");
  scanf("%i",&i);
  h=head;

	 while(h->next!=0)
	 {  if(strcmp(h->data.addr,ad[i-1])==0)
	 {	 printf("%-15s",h->data.name);
	 if(h->data.sex==WOMAN) {printf("woman\t");}
	 else if(h->data.sex==MAN) {printf("man\t");}
 printf("%-15s",h->data.number);
 printf("%s\n",h->data.addr);}
 h=h->next;
 }
	  if(strcmp(h->data.addr,ad[i-1])==0)
	  { printf("%-15s",h->data.name);
      if(h->data.sex==WOMAN) {printf("woman\t");}
      else if(h->data.sex==MAN) {printf("man\t");}
      printf("%-15s",h->data.number);
      printf("%s\n",h->data.addr);
	  }
	  printf("successfully got\n");
  return;
 }

 void copyright()
 {     
     printf("this is a program fully based on C\n");
     printf("written on visual studio code\n");
     printf("follow me on github:https://github.com/carlsberg03 (￣▽ ￣)\n");
 }

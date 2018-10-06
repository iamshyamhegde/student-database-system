#include<stdio.h>
#include<stdlib.h>
struct sll
{
  	 int id;
  	 char *name;
  	 char *course;
  	 float amount;
  	 struct sll *next;
};
       	typedef struct sll student;
      	student *first=NULL,*last=NULL;

void create(char* na,int rol,char* cour,float fee)
{
	student *new = (student*)malloc(sizeof(student));
     	if(first==NULL)
      	{
          	new->name=na;
           	new->id=rol;
          	new->course=cour;
               	new->amount=fee;
                new->next=NULL;
                first=new;
                last=new;
      	}
      else
       {
               new->name=na;
               new->id=rol;
               new->course=cour;
               new->amount=fee;
               new->next=NULL;
               last->next=NULL;
               last->next=new;
               last=new;
       }

	student *temp = first, *temp1;
	for(temp = first; temp->next != NULL; temp = temp->next)
	{
		for(temp1 = temp->next; temp1 != NULL; temp1 = temp1->next)
		{
			if(temp->id > temp1->id)
			{
				int dummy = temp->id;
				temp->id = temp1->id;
				temp1->id = dummy;
			}
		}

	}
	temp1 = temp->next;
	while(temp1)
	{
		printf("%s\t%d\t%s\t%f\n", temp1->name,temp1->id,temp1->course,temp1->amount);
		temp1 = temp1->next;
	}
}


void display()
{
      student *temp=first;
      while(temp!=NULL)
      {
        printf("\nNAME=%s\n",temp->name);
        printf("ID=%d\n",temp->id);
        printf("COURSE=%s\n",temp->course);
        printf("AMOUNT=%f\n",temp->amount);
        temp=temp->next;
      }
}

void delete(int key)
{

//     	printf("\nenter the roll number do delete\n");
  //   	scanf("%d",&key);
     	student *temp=first,*temp1;
     	if(temp->id==key)
       	{
        	first=first->next;
        	free(temp);
                printf("after deleting student details\n");
        	display();
       	}
      	else
	{
        	while(temp->id!=key)
           	{
        		temp1=temp;
			temp=temp->next;
           	}
          	temp1->next=temp->next;
		free(temp);
                printf("student details after deleting\n");
		display();
        }
       
  }
 
void display_one()
{
        int key;
	student *temp=first,*temp1;
        printf("To display individual student-enter student ID\n");
        scanf("%d",&key);
        if(key==temp->id)
	{
          printf("\nName=%s\nID=%d\ncourse=%s\namount= %f\n",temp->name,temp->id,temp->course,temp->amount);
        }
        else if(key!=temp->id)
        {
       		 while(temp->id!=key)
         	  {
             		temp1=temp;
             		temp=temp->next;
          	  }
            		printf("\nName=%s\nID=%d\ncourse= %s\namount= %f\n",temp->name,temp->id,temp->course,temp->amount);
        }
}

int main()
{
	int key,n,choice, roll,id,id1, roll1;
        printf("student database\n");
        label1:
        printf("enter 1 to add 3 student\n");
        printf("enter 2 to adding one more student\n");
        printf("enter 3 to deleting student\n");
        printf("enter 4 to display student details\n");
        printf("enter 5 to store a data\n");
        printf("enter 6 to exit\n");
     printf("enter your choice\n");
     scanf("%d",&choice);
      switch(choice)
      {
              case 1:
              {
     	create("shyam",150," C",20000.1);
      	create("manu",300," C++",30000.1); 
      	create("santu",200," C#",40000.1);
       	display();
             }
        case 2:
        printf("Wish to add one more student details\n");
	printf("If yes press 2\n");
	scanf("%d", &choice);
	if(choice == 2)
	{
     		printf("\nafter inserting new student\n");
      		create("Ram",400," Cobol",50000.1);
       		display();
        } 
	case 3:
        printf("\nwish to delete student detail\n");
        printf("If yes,press 3\n");
        scanf("%d",&choice);
	if(choice == 3)
	{
           printf("enter the student ID\n");
           scanf("%d",&key);
		delete(key);
	}
	
        
	printf("Wish to delete one more student record\n");
	printf("If yes, press 4\n For next option press 5\n");
        scanf("%d",&choice);
        if(choice==4)
        {
           printf("enter the student ID\n");
           scanf("%d",&key);
           delete(key);
        }
       
       // printf("Go to next option,press 5\n");
//	printf("Enter your choice\n");
       // scanf("%d",&choice);
        if(choice == 4)
        {
          	 printf("enter the student ID\n");
          	 scanf("%d",&roll1);
          	 if(roll1 == key)
          	 {
         		printf(" student details is already deleted\n");
         	 }
           	 else if(roll != roll)
           	{
              		delete(roll1);
           	}
         }
	else if(choice == 5)
	{
		goto label3;
	}
        
	case 4:
	label3:
        printf("\nTo display all student press 1\nTo display individual student-press 2\nFor other option press 3\n ");
       	 scanf("%d",&choice);
        if(choice == 1)
        {
       	   	display();
        }
       	else if(choice == 2)
	{
		goto label4;
	}
	else
	{
		goto label5;
	}

       label4:
       printf("Individual students display-press 2\nchoice 3 for other\n");
       scanf("%d",&choice);
       if(choice == 2)
       {
       		printf("Enter the student Id\n");
		scanf("%d",&id);
		display_one();
       }
	
	printf("Wish to display one more student details\n");
	printf("If yes press 1\n");
	printf("If no, press 2 for other option\n");
	scanf("%d",&n);
       if(n == 1)
	{
		goto label4; 
	}
	else if(n == 2)
	{
		goto label5;
	}

        case 5:
	label5:
        printf("To store in file-select 5\n");
        scanf("%d",&choice);
        if(choice==5)
        {
            student *temp = first; 
            FILE *fp = fopen("file_link","w+");
	    if(fp == NULL)
	    {
		printf("File is not opened\n");
		 exit(1);
	    }
	    else
	    {
	      while(temp != NULL)
	       {
	      fprintf(fp,"Name = %s\tID = %d\tCourse = %s\tFees = %f\n",temp->name,temp->id,temp->course,temp->amount);
	      printf("Name = %s\tID = %d\tCourse = %s\tFees = %f\n",temp->name,temp->id,temp->course,temp->amount);
	      temp = temp->next;
	        }
	      }
	      fclose(fp);		
	}
     }
}
    

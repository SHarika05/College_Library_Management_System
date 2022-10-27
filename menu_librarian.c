#include<functions.h>
#include<macros.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<struct.h>
book *head = NULL;
stud *head1= NULL;
int validatename(char *bookname)
{
	for(int i=0; i<strlen(bookname); i++)
	{
		if (isalpha(bookname[i]))
			continue;
		else
			return 0;
	}
	return 1;
}
int validatestudentname(char *studentname)
{
	for(int i=0;i<strlen(studentname);i++)
	{
		if(isalpha(studentname[i]))
			continue;
		else
			return 0;
	}
}
void add_record( )
{
	FILE *fp = fopen("../data/book.txt","a");
	book *temp = (book *)calloc(1,sizeof(book));
	int qty=0;
	while(1)
	{
		printf("\nEnter the Book Id ");
		scanf("%d",&temp->id);
                //break;
		if(temp->id>1000)
			printf("\nPlease enter the book number between 1 to 999");
		else
			break;
	}
	while(1)
	{
		printf("\nEnter the Book Name ");
		scanf("%s",temp->bookname);
		if(validatename(temp->bookname))
				break;
		else
			printf("Book name is not valid ");
	}
	printf("\nEnter the Author Name ");
	scanf("%s",temp->authorname);
	printf("\nEnter Quantity");
	scanf("%d",&temp->qty);
	temp->link = NULL;
	if(head == NULL)
	{
		head = temp;
		
		fprintf(fp,"%d %s %s %d \n",temp->id,temp->bookname,temp->authorname,temp->qty);
		
	}
	else
	{
		book *q = head;
		while(q->link != NULL)
		{
			qty++;
			q=q->link;
		}
		q->link = temp;
		fprintf(fp,"%d %s %s %d\n",temp->id,temp->bookname,temp->authorname,temp->qty);
		//printf("Total Books are : %d",qty);
	} 
	fclose(fp);
}
void display()
{
	//char ch;
	FILE *fr = fopen("../data/book.txt","r");
	/*while((ch = getchar())!=EOF)
	{
		putc(ch,fr);
	}*/
	
	if(fr == NULL)
	{
		printf("File does not exists ");
	}
	else
	{
		char bookname[MAX];
		char authorname[MAX];
		int id,qty;
		printf("\n****************************************\n");
		printf("*           DETAILS OF BOOKS             *");
		printf("\n****************************************\n");
		book *start=NULL;
		//printf("%d","Book ID");
		printf("%-10s%-20s%-20s%s","Book ID","Book Name","Author Name","Quantity");
		fscanf(fr,"%d%s%s%d",&id,bookname,authorname,&qty);
		
		while(!feof(fr))
		{
			book *temp = (book *) calloc(1,sizeof(book));
			temp->id = id;
			strcpy(temp->bookname,bookname);
			strcpy(temp->authorname,authorname);
			temp->qty = qty;
			temp->link = NULL;
			if(start == NULL)
				start = temp;
			else
			{
				book *q = start;
				while(q->link != NULL)
					q=q->link;
				q->link = temp;
			}
			fscanf(fr,"%d%s%s%d",&id,bookname,authorname,&qty);
		}
		fclose(fr);
		book *q = start;
		while(q!=NULL)
		{
			printf("\n%-10d%-20s%-20s%d",q->id,q->bookname,q->authorname,q->qty);
			q=q->link;

		}
	}
}
void search()
{
	FILE *fr = fopen("../data/book.txt","r");
	book *temp=(book *)calloc(1,sizeof(book));
	if(fr == NULL)
	{
		printf("\nFile doesn't Exist");
	}
	else
	{
		int item,i=0,flag;
		printf("\n*****************************************\n");
		printf("*   		SEARCH BOOKS		  *");
		printf("\n*****************************************\n");
		while(!feof(fr))
		{
			if(head == NULL)
				printf("\nLinked list is empty ");
			else
			{
				int key;
				printf("\nEnter book ID ");
				scanf("%d",&key);
				for(book *q = head;q!=NULL; q=q->link)
				{
					if(key == q->id)
					{
						printf("\nBook Found ");
						printf("\nBook ID : %d",q->id);
						printf("\nBook Name : %s",q->bookname);
						printf("\nAuthor Name : %s",q->authorname);
						break;
					}
					else
						printf("\nBook Not Found ");
				}
			}
		}
		fclose(fr);
	}
}
void Delete()
{
	
	
      FILE *fr= fopen("../data/book.txt","r");
      FILE *fw = fopen("../data/temp.txt","w");
    int no;
    printf("\nEnter the book number to be deleted ");
    scanf("%d",&no);
    int bno,q;
    char bname[20] , aname[20];
    fscanf(fr,"%d%s%s%d",&bno,bname,aname,&q);
  
    while(!feof(fr))
    {
        if(bno != no)
        {
	    
	    printf("%d%s%s%d",bno,bname,aname,q);
            fprintf(fw,"%d %s %s %d\n",bno,bname,aname,q);
	    break;
        }
        fscanf(fr,"%d%s%s",&bno,bname,aname);

	
    }
    remove("../data/book.txt");
    fclose(fw);
    rename("../data/temp.txt","../data/book.txt");
    fclose(fr);
}
void Add_student()
{

	FILE *fp = fopen("../data/student.txt","a");
	stud *temp = (stud *)calloc(1,sizeof(stud));
	while(1)
	{
		printf("\nEnter the Student Id ");
		scanf("%d",&temp->studentid);
                //break;
		if(temp->studentid>100)
			printf("\nPlease enter the student ID between 1 to 100");
		else
			break;
	}
	while(1)
	{
		printf("\nEnter the student Name ");
		scanf("%s",temp->studentname);
		if(validatestudentname(temp->studentname))
				break;
		else
			printf("student name is not valid ");
	}
	printf("\nEnter the course Name ");
	scanf("%s",temp->coursename);
	while(1)
	{
		printf("\nEnter Year ");
		scanf("%d",&temp->year);
		if(temp->year>4)
			printf("\nPlease enetr the year between 1 to 4 ");
		else
			break;
	}
	temp->link = NULL;
	if(head1 == NULL)
	{
		head1 = temp;
		fprintf(fp,"%d %s %s %d \n",temp->studentid,temp->studentname,temp->coursename,temp->year);

	}
	else
	{
		stud *q = head1;
		while(q->link != NULL)
			q=q->link;
		q->link = temp;
		fprintf(fp,"%d %s %s %d\n",temp->studentid,temp->studentname,temp->coursename,temp->year);
	}
	fclose(fp);
}
void Display_student()
{
	FILE *fr = fopen("../data/student.txt","r");
	/*while((ch = getchar())!=EOF)
	{
		putc(ch,fr);
	}*/

	if(fr == NULL)
	{
		printf("File does not exists ");
	}
	else
	{
		char studentname[MAX];
		char coursename[MAX];
		int studentid,year;
		printf("\n****************************************\n");
		printf("*           DETAILS OF STUDENTS             *");
		printf("\n****************************************\n");
		stud *start=NULL;
		printf("%-10s%-20s%-20s%s","Student ID","Student Name","Course Name","Year");
		fscanf(fr,"%d%s%s%d",&studentid,studentname,coursename,&year);

		while(!feof(fr))
		{
			stud *temp = (stud *) calloc(1,sizeof(stud));
			temp->studentid = studentid;
			strcpy(temp->studentname,studentname);
			strcpy(temp->coursename,coursename);
			temp->year = year;
			temp->link = NULL;
			if(start == NULL)
				start = temp;
			else
			{
				stud *q = start;
				while(q->link != NULL)
					q=q->link;
				q->link = temp;
			}
			fscanf(fr,"%d%s%s%d",&studentid,studentname,coursename,&year);
		}
		fclose(fr);
		stud *q = start;
		while(q!=NULL)
		{
			printf("\n%-10d%-20s%-20s%d",q->studentid,q->studentname,q->coursename,q->year);
			q=q->link;
		}
	}
}
void Search_student()
{
	FILE *fr = fopen("../data/student.txt","r");
	stud *temp=(stud *)calloc(1,sizeof(stud));
	if(fr == NULL)
	{
		printf("\nFile doesn't Exist");
	}
	else
	{
		int item,i=0,flag;
		printf("\n*****************************************\n");
		printf("*   		SEARCH STUDENT		  *");
		printf("\n*****************************************\n");
		while(!feof(fr))
		{
			if(head1 == NULL)
				printf("\nLinked list is empty ");
			else
			{
				int key;
				printf("\nEnter student ID ");
				scanf("%d",&key);
				for(stud *q = head1;q!=NULL; q=q->link)
				{
					if(key == q->studentid)
					{
						printf("\nStudent Found ");
						printf("\nStudent ID : %d",q->studentid);
						printf("\nStudent Name : %s",q->studentname);
						printf("\nCourse Name : %s",q->coursename);
						printf("\nYear  : %d",q->year);
						break;
					}
					else
						printf("\nStudent Not Found ");
				}
			}
		}
		fclose(fr);
	}
}
void Delete_student()
{


    FILE *fr= fopen("../data/student.txt","r");
    FILE *fw = fopen("../data/temp1.txt","w");
    int no;
    printf("\nEnter the student id to be deleted ");
    scanf("%d",&no);
    int sno,y;
    char sname[20] , cname[20];
    fscanf(fr,"%d%s%s%d",&sno,sname,cname,&y);

    while(!feof(fr))
    {
        if(sno != no)
        {
	    printf("%d%s%s%d",sno,sname,cname,y);
            fprintf(fw,"%d %s %s %d\n",sno,sname,cname,y);
        }
        fscanf(fr,"%d%s%s%d",&sno,sname,cname,&y);
    }
    remove("../data/student.txt");
    fclose(fw);
    rename("../data/temp1.txt","../data/student.txt");
    fclose(fr);
}
void Issue_book()
{
	/*FILE *fw=fopen("../data/studentbook.txt","a");
	int sid,bid;
	char DOI[MAX];
	printf("\nEnter the book id ");
	scanf("%d",&bid);
	printf("\nEnter the Student id ");
	scanf("%d",&sid);
	printf("\nEnter Date of issue ");
	scanf("%s",DOI);
	fprintf(fw,"%d %d %s\n",bid,sid,DOI);
	fclose(fw);*/
	FILE *fw=fopen("../data/studentbook.txt","a");
    int sid,bid;
    char DOI[MAX];
    printf("\nEnter the book id ");
    scanf("%d",&bid);
    printf("\nEnter the Student id ");
    scanf("%d",&sid);
    printf("\nEnter Date of issue ");
    scanf("%s",DOI);
    fprintf(fw,"%d %d %s\n",bid,sid,DOI);
    fclose(fw);

    FILE *fr = fopen("../data/book.txt","r");
    FILE *fw1 = fopen("../data/temp.txt","w");

    int id ,q ;
    char bnm[20],anm[20];
    fscanf(fr,"%d%s%s%d",&id,bnm,anm,&q);
    while(!feof(fr))
    {
        if(id == bid)
        {
            q = q-1;
            //fprintf(fw1,"%d %s %s %d\n",id,bnm,anm,q);
        }
	fprintf(fw1,"%d %s %s %d\n",id,bnm,anm,q);
        fscanf(fr,"%d%s%s%d",&id,bnm,anm,&q);

    }
    fclose(fr);
    fclose(fw1);
    remove("../data/book.txt");
    rename("../data/temp.txt","../data/book.txt");
			


}

void menu_librarian( )
{
	int choice;
	book *head = NULL;
	while(1)
	{
		printf("\n1.Add Books\n2.Display Books\n3.Search For Book\n4.Delete Books\n5.Add Student\n6.Display Student\n7.Search For Student\n8.Delete Student\n9.Issue Books\n10.Back to main menu");
		printf("\nEnter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:add_record();
			       break;
			case 2:display();
			       break;
			case 3:search();
			       break;
			case 4:Delete();
			       break;
			case 5:Add_student();
			       break;
			case 6:Display_student();
			       break;
			case 7:Search_student();
			       break;
			case 8:Delete_student();
			       break;
			case 9:Issue_book();
			       break;
			case 10:options();
		}
	}
}


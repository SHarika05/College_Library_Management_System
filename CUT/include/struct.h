#pragma once
#include<macros.h>
typedef struct books
{
	int id,qty;
	char bookname[MAX],authorname[MAX];	
	struct books *link;
}book;
typedef struct students
{
	int studentid;
	char studentname[MAX];
	char coursename[MAX];
	int year;
	struct students *link;
}stud;
typedef struct book_student
{
 	int sid;
        int bno;
	char DOI[MAX];
	struct book_student* link;
}bs;

#include<macros.h>
#include<string.h>
#include<stdlib.h>
#include<functions.h>
#include<stdio.h>
int admin( )
{
	FILE *info;
	info = fopen("../data/password.txt","r");
	if(info == NULL)
	{
		printf("\n\n\tFile does not exists ");
		return 0;
	}
	else
	{
		clear( );
		char user[MAX],pass[MAX],username[MAX],password[MAX];
		fscanf(info,"%s %s",user,pass);
		fclose(info);
		printf("\n\n\tEnter the Username ");
		scanf("%s",username);
		printf("\n\n\tEnter the password ");
		scanf("%s",password);
		if( strcmp(user,username)==0 && strcmp(pass,password)==0)
		{
			printf("\n\t*********************************\n");
			printf("\n\tLibrarian Login Sucessfully\n");
			printf("\n\t**********************************");
			return 1;
		}
		else
			return 0;
	}
}


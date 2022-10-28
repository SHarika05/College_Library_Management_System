#include<stdio.h>
#include<stdlib.h>
#include<functions.h>
void options( )
{
	int choice;
	while(1)
	{
		clear( );
		//printf("\n\n\tPress 1 for Student ");
		printf("\n\n\tPress 1 for Librarian ");
		printf("\n\n\tPress 2 for Exit ");
		printf("\n\n\tPlease Enter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
		
			case 1:int result2 = admin( );
			       if(result2 == 1)
			       {
				       menu_librarian( );
			       }
			       else
				       printf("\nInvalid Admin ");
			       break;
			case 2:exit(0);
		}
	}
}


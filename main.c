#include <stdio.h>
#include <stdlib.h>
#include "clinic.h"
typedef enum
{
	add=1,
	edit,
	reserve,
	cancel
}admin;
typedef enum
{
	 view_patient_record=1,
	 view_today_reservations
}user;
# define FINISH 0
#define default_pass 1234
void main (void)
{
	char decision;
	char decision2;
	char finish;
	printf("*********WELLOME*********\n");
	do
	{
	printf("For Admin Mode press 1, for user mode press 2\n");
	scanf("%d",&decision);
	if (decision==1)
	{
		//Admin
		system("cls");
		take_pass();
		printf("Press: \n");
		printf("1 to Add new patient record\n");
		printf("2 to Edit patient record\n");
		printf("3 to Reserve a slot with the doctor\n");
		printf("4 to Cancel reservation\n");
		scanf("%d",&decision2);
		switch(decision2)
		{
			case add : add_patient (); break;
			case edit : edit_patient_info(); break;
			case reserve : reserve_slot_for_patient(); break;
			case cancel : cancel_reserve_for_patient(); break;
			default : printf("Invalid option\n"); break;
		}
		
	}
	else if (decision==2)
	{
		system("cls");
		printf("Press: \n");
		printf("1 to View patient record\n");
		printf("2 to View today’s reservation\n");
		scanf("%d",&decision2);
		switch(decision2)
		{
			case view_patient_record: view_patient_info(); break;
			case view_today_reservations: view_reservations(); break;
			default : printf("Invalid option\n"); break;
		}
		
	}
	else 
	{
		printf("Unvalid option\n");
		
	}
	printf("To finish the program press 0, to continue press anything else\n");
	scanf("%d",&finish);
	}while (finish!=FINISH);
}


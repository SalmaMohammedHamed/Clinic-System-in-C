#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "clinic.h"
/*------------------------------------------------------*/
void add_patient (void)
{
	unsigned short int scan_id;
	patient* user = add_element();
	patient* result=NULL;
	system("cls");
	printf("Add New Patient\n");
	printf("Patient ID: ");
	scanf("%d",&scan_id);
	result=search_element(id_type,scan_id);
	if (result==NULL)
	{
		printf("Enter your name: ");
		scanf(" %[^\n]",&(user->name));
		printf("Enter your age: ");
		scanf("%d",&(user->age));
		gender_input(user);
		user->id=scan_id;	
	}
	else
	{
		printf("This ID already exists\n");
	}
	
}
/*------------------------------------------------------*/
void edit_patient_info(void)
{
    patient* result = NULL;
    unsigned short int scan_id;
    system("cls");
    printf("Patient ID: ");
    scanf("%hu", &scan_id);
    result = search_element(id_type, scan_id);
    if (result != NULL)
    {
        printf("This patient data is: \n");
        display_element(result);
        int edit_type;
        printf("1 to edit Name\n");
        printf("2 to edit Age\n");
        printf("3 to edit Gender\n");
        printf("Choose what you want to edit: \n");
        scanf("%d", &edit_type);
        switch (edit_type)
        {
        case 1:
            printf("Enter the new name: ");
            scanf(" %[^\n]", &(result->name));
            break;
        case 2:
            printf("Enter the new age: ");
            scanf("%d", &(result->age));
            break;
        case 3:
            gender_input(result);
            break;
        default:
            printf("Invalid option\n");
        }
        printf("Updated patient data: \n");
        display_element(result);
    }
    else
    {
        printf("Incorrect ID\n");
    }
}
/*------------------------------------------------------*/
void reserve_slot_for_patient(void)
{
    patient* result = NULL;
    patient* result2 = NULL;
    unsigned short int choose_slot = 0;
    int i = 0;
    char flag = 0;
    unsigned short int scan_id;
    system("cls");
    for (i = slot2; i <= slot4_30; i++)
    {
        result = search_element(time_slot_type, i);
        if (result != NULL)
        {
            continue;
        }
        else
        {
            flag = 1;
            switch (i)
            {
            case slot2:
                printf("slot from 2 to 2:30 is available: for this slot press 1\n");
                break;
            case slot2_30:
                printf("slot from 2:30 to 3 is available: for this slot press 2\n");
                break;
            case slot3:
                printf("slot from 3 to 3:30 is available: for this slot press 3\n");
                break;
            case slot4:
                printf("slot from 4 to 4:30 is available: for this slot press 4\n");
                break;
            case slot4_30:
                printf("slot from 4:30 to 5 is available: for this slot press 5\n");
                break;
            }
        }
    }
    if (flag == 0)
    {
        printf("No available slots\n");
        return;
    }
    printf("Enter the time slot you want: ");
    scanf("%hu", &choose_slot);
    printf("%hu\n", choose_slot);
    printf("Enter your ID: ");
    scanf("%hu", &scan_id);
    result2 = search_element(id_type, scan_id);
    if (result2 != NULL)
    {
        result2->time_slot = choose_slot;
        printf("%hu\n", result2->time_slot);
        printf("Done\n");
    }
    else
    {
        printf("ID not found\n");
    }
}
/*------------------------------------------------------*/
void cancel_reserve_for_patient(void)
{
	patient* result=NULL;
	unsigned short int scan_id;
	system("cls");
	printf("Patient ID: ");
	scanf("%d",&scan_id);
	result=search_element(id_type,scan_id);
	if (result!=NULL)
	{
		result->time_slot=0;
		printf("DONE\n");
	}
	else
	{
		printf("Incorrect ID ");
	}
}
/*------------------------------------------------------*/
void view_patient_info (void)
{
	patient* result=NULL;
	unsigned short int scan_id;
	system("cls");
	printf("Patient ID: ");
	scanf("%d",&scan_id);
	result=search_element(id_type,scan_id);
	if (result!=NULL)
	{
		printf("your name is: %s\n",result->name);
		printf("your Age is: %d\n",result->age);
		printf("your Gender is: %c\n",result->gender);
		printf("your ID is: %d\n",result->id);
		printf("your Time slot is: %d\n",result->time_slot);
	}

	else
	{
		printf("This ID does not exist\n");
	}
	
}
/*------------------------------------------------------*/
void view_reservations (void)
{
	patient* temp = get_start();
	system("cls");
	while (temp!=NULL)
	{
		if (temp->time_slot!=0)
		{
			switch(temp->time_slot)
			{
				case slot2: printf("slot from 2 to 2:30, ID is %d\n",temp->id); break;
				case slot2_30: printf("slot from 2:30 to 3, ID is %d\n",temp->id); break;
				case slot3: printf("slot from 3 to 3:30, ID is %d\n",temp->id); break;
				case slot4: printf("slot from 4 to 4:30, ID is %d\n",temp->id); break;
				case slot4_30: printf("slot from 4:30 to 5, ID is %d\n",temp->id); break;
			}
		}
		temp=temp->next;
	}
}
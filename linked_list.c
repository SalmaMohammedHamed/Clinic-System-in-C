#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
static patient* start=NULL;
/*------------------------------------------------------*/
patient* creat_element()
{
    patient* new_element = (patient*)malloc(sizeof(patient));
    new_element->time_slot = 0;
    return new_element;
}
/*------------------------------------------------------*/
patient* add_element()
{
	patient* e = creat_element();
	e->next=NULL;
	if (start==NULL)
	{
		start = e;
		return e;
	}
	else
	{
		patient* temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		if (temp->next==NULL)
		{
			temp->next=e;
			return e;
		}
	}
	
}
/*------------------------------------------------------*/
patient* search_element(char type, unsigned short int value)
{
    patient* temp = start;
    while (temp != NULL)
    {
        if (type == id_type)
        {
            if (temp->id == value)
            {
                return temp;
            }
        }
        else if (type == time_slot_type)
        {
            if (temp->time_slot == value)
            {
                return temp;
            }
        }
        temp = temp->next; // Move to the next element in the list
    }
    return NULL;
}
/*------------------------------------------------------*/
patient* get_start ()
{
	return start;
}
/*------------------------------------------------------*/
void display_element (patient* element)
{
	printf("The name is: %s \n",element->name);
	printf("The ID is: %d \n",element->id);
	printf("The age is: %d \n",element->age);
	printf("The gender is: %c \n",element->gender);
	printf("The time slot is: %d \n",element->time_slot);
}
/*------------------------------------------------------*/
void gender_input(patient* user)
{
	char scan_gender;
	printf("Enter your gender (F for female or M for male): ");
	while((scan_gender!='F') && (scan_gender!='M'))
			{
				printf("Enter a valid gender (F for female or M for male): ");
				scanf(" %c",&(scan_gender));
			}
	if (scan_gender=='F' || scan_gender=='M')
	{
		user->gender=scan_gender;
	}
	
	
}
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#define id_type 1
#define time_slot_type 2
typedef struct node
{
	char gender;
	char age;
	unsigned short int id;
	unsigned short int time_slot;
	struct node *next;	
	char name[20];
}patient;

patient* creat_element ();
patient* add_element();
patient* search_element(char type, unsigned short int value);
patient* get_start ();
void display_element (patient* element);
void gender_input(patient* user);
#endif

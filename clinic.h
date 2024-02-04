#ifndef _CLINIC_H_
#define _CLINIC_H_
typedef enum
{
	slot2=1,
	slot2_30,
	slot3,
	slot4,
	slot4_30
}time_slot;
void add_patient (void);
void edit_patient_info (void);
void reserve_slot_for_patient (void);
void cancel_reserve_for_patient(void);
void view_patient_info (void);
void view_reservations (void);
#endif
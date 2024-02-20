# Clinic Management System

This is a C program for a Clinic Management System designed to efficiently manage patient records, appointments, and reservations. The system offers both admin and user modes to cater to different users' needs. Below, we explain the key features of the program and its usage instructions.


# Features

# Admin Mode
Password Protection: In admin mode, the system asks for a password. The default password is '1234'. Users have three attempts to enter the correct password; otherwise, the system will close.

Add New Patient Record: Admins can add new patient records by providing basic information such as name, age, gender, and a unique ID. If the entered ID already exists, the system will reject the entry.

Edit Patient Record: Admins can edit patient information by entering the patient's ID. If the ID exists, the system allows the user to update the patient's information; otherwise, an incorrect ID message is displayed.

Reserve a Slot with the Doctor: There are five available slots: 2pm to 2:30pm, 2:30pm to 3pm, 3pm to 3:30pm, 4pm to 4:30pm, and 4:30pm to 5pm. Admins can reserve a slot by entering the patient's ID and selecting a desired slot. The reserved slot will not be available for the next patient's reservation.

Cancel Reservation: Admins can cancel a reservation by entering the patient's ID. The canceled reservation will become available for future bookings.

# User Mode
View Patient Record: In user mode, there is no password requirement. Users can view patient records by entering the patient's ID. The system displays basic patient information.

View Today’s Reservations: Users can view today's reservations, including the patient ID attached to each reservation slot.

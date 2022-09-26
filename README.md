# Fitness-Center-Management-System

## Introduction

In this program, I implement a Fitness Center Management System using the data structure Linked List which is accessible by administrative staff and members. It manages the different fitness classes and their sessions at the fitness center. An admin can mainly add/delete/edit/view fitness classes and sessions, and view the list of training sessions a member has booked so far, among other operations. On the other hand, a member can mainly view the list of available sessions per fitness class, book a spot in a training session that is not full, cancel a booking, and view their list of bookings.

This program is created by utilizing object-oriented programming (OOP) principles and data structures (Classes, inheritance, templates, error handling, and linked lists).

## Implementation

### Initialization:

1. At the beginning, the latest system files are to be loaded:
a. Admins.txt
b. Members.txt
c. FitnessClasses.txt
d. Sessions.txt

2. The following classes with their main attributes are defined:
a. Admin Class – Admin ID, First name, Last name, Username, Password.
b. Member Class – Member ID, First name, Last name, Username, Password, List of bookings.
c. FitnessClass Class – Class ID, Class name, List of sessions.
d. Session Class – Session ID, Class ID, Maximum capacity, Session date, Session time, Room number, List of registered members.

3. The list of bookings from the Member Class, the list of sessions from the
FitnessClass Class, and the list of registered members from the Session Class are implemented as linked lists (manually made, not STLs).


### Main Operations:

1. The program prints out a welcome message and ask the user to identify themselves either as an administrative staff or as a member. Then, the system
will ask the user, if a member, to either register or log in, while an admin will have only the option to log in:
a. If the user chooses to log in, the system asks for their credentials (username and password). If the credentials are valid, the corresponding (terminal) interface will appear with the list of possible actions they can choose from.
b. If the user (i.e. a member) is not yet registered, they should choose to register.

2. registerMember(..): A member is able to register in the system by providing the first name and the last name. An admin is able to register a new member too. The member ID, username and password of the new member is generated as follows:
a. Member ID: a randomly generated unique number of 4 digits.
b. Username: lowercase first name concatenated with the member ID.
c. Password: lowercase last name concatenated with a randomly generated number of 4 digits.

3. login(..): Any user is able to login by entering a valid set of username and password, with respect to their category.

4. addFitnessClass(..): An admin is able to add a new fitness class, in which its list of sessions is initially empty, by providing the following details:
Class ID, Class name.

5. deleteFitnessClass(..): An admin is able to delete a fitness class by providing its ID. This results in deleting all its sessions as well.

6. updateFitnessClassName(..): An admin is able to update a session’s name by providing the fitness class ID and the updated value.

7. addSession(..): An admin is able to add a new session to the list of sessions that belongs to a certain fitness class, in which the default maximum capacity is 20, by providing first the fitness class ID to get the list, then providing the following details to create the session object:
Session ID, Class ID, maximum capacity, Session date, Session time, Room number.

8. updateSessionDetails(..): An admin is able to update a session’s capacity/room/date/time by providing the session ID and the updated value. The user is able to choose what attribute to update. A single attribute is to be updated with every call of this method.

9. deleteSession(..): An admin is able to delete a session by providing its ID.

10. viewSessionDetails(..): An admin is able to view a session’s details, without the list of members, by providing the session ID.

11. viewListOfMembers(..): An admin is able to view the list of members (ID, First name + Last name) in a session by providing the session ID.

12. viewListOfBookings(..): An admin is able to view the list of bookings a member has booked by providing the member ID. For each booking in the list, the class name and session date/time are displayed.

13. viewSessionsWithVacancies(..): An admin or a member is able to view the list of sessions for a certain fitness class that are not yet full. For each session in the list, all the session’s information is displayed, except for the class ID and the list of members.

14. bookASession(..): A member is able to book a spot in a session if the maximum capacity has not been reached yet, by providing the fitness class ID. As a result, the member will be added to the list of members in that session, and the session will be added to the member’s list of bookings.

15. cancelBooking(..): A member is able to cancel a booking by providing the session ID. As a result, the session’s list of members and the member’s list of bookings is updated accordingly.

16. viewListOfMembersWithCommonClasses(..): An admin is able to view the list of members (ID, First name + Last name) having two or more common classes.

17. quitProgram(..): An admin or a member is able to choose to quit the program.
a. The system files are updated and saved accordingly.
b. The list of sessions saved in the “FitnessClasses.txt” file contain the list of session IDs, e.g. [2,3,4].
c. The list of members saved in the “Sessions.txt” file contain the list of member IDs, e.g. [5879,4380,9090].
d. The list of bookings saved in the “Members.txt” file contain the list of session IDs, e.g. [2,3,5].

18. The system asks for the relevant information (i.e. arguments) needed to be provided by the user for each of the aforementioned operations.

19. The system handles errors, missing and invalid input.

20. Finally, the system prints out a message indicating that an operation was completed successfully.

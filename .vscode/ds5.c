/*
practical:-5
Title:-Implement a Hospital Patient Registration System using Queue

*/

#include <stdio.h>

#define MAX 4

struct Patient
{
    int patientID;
    char arrivalTime[20];
};

struct Patient queue[MAX];
int front = -1;
int rear = -1;

void addPatient()
{
    struct Patient p;
    if (rear == MAX - 1)
    {
        printf("\nQueue Overflow\n");
        return;
    }
    printf("\nEnter Patient ID: ");
    scanf("%d", &p.patientID);
    printf("Enter Arrival Time: ");
    scanf("%s", p.arrivalTime);

    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = p;
    printf("Patient added successfully.\n");
}
void attendPatient()
{
    if (front == -1)
    {
        printf("\nQueue Underflow\n");
        return;
    }
    printf("\nAttending Patient:\n");
    printf("Patient ID: %d\n", queue[front].patientID);
    printf("Arrival Time: %s\n", queue[front].arrivalTime);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    printf("Patient attended successfully\n");
}
void viewPatients()
{
    int i;
    if (front == -1)
    {
        printf("\nNo patients are waiting\n");
        return;
    }
    printf("\nPatients currently waiting:\n");
    printf("--------------------------------\n");
    printf("Patient ID\tArrival Time\n");
    printf("--------------------------------\n");
    for (i = front; i <= rear; i++)
    {
        printf("%d\t\t%s\n",
               queue[i].patientID,
               queue[i].arrivalTime);
    }
    printf("--------------------------------\n");
}
void isQueueEmpty()
{
    if (front == -1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nQueue is not empty");
    }
}

int main()
{
    int choice;
    do
    {
        printf("\n----HOSPITAL PATIENT REGISTRATION SYSTEM ----\n");
        printf("1.Add Patient\n");
        printf("2.attend Patient\n");
        printf("3.display Patients\n");
        printf("4.check Queue Empty\n");
        printf("5.Exit\n");
        printf("-----------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addPatient();
            break;

        case 2:
            attendPatient();
            break;

        case 3:
            viewPatients();
            break;

        case 4:
            isQueueEmpty();
            break;

        case 5:
            printf("\nExit");
            break;

        default:
            printf("\nInvalid choice");
        }
    } while (choice != 5);
    return 0;
}
/* OUTPUT:-

-- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 1

Enter Patient ID: 100
Enter Arrival Time: 12:00
Patient added successfully.

--- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 1

Enter Patient ID: 101
Enter Arrival Time: 12:30
Patient added successfully.

--- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 1

Enter Patient ID: 102
Enter Arrival Time: 1:00
Patient added successfully.

--- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 103
Invalid choice.

--- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 1:30

Enter Patient ID: Enter Arrival Time: Patient added successfully.

--- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 1

Enter Patient ID: 104
Enter Arrival Time: 2:00
Patient added successfully.

--- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 2
Attending Patient ID: 100
Arrival Time: 12:00

--- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 2
Attending Patient ID: 101
Arrival Time: 12:30

--- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 3
Patients currently waiting:
Patient ID: 102, Arrival Time: 1:00
Patient ID: 102, Arrival Time: :30
Patient ID: 104, Arrival Time: 2:00

--- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 4
Queue is not Empty.

--- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 5
Exiting program...
*/
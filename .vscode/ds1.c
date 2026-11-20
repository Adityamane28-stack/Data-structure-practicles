/*
Practicle:1
Title : Implement Array Operations and Searching

*/
#include <stdio.h>
int main()
{
    int arr[100], n = 0;
    int i, j, choice, pos, key;
    int low, high, mid, found;
    do
    {
        printf("\n------- MENU -------\n");
        printf("1.Insert Marks\n");
        printf("2.Delete Mark from Given Position\n");
        printf("3.Display All Marks\n");
        printf("4.Linear Search\n");
        printf("5.Sorted Array and Binary Search\n");
        printf("6.Exit\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // Insert Marks
            printf("Enter number of students : ");
            scanf("%d", &n);
            printf("Enter %d marks:\n", n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            break;

        case 2: // Delete Mark from Given Position
            if (n == 0)
            {
                printf("Array is empty.\n");
                break;
            }
            printf("Enter position to delete : ");
            scanf("%d", &pos);
            if (pos < 1 || pos > n)
                printf("Invalid position.\n");
            else
            {
                for (i = pos - 1; i < n - 1; i++)
                    arr[i] = arr[i + 1];
                n--;
                printf("Mark deleted successfully.\n");
            }
            break;

        case 3: // Display All Marks
            if (n == 0)
                printf("No marks available.\n");
            else
            {
                printf("Marks are:\n");
                for (i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
            }
            break;

        case 4: // Linear Search
            if (n == 0)
            {
                printf("Array is empty.\n");
                break;
            }
            printf("Enter mark to search : ");
            scanf("%d", &key);
            found = 0;
            for (i = 0; i < n; i++)
            {
                if (arr[i] == key)
                {
                    printf("Mark found at position %d.\n", i + 1);
                    found = 1;
                    break;
                }
            }
            break;

        case 5: // Sorted Array and Binary Search
            if (n == 0)
            {
                printf("Array is empty.\n");
                break;
            }
            for (i = 0; i < n - 1; i++)
                for (j = 0; j < n - i - 1; j++)
                    if (arr[j] > arr[j + 1])
                    {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
            printf("Sorted Marks:\n");
            for (i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\nEnter mark to search : ");
            scanf("%d", &key);
            low = 0;
            high = n - 1;
            found = 0;
            while (low <= high)
            {
                mid = (low + high) / 2;
                if (arr[mid] == key)
                {
                    printf("Mark found at position %d in sorted array.\n", mid + 1);
                    found = 1;
                    break;
                }
                else if (key < arr[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            break;

        case 6: // Exit
            printf("Exit\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 6);
    return 0;
}

/*
cc marks.c
student@TCOERCL-VI-11:~$ ./a.out

------- MENU -------
1.Insert Marks
2.Delete Mark from Given Position
3.Display All Marks
4.Linear Search
5.Sorted Array and Binary Search
6.Exit
 Enter your choice : 1
Enter number of students : 5
Enter 5 marks:
98
79
86
81
65

------- MENU -------
1.Insert Marks
2.Delete Mark from Given Position
3.Display All Marks
4.Linear Search
5.Sorted Array and Binary Search
6.Exit
 Enter your choice : 3
Marks are:
98 79 86 81 65

------ MENU -------
1.Insert Marks
2.Delete Mark from Given Position
3.Display All Marks
4.Linear Search
5.Sorted Array and Binary Search
6.Exit
 Enter your choice : 2
Enter position to delete : 4
Mark deleted successfully.

------- MENU -------
1.Insert Marks
2.Delete Mark from Given Position
3.Display All Marks
4.Linear Search
5.Sorted Array and Binary Search
6.Exit
 Enter your choice : 3
Marks are:
98 79 86 65

------- MENU -------
1.Insert Marks
2.Delete Mark from Given Position
3.Display All Marks
4.Linear Search
5.Sorted Array and Binary Search
6.Exit
------- MENU -------
1.Insert Marks
2.Delete Mark from Given Position
3.Display All Marks
4.Linear Search
5.Sorted Array and Binary Search
6.Exit
 Enter your choice : 4
Enter mark to search : 79
Mark found at position 2.
------- MENU -------
1.Insert Marks
2.Delete Mark from Given Position
3.Display All Marks
4.Linear Search
5.Sorted Array and Binary Search
6.Exit
 Enter your choice : 5
Sorted Marks:
65 79 86 98
Enter mark to search : 86
Mark found at position 3 in sorted array.
------- MENU -------
1.Insert Marks
2.Delete Mark from Given Position
3.Display All Marks
4.Linear Search
5.Sorted Array and Binary Search
6.Exit
 Enter your choice : 6
Exit
*/
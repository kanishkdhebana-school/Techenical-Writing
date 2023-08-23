#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SEATS 50

typedef struct 
{
    bool reserved ;
    char passenger_name[50] ;
} Seat ;

Seat train_seats[MAX_SEATS] ;

void initializeSeats () 
{
    for (int i = 0; i < MAX_SEATS; i++) 
    {
        train_seats[i].reserved = false ;
        train_seats[i].passenger_name[0] = '\0' ;
    }
}

void displaySeats () 
{
    printf("Seat No\tReserved\tPassenger Name\n") ;
    for (int i = 0; i < MAX_SEATS; i++) 
        printf("%d\t%s\t\t%s\n", i + 1, train_seats[i].reserved ? "Yes" : "No", train_seats[i].passenger_name) ;
}

void reserveSeat (int seat_number, const char *passenger_name) 
{
    if (seat_number < 1 || seat_number > MAX_SEATS) 
    {
        printf("Invalid seat number.\n") ;
        return ;
    }

    if (train_seats[seat_number - 1].reserved) 
    {
        printf("Seat already reserved.\n") ;
        return ;
    }

    train_seats[seat_number - 1].reserved = true ;
    strcpy(train_seats[seat_number - 1].passenger_name, passenger_name) ;
    printf ("Seat reserved successfully.\n") ;
}

int main() 
{
    initializeSeats() ;
    int choice ;
    
    do 
    {
        printf("\nRailway Reservation System\n") ;
        printf("1. Display Available Seats\n") ;
        printf("2. Reserve a Seat\n") ;
        printf("3. Exit\n") ;
        printf("Enter your choice: ") ;
        scanf("%d", &choice) ;

        switch (choice) 
        {
            case 1:
                displaySeats() ;
                break ;
                
            case 2: 
                int seat_number ;
                char passenger_name[50] ;
                printf ("Enter seat number: ") ;
                scanf ("%d", &seat_number) ;
                printf ("Enter passenger name: ") ;
                scanf ("%s", passenger_name) ;
                reserveSeat (seat_number, passenger_name) ;
                break ;
            
            case 3:
                printf ("Exiting the program.\n") ;
                break ;
                
            default:
                printf ("Invalid choice. Please try again.\n") ;
        }
    } while (choice != 3) ;

    return 0 ;
}


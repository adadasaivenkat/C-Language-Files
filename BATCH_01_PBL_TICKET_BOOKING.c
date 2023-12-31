#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>
struct ticket_booking
{
    char name[50];
    int bus_num;
    int num_of_tickets;
};
void clear_screen()
{
    printf("\033[H\033[J");     //ANSI escape code to clear the screen //ANSI stands for the American National Standards Institute
}
void available_buses()
{
    clear_screen();
    printf("| Bus no | Bus name |         Destination               |  Fare   | Time |\n");
    printf("--------------------------------------------------------------------------\n");
    printf("| 533101 | Bus A    | Kakinada to Visakhapatnam         | Rs.500  | 9am  |\n");
    printf("| 533102 | Bus B    | Kakinada to Vizianagaram          | Rs.500  | 11am |\n");
    printf("| 533103 | Bus C    | Rajahmundry to Vizianagaram       | Rs.450  | 3pm  |\n");
    printf("| 533104 | Bus D    | Visakhapatnam to Rajahmundry      | Rs.450  | 8pm  |\n");
    printf("| 533105 | Bus E    | Vizianagaram to Kakinada          | Rs.500  | 10pm |\n");
}
void print_bus(int bus_num)
{
    switch(bus_num)
    {
        case 533101:
                    printf("Bus                : Bus A\n");
                    printf("Destination        : Kakinada to Visakhapatnam\n");
                    printf("Departure          : 9am\n");
                    break;
        case 533102:
                    printf("Bus                : Bus B\n");
                    printf("Destination        : Kakinada to Vizianagaram\n");
                    printf("Departure          : 11am\n");
                    break;
        case 533103:
                    printf("Bus                : Bus C\n");
                    printf("Destination        : Rajahmundry to Vizianagaram\n");
                    printf("Departure          : 3pm\n");
                    break;
        case 533104:
                    printf("Bus                : Bus D\n");
                    printf("Destination        : Visakhapatnam to Rajahmundry\n");
                    printf("Departure          : 8pm\n");
                    break;
        case 533105:
                    printf("Bus                : Bus E\n");
                    printf("Destination        : Vizianagaram to Kakinada\n");
                    printf("Departure          : 10pm\n");
                    break;
        default:
                    printf("Invalid bus number!!\n");
                    break;
    }
}
float fare(int bus_num, int num_of_tickets)
{
    return (bus_num == 533103 || bus_num == 533104) ? (float)(num_of_tickets * 450) : (float)(num_of_tickets * 500);
}
void print_ticket(struct ticket_booking *details, float charge)
{
    clear_screen();
    printf("=============================================\n");
    printf("                   DETAILS\n");
    printf("=============================================\n");
    printf("Name               : %s\n", details->name);
    printf("Number of tickets  : %d\n", details->num_of_tickets);
    printf("Bus number         : %d\n", details->bus_num);
    print_bus(details->bus_num);
    printf("Fare               : Rs/- %.2f\n", charge);
}
void book()
{
    char confirm;
    struct ticket_booking *details=(struct ticket_booking *)malloc(sizeof(struct ticket_booking));
    printf("Enter your name : ");
    scanf(" %[^\n]s",details->name);
    printf("Enter number of tickets : ");
    scanf("%d",&details->num_of_tickets);
    printf("Press enter to view all available buses.\n");
    getchar();      //Consume newline
    getchar();      //Wait for key press
    clear_screen();
    available_buses();
    printf("Enter bus number : ");
    scanf("%d",&details->bus_num);
    if(details->bus_num >= 533101 && details->bus_num <= 533105)
    {
        float charge=fare(details->bus_num,details->num_of_tickets);
        print_ticket(details,charge);
        printf("Are you sure you want to confirm? (y/n) : ");
        scanf(" %c",&confirm);
        if(confirm=='y' || confirm=='Y')
        {
            printf("Booking successful! Wishing you a happy journey.\n");
            free(details);
            exit(0);
        }
        else
        {
            printf("Booking not successful! Please try again.\n");
            free(details);
            exit(0);
        }
    }
    else
    {
        printf("Invalid bus number! Booking failed.\n");
        free(details);
        exit(0);
    }
}
int main()
{
    int choice;
    do
    {
        clear_screen();
        printf("=============================================\n");
        printf("      WELCOME TO TICKET BOOKING SYSTEM\n");
        printf("=============================================\n");
        printf("1. Book a ticket\n");
        printf("2. Available buses\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3) : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    book();
                    break;
            case 2:
                    available_buses();
                    printf("Press any key to go back to main menu.\n");
                    getchar(); // Consume newline
                    getchar(); // Wait for key press
                    break;
            case 3:
                    exit(0);
            default:
                    printf("Invalid choice! Please enter a valid choice.\n");
                    exit(0);
        }
    }while(1);
    return 0;
}

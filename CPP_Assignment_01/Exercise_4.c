/* A marketing company wants to keep record of its employees. Each record would have the following characteristics:
•	First name
•	Last name
•	Age (0...100)
•	Gender (male or female)
•	Personal ID number (e.g. 012345678)
•	Unique employee number (00000000 -> 99999999)
*/

#include <stdio.h>

int main(){
    
    // Declare variables to store employee information
    char firstName[50];  // Assuming maximum length of 50 characters for the first name
    char lastName[50];   // Assuming maximum length of 50 characters for the last name
    int age;             // Age between 0 and 100
    char gender[10];     // "male" or "female"
    char personalID[10]; // Personal ID number, assuming a maximum of 9 digits + null terminator
    int employeeNumber;  // Unique employee number (8 digits)

    printf("Enter first name:");
    scanf("%s", firstName);
    printf("Enter last name: ");
    scanf("%s", lastName);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter gender (male/female): ");
    scanf("%s", gender);
    printf("Enter personal ID (9 digits): ");
    scanf("%s", personalID);
    printf("Enter unique employee number (8 digits): ");
    scanf("%d", &employeeNumber);

    // Output employee data
    printf("\nFirst name: %s\n", firstName);
    printf("Last name: %s\n", lastName);
    printf("Age: %d\n", age);
    printf("Gender: %s\n", gender);
    printf("Personal ID: %s\n", personalID);
    printf("Unique Employee number: %08d\n", employeeNumber); // Print employee number with leading zeros

    return 0;
}
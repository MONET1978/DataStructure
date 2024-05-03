#include <stdio.h>

// Define a structure to represent a row in the table
typedef struct {
    int serialNumber;
    char name[50];
    char gender[10];
    int age;
    char city[50];
} Person;

// Function to print the table header
void printHeader() {
    printf("+-------------+--------------------------------+----------+-----+--------------------------------+\n");
    printf("| Serial No.  | Name                           | Gender   | Age | City                           |\n");
    printf("+-------------+--------------------------------+----------+-----+--------------------------------+\n");
}

// Function to print the data in table format
void printPerson(Person person) {
    printf("| %-11d | %-30s | %-8s | %-3d | %-30s |\n",
        person.serialNumber, person.name, person.gender, person.age, person.city);
    printf("+-------------+--------------------------------+----------+-----+--------------------------------+\n");
}

int main() {
    // Initialize an array of `Person`
    Person people[] = {
        {1, "Zhang Wei", "Male", 29, "Beijing"},
        {2, "Li Hua", "Female", 24, "Shanghai"},
        {3, "Wang Feng", "Male", 35, "Guangzhou"}
    };

    int numPeople = sizeof(people) / sizeof(people[0]);

    // Print the table
    printHeader();//输出表头
    for (int i = 0; i < numPeople; i++) {
        printPerson(people[i]);
    }

    return 0;
}
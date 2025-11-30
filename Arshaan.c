#include <stdio.h>
#include <string.h>
#include "incident.h"

// Reports
void reportOpen() {
    printf("\n--- OPEN INCIDENTS ---\n");
    for (int i = 0; i < count; i++)
        if (strcmp(list[i].status, "open") == 0)
            printf("ID %d - %s\n", list[i].id, list[i].type);
}

void reportClosed() {
    printf("\n--- CLOSED INCIDENTS ---\n");
    for (int i = 0; i < count; i++)
        if (strcmp(list[i].status, "closed") == 0)
            printf("ID %d - %s\n", list[i].id, list[i].type);
}

void reportEscalated() {
    printf("\n--- ESCALATED INCIDENTS ---\n");
    for (int i = 0; i < count; i++)
        if (strcmp(list[i].status, "escalated") == 0)
            printf("ID %d - %s\n", list[i].id, list[i].type);
}

// Main Program
int main() {
    int choice;

    while (1) {
        printf("\n==== Cyber Incident Response Tracker ====\n");
        printf("1. Add Incident\n");
        printf("2. List All Incidents\n");
        printf("3. Update Ages\n");
        printf("4. Auto Escalate\n");
        printf("5. Report Open\n");
        printf("6. Report Closed\n");
        printf("7. Report Escalated\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addIncident(); break;
            case 2: listIncidents(); break;
            case 3: updateAges(); break;
            case 4: autoEscalate(); break;
            case 5: reportOpen(); break;
            case 6: reportClosed(); break;
            case 7: reportEscalated(); break;
            case 8: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

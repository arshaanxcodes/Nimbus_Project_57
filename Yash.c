#include <stdio.h>
#include <string.h>
#include "incident.h"

struct Incident list[MAX_INCIDENTS];
int count = 0;

// Add new incident
void addIncident() {
    if (count >= MAX_INCIDENTS) {
        printf("Storage full!\n");
        return;
    }

    struct Incident inc;

    printf("Enter ID: ");
    scanf("%d", &inc.id);

    printf("Enter Type: ");
    scanf("%s", inc.type);

    printf("Enter Severity (1-5): ");
    scanf("%d", &inc.severity);

    printf("Enter Assigned To: ");
    scanf("%s", inc.assigned_to);

    printf("Enter Status (open/closed/in-progress): ");
    scanf("%s", inc.status);

    printf("Enter Age (hours): ");
    scanf("%d", &inc.age_hours);

    list[count] = inc;
    count++;

    printf("Incident added successfully!\n");
}

// List all incidents
void listIncidents() {
    if (count == 0) {
        printf("No incidents recorded.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\n=== Incident %d ===\n", i + 1);
        printf("ID: %d\n", list[i].id);
        printf("Type: %s\n", list[i].type);
        printf("Severity: %d\n", list[i].severity);
        printf("Assigned To: %s\n", list[i].assigned_to);
        printf("Status: %s\n", list[i].status);
        printf("Age (hours): %d\n", list[i].age_hours);
    }
}

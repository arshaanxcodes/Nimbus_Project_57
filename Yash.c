#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INCIDENTS 100
#define MAX_TYPE_LEN 50
#define MAX_ASSIGNED_LEN 50
#define MAX_STATUS_LEN 20

// ==========================
// MEMBER 1: Struct + Add + List
// Improved: safe input and a main menu
// ==========================

// Incident Structure
struct Incident {
    int id;
    char type[MAX_TYPE_LEN];
    int severity;
    char assigned_to[MAX_ASSIGNED_LEN];
    char status[MAX_STATUS_LEN];
    int age_hours;
};

// Global array
static struct Incident list[MAX_INCIDENTS];
static int count = 0;

// Read a line from stdin and strip newline
static void read_line(char *buf, int size) {
    if (!fgets(buf, size, stdin)) {
        buf[0] = '\0';
        return;
    }
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') buf[len - 1] = '\0';
}

// Read an integer robustly
static int read_int(const char *prompt) {
    char buf[64];
    int val = 0;
    while (1) {
        printf("%s", prompt);
        read_line(buf, sizeof(buf));
        if (sscanf(buf, "%d", &val) == 1) return val;
        printf("Invalid number, please try again.\n");
    }
}

// Read menu choice strictly: reject inputs like "1abc"
static int read_choice(const char *prompt) {
    char buf[64];
    char *endptr;
    long val;

    printf("%s", prompt);
    read_line(buf, sizeof(buf));
    if (buf[0] == '\0') return -1;
    val = strtol(buf, &endptr, 10);
    if (endptr == buf) return -1; // no digits
    // skip trailing whitespace
    while (*endptr == ' ' || *endptr == '\t') endptr++;
    if (*endptr != '\0') return -1; // extra junk after number
    return (int)val;
}

// Add new incident
void addIncident() {
    if (count >= MAX_INCIDENTS) {
        printf("Storage full!\n");
        return;
    }

    struct Incident inc;

    inc.id = read_int("Enter ID: ");

    printf("Enter Type: ");
    read_line(inc.type, sizeof(inc.type));

    inc.severity = read_int("Enter Severity (1-5): ");

    printf("Enter Assigned To: ");
    read_line(inc.assigned_to, sizeof(inc.assigned_to));

    // Read and validate status. Accept: open, closed, in-progress or in-process (case-insensitive)
    printf("Enter Status (open/closed/in-progress): ");
    read_line(inc.status, sizeof(inc.status));
    if (inc.status[0] == '\0') {
        printf("No status entered. Add cancelled.\n");
        return;
    }
    char status_lc[MAX_STATUS_LEN];
    for (size_t ii = 0; ii < sizeof(status_lc) && inc.status[ii] != '\0'; ++ii) {
        status_lc[ii] = (char)tolower((unsigned char)inc.status[ii]);
        status_lc[ii+1] = '\0';
    }
    if (!(strcmp(status_lc, "open") == 0 || strcmp(status_lc, "closed") == 0 || strcmp(status_lc, "in-progress") == 0 || strcmp(status_lc, "in-process") == 0)) {
        printf("Invalid status. Allowed values: open, closed, in-progress (or in-process). Add cancelled.\n");
        return;
    }

    inc.age_hours = read_int("Enter Age (hours): ");

    list[count++] = inc;

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

int main(void) {
    char choice_buf[16];
    int choice = 0;

    while (1) {
        printf("\nIncident Manager\n");
        printf("1) Add incident\n");
        printf("2) List incidents\n");
        printf("3) Exit\n");
        choice = read_choice("Choose an option: ");
        if (choice == -1) {
            printf("Invalid choice.\n");
            continue;
        }

        if (choice == 1) {
            addIncident();
        } else if (choice == 2) {
            listIncidents();
        } else if (choice == 3) {
            printf("Exiting.\n");
            break;
        } else {
            printf("Unknown option.\n");
        }
    }

    return 0;
}

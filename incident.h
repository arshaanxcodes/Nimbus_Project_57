#ifndef INCIDENT_H
#define INCIDENT_H

#define MAX_INCIDENTS 100

struct Incident
{
int id;
char type[50];
int severity;
char assigned_to[50];
char status[20];
int age_hours;
};
// Global array and count
extern struct Incident list[MAX_INCIDENTS];
extern int count;

// MEMBER 1 FUNCTIONS
void addIncident();
void listIncidents();

// MEMBER 2 FUNCTIONS
void updateAges();
void autoEscalate();

// MEMBER 3 FUNCTIONS
void reportOpen();
void reportClosed();
void reportEscalated();

#endif


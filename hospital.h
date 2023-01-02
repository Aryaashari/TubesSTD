#ifndef HOSPITAL_H_INCLUDED
#define HOSPITAL_H_INCLUDED

#include <iostream>
#include <iomanip>
using namespace std;


struct Room {
    int capacity, emptyBed;
    string id, roomType;
};

struct Patient {
    string id, name, disease;
    char gender;
    int age;
};


typedef Room infoRoom;
typedef Patient infoPatient;
typedef struct ElmRoom *adrRoom;
typedef struct ElmPatient *adrPatient;

struct ElmRoom {
    infoRoom info;
    adrPatient patient;
    adrRoom prev;
    adrRoom next;
};

struct ElmPatient {
    infoPatient info;
    adrPatient next;
};

struct Hospital {
    adrRoom first, last;
};


void createHospital(Hospital &H);
adrRoom newElmRoom(infoRoom info);
adrPatient newElmPatient(infoPatient info);
adrRoom searchRoom(Hospital H, string roomId);
adrPatient searchPatient(Hospital H, string patientId);
adrRoom searchRoomByPatientId(Hospital H, string patientId);
void insertRoom(Hospital &H, adrRoom r);
void insertPatient(Hospital &H, adrPatient p, string roomId);
adrPatient deletePatient(Hospital &H, string patientId);
void showAll(Hospital &H);
void showDetailPatient(Hospital H, string patientId);
void showDetailRoom(Hospital H, string roomId);


#endif // HOSPITAL_H_INCLUDED

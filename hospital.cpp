#include "hospital.h"

void createHospital(Hospital &H) {
    H.first = NULL;
    H.last = NULL;
}


adrRoom newElmRoom(infoRoom info) {
    adrRoom r = new ElmRoom;
    r->info = info;
    r->patient = NULL;
    r->next = NULL;
    r->prev = NULL;
    return r;
}

adrPatient newElmPatient(infoPatient info) {
    adrPatient p = new ElmPatient;
    p->info = info;
    p->next = NULL;
    return p;
}

adrRoom searchRoomByType(Hospital H, string type) {
    adrRoom r = H.first;
    while (r != NULL) {
        if (r->info.roomType == type && r->info.emptyBed != 0) {
            return r;
        }
        r = r->next;
    }

    return NULL;
}

adrPatient searchPatient(Hospital H, string id) {
    adrRoom r = H.first;
    while (r != NULL) {
        adrPatient p = r->patient;
        while (p != NULL) {
            if (p->info.id == id) {
                return p;
            }
            p = p->next;
        }
        r = r->next;
    }

    return NULL;
}

adrRoom searchRoomByPatientId(Hospital H, string id) {
    adrRoom r = H.first;
    while (r != NULL) {
        adrPatient p = r->patient;
        while (p != NULL) {
            if (p->info.id == id) {
                return r;
            }
            p = p->next;
        }
        r = r->next;
    }

    return NULL;
}

void insertRoom(Hospital &H, adrRoom r) {
    if (H.first == NULL) {
        H.first = r;
        H.last = r;
    } else {
        r->prev = H.last;
        H.last->next = r;
        H.last = r;
    }
}

void insertPatient(Hospital &H, adrPatient p, string type) {
    adrRoom r = searchRoomByType(H,type);

    if (r != NULL) {

        adrPatient q = r->patient;
        if (q == NULL) {
            r->patient = p;
        } else {
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        }

        r->info.emptyBed--;
    } else {
        cout << "Kamar dengan tipe " << type << " tidak tersedia" << endl;
    }
}

adrPatient deletePatient(Hospital &H, string id) {
    adrPatient p = searchPatient(H, id);
    adrRoom r = searchRoomByPatientId(H,id);

    if (p == NULL) {
        cout << "Pasien dengan id '" << id << "' tidak ditemukan!" << endl;
        return NULL;
    } else {
        adrPatient q = r->patient;
        if (q != p) {
            while (q->next != p){
                q = q->next;
            }
            q->next = p->next;
        } else {
            r->patient = p->next;
        }

        p->next = NULL;
    }

    return p;

}

void showAll(Hospital &H){
    int i = 1;
    adrRoom r = H.first;

    while (r != NULL){
        cout<< "========== Room "<<r->info.id<<" "<<r->info.roomType<<" =========="<<endl;
        adrPatient p = r->patient;
        while (p != NULL){
            cout<<setw(5)<<i<<setw(10)<<p->info.id<<setw(15)<<p->info.name<<setw(5)<<p->info.age
            <<setw(5)<<p->info.gender<<setw(15)<<p->info.disease<<endl;
            p = p->next;
            i++;
        }
        r = r->next;
    }
}
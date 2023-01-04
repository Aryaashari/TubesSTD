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

adrRoom searchRoom(Hospital H, string roomId) {
    adrRoom r = H.first;
    while (r != NULL) {
        if (r->info.id == roomId) {
            return r;
        }
        r = r->next;
    }
    return NULL;
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
        cout << "Pasien dengan id '" << id << "' tidak ditemukan" << endl;
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
        r->info.emptyBed++;
        p->next = NULL;
    }

    return p;

}

void showAll(Hospital &H){
    int i = 1;
    adrRoom r = H.first;

    if (r == NULL) {
        cout << "Belum ada kamar yang tersedia" << endl;
        cout << endl;
    } else {
        while (r != NULL){
            adrPatient p = r->patient;
            cout<< "==================== Room "<<r->info.id<<" "<<r->info.roomType<<" ===================="<<endl;
            cout<<setw(5)<<"No"<<setw(5)<<"ID"<<setw(15)<<"Name"<<setw(5)<<"Age"
            <<setw(7)<<"Gender"<<setw(17)<<"Disease"<<endl;
            while (p != NULL){
                cout<<setw(5)<<i<<setw(5)<<p->info.id<<setw(15)<<p->info.name<<setw(5)<<p->info.age
                <<setw(7)<<p->info.gender<<setw(17)<<p->info.disease<<endl;
                p = p->next;
                i++;
            }
            cout<<endl;
            i = 1;
            r = r->next;
        }
    }
}


void showDetailPatient(Hospital H, string patientId) {
    adrPatient p = searchPatient(H, patientId);
    if (p == NULL) {
        cout << "Patien dengan id '" << patientId << "' tidak ditemukan" << endl;
    } else {
        cout << "Name: " << p->info.name << endl;
        cout << "Age: " << p->info.age << endl;
        cout << "Gender: " << p->info.gender << endl;
        cout << "Disease: " << p->info.disease << endl;
        cout << endl;
    }
}

void showDetailRoom(Hospital H, string roomId) {
    adrRoom r = searchRoom(H, roomId);

    if (r == NULL) {
        cout << "Room dengan id '" << roomId << "' tidak ditemukan" << endl;
    } else {
        cout << "Capacity: " << r->info.capacity << endl;
        cout << "Empty Bed: " << r->info.emptyBed << endl;
        cout << "Room Type: " << r->info.roomType << endl;
        cout << endl;
    }
}

void insertPatientByRoom(Hospital &H, adrPatient p, adrRoom r) {

    adrPatient q = r->patient;
    if (r->info.emptyBed == 0) {
        cout << "Kamar yang dituju telah penuh" << endl;
    } else {
        if (q == NULL) {
            r->patient = p;
        } else {
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        }

        r->info.emptyBed--;
    }

}


void moveRoom(Hospital &H, string roomId, string patientId) {
    adrRoom r = searchRoom(H,roomId);
    adrPatient p = searchPatient(H, patientId);
    adrRoom rp = searchRoomByPatientId(H,patientId);
    if (r == NULL) {
        cout << "Kamar dengan ID '" << r->info.id << "' tidak ditemukan" << endl;
    } else if (p == NULL) {
        cout << "Pasien dengan ID '" << p->info.id << "' tidak ditemukan" << endl;
    } else if (roomId == rp->info.id) {
        cout << "ID kamar asal dan tujuan tidak boleh sama" << endl;
    } else {
        insertPatientByRoom(H,p,r);
        deletePatient(H,patientId);
        cout << "Berhasil memindahkan pasien" << endl;
    }
}

void deleteRoom(Hospital &H, string roomId) {
    adrRoom r = searchRoom(H,roomId);

    if (r == NULL) {
        cout << "Kamar dengan ID '" << r->info.id << "' tidak ditemukan" << endl;
    } else if (r->info.emptyBed != r->info.capacity) {
        cout << "Kamar dengan ID '" << r->info.id << "' masih memiliki pasien, silahkan pindahkan terlebih dahulu" << endl;
    } else {
        if (H.first == H.last) {
            H.first = NULL;
            H.last = NULL;
        } else if (H.first == r) {
            r->next->prev == NULL;
            H.first = r->next;
        } else if (H.last == r) {
            r->prev->next = r->next;
            H.last = r->prev;
        } else {
            r->prev->next = r->next;
            r->next->prev = r->prev;
        }
    }
}

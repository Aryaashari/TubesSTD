#include "hospital.h"

int main()
{
    Hospital H;
    infoPatient p;
    infoRoom r;
    adrRoom ar;
    adrPatient ap;
    string id,roomtype;
    int menu = 1;

    createHospital(H);

//    r.capacity = 2;
//    r.emptyBed = 2;
//    r.id = "A01";
//    r.roomType = "VIP";
//    ar = newElmRoom(r);
//    insertRoom(H, ar);
//
//    p.age = 21;
//    p.disease = "HIV";
//    p.gender = 'L';
//    p.id = "V01";
//    p.name = "Arya Wiguna";
//    ap = newElmPatient(p);
//    insertPatient(H, ap, "VIP");
//
//    -------------------------beda kelas------------
//
//    r.capacity = 3;
//    r.emptyBed = 3;
//    r.id = "A02";
//    r.roomType = "Reguler";
//    ar = newElmRoom(r);
//    insertRoom(H, ar);
//
//    p.age = 12;
//    p.disease = "Chlamydia";
//    p.gender = 'P';
//    p.id = "C69";
//    p.name = "Audy Nadia";
//    ap = newElmPatient(p);
//    insertPatient(H, ap, "Reguler");
//
//    p.age = 23;
//    p.disease = "Gonorrhea";
//    p.gender = 'L';
//    p.id = "G12";
//    p.name = "Sultan Lord";
//    insertPatient(H, newElmPatient(p), "Reguler");
//
//    p.age = 44;
//    p.disease = "Herpes";
//    p.gender = 'L';
//    p.id = "H45";
//    p.name = "King Ipul";
//    insertPatient(H, newElmPatient(p), "Reguler");
//
//    showAll(H);

    while (menu != 0){
        cout<<"\n==============Menu=============="<<endl;
        cout<<"1. Insert new patient"<<endl;
        cout<<"2. Create new room"<<endl;
        cout<<"3. Delete Patient from the list"<<endl;
        cout<<"4. Show patient list"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Choose menu: ";cin>>menu;
        cout<<endl;
        switch (menu){
        case 0:
            break;
        case 1:
            if (H.first == NULL) {
                cout << "Kamar belum tersedia" << endl;
            } else {
                cout<<"Insert new patient: "<<endl;
                cout<<"ID: ";cin>>p.id;
                cout<<"Name: ";cin>>p.name;
                cout<<"Gender: ";cin>>p.gender;
                cout<<"Age: ";cin>>p.age;
                cout<<"Disease: ";cin>>p.disease;
                cout<<"Room type: ";cin>>roomtype;
                insertPatient(H, newElmPatient(p), roomtype);
            }
            break;
        case 2:
            cout<<"Create new room: "<<endl;
            cout<<"ID: ";cin>>r.id;
            cout<<"Room Type: ";cin>>r.roomType;
            cout<<"Capacity: ";cin>>r.capacity;
            r.emptyBed = r.capacity;
            ar = newElmRoom(r);
            insertRoom(H, ar);
            cout<<"Room created"<<endl;
            break;
        case 3:
            cout<<"Delete patient from the list: "<<endl;
            cout<<"Patient ID: ";cin>>id;
            deletePatient(H, id);
            break;
        case 4:
            showAll(H);
            break;
        }
    }

    return 0;

//    cout<<"Delete patient from the list? (input 0 if no)"<<endl;
//    cout<<"Patient ID: ";cin>>id;
//    if (id == "0"){
//        cout<<"They're ALL alive?..cool"<<endl;
//    }
//    deletePatient(H, id);
//    cout<<"Patient deleted from the list"<<endl<<endl;
//    showAll(H);
}
#include "hospital.h"

int main()
{
    Hospital H;
    infoPatient p;
    infoRoom r;
    adrRoom ar;
    adrPatient ap;
    string id,roomtype, roomId;
    int menu = 1;

    createHospital(H);

    while (menu != 0){
        cout<<"\n==============Menu=============="<<endl;
        cout<<"1. Insert new patient"<<endl;
        cout<<"2. Create new room"<<endl;
        cout<<"3. Delete Patient from the list"<<endl;
        cout<<"4. Show patient list"<<endl;
        cout<<"5. Show detail patient"<<endl;
        cout<<"6. Show detail room"<<endl;
        cout<<"7. Move room"<<endl;
        cout<<"8. Delete room"<<endl;
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
        case 5:
            cout<<"Detail pasien: "<<endl;
            cout<<"Patient ID: ";cin>>id;
            showDetailPatient(H, id);
            break;
        case 6:
            cout<<"Detail room: "<<endl;
            cout<<"Room ID: ";cin>>roomId;
            showDetailRoom(H, roomId);
            break;
        case 7:
            cout << "Move room:" << endl;
            cout<<"Patient ID: ";cin>>id;
            cout<<"Room ID: ";cin>>roomId;
            moveRoom(H,roomId,id);
            break;
        case 8:
            if (H.first == NULL) {
                cout << "Kamar belum tersedia" << endl;
            } else {
                cout << "Delete room:" << endl;
                cout << "Room ID: ";cin>>roomId;
                deleteRoom(H,roomId);
            }
            break;
        default:
            cout << "Inputan tidak valid" << endl;
        }
    }

    return 0;
}

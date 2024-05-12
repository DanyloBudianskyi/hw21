#include "Resident.h"
#include "Flat.h"
#include "Building.h";

int main()
{
    Resident name1("Vasya");
    Flat flat1;
    Flat flat2 = flat1;
    Building build1;


    //flat1.showInfo();
    //flat1.addResident(name1);
    //flat1.addResident("Ivan");
    //flat1.setRooms(5);
    //flat1.showInfo();
    //flat2.showInfo();

    build1.addResident("Ivan", 5);
    build1.addResident("Katya", 5);
    build1.addResident("Igor", 9);
    build1.addResident("Vasya", 3);
    build1.showAllFlatsList();
    cout << "====================================================\n\n";

    build1.showAllPersonList();
    cout << "====================================================\n\n";
    build1.showPersonsListByFlat(5);
}
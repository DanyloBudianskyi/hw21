#include "Building.h"
#include "Resident.h"

Building::Building()
{
    address = new char[16] {"Unknown address"};
    numberOfFlats = 10;

    flats = new Flat*[numberOfFlats];
    for (int i = 0; i < numberOfFlats; i++) {
        flats[i] = new Flat();
    }
}

Building::Building(const char* address, int numberOfFlats)
{
    if (strlen(address) >= 3) {
        this->address = new char[strlen(address) + 1];
        strcpy_s(this->address, strlen(address) + 1, address);
    }
    this->numberOfFlats = numberOfFlats;

    flats = new Flat * [numberOfFlats];
    for (int i = 0; i < numberOfFlats; i++) {
        flats[i] = new Flat();
    }
}

Building::~Building()
{
    delete[] address;
    for (int i = 0; i < numberOfFlats; i++) {
        delete flats[i];
    }
    delete[] flats;
}

void Building::setAddress(const char* address)
{
    if (strlen(address) >= 3) {
        this->address = new char[strlen(address) + 1];
        strcpy_s(this->address, strlen(address) + 1, address);
    }
    else {
        cout << "Address to short\n\n";
    }
}

const char* Building::getAddress() const
{
    return address;
}

int Building::getNumberOfFlats() const
{
    return numberOfFlats;
}

void Building::addResident(const Resident& person, int nFlat)
{
    if (nFlat >= 0 && nFlat < numberOfFlats) {
        Flat* flat = flats[nFlat];
        flat->addResident(person);
    }
    else {
        cout << "Invalid flat index\n\n";
    }
}

void Building::delResident(const Resident& obj, int nFlat)
{
    if (nFlat >= 0 && nFlat < numberOfFlats) {
        Flat* flat = flats[nFlat];
        flat->delResident(obj);
    }
}

void Building::showAllFlatsList() const
{
    for (int i = 0; i < numberOfFlats; i++) {
        cout << "\nFlat #" << i << ":\n";
        flats[i]->showInfo();
    }
}

void Building::showAllPersonList() const
{
    for (int i = 0; i < numberOfFlats; i++) {
        cout << "\nFlat #" << i << endl;
        flats[i]->showInfoAboutRes();
    }
}

void Building::showPersonsListByFlat(int nFlat) const
{
    if (nFlat >= 0 && nFlat < numberOfFlats) {
        cout << "Residents in flat " << nFlat << ":\n";
        flats[nFlat]->showInfoAboutRes();
    }
}
#include "Flat.h"

Flat::Flat()
{
    _rooms = 1;
    _square = 25.5;
    amountOfResidents = 0;
    arrResidents = nullptr;
}

Flat::Flat(int rooms, float square)
{
    _rooms = rooms;
    _square = square;
    amountOfResidents = 0;
    arrResidents = nullptr;
}

Flat::Flat(const Flat& obj)
{
    this->_rooms = obj._rooms;
    this->_square = obj._square;
    this->amountOfResidents = obj.amountOfResidents;

    this->arrResidents = new Resident[obj.amountOfResidents];
    for (int i = 0; i < obj.amountOfResidents; i++) {
        this->arrResidents[i] = obj.arrResidents[i];
    }
}

Flat& Flat::operator=(const Flat& obj)
{
    this->_rooms = obj._rooms;
    this->_square = obj._square;
    this->amountOfResidents = obj.amountOfResidents;

    delete[] this->arrResidents;
    this->arrResidents = new Resident[obj.amountOfResidents];
    for (int i = 0; i < obj.amountOfResidents; i++) {
        this->arrResidents[i] = obj.arrResidents[i];
    }

    return *this;
}

Flat::~Flat()
{
    delete[] arrResidents;
}

void Flat::setRooms(int rooms)
{
    _rooms = rooms;
}

void Flat::setSquare(float square)
{
    _square = square;
}

int Flat::getRooms() const
{
    return _rooms;
}

float Flat::getSquare() const
{
    return _square;
}

int Flat::getAmountOfResidents() const
{
    return amountOfResidents;
}

void Flat::addResident(const Resident& person)
{
    Resident* tmp = new Resident[amountOfResidents + 1];
    for (int i = 0; i < amountOfResidents; i++) {
        tmp[i] = arrResidents[i];
    }
    tmp[amountOfResidents] = person;
    amountOfResidents++;
    delete[] arrResidents;
    arrResidents = tmp;
}

void Flat::delResident(const Resident& obj)
{
    int index = -1;
    for (int i = 0; i < amountOfResidents; i++) {
        if(strcmp(arrResidents[i].getName(), obj.getName()) == 0){
            index = i;
            break;
        }
    }
    for (int i = index; i < amountOfResidents - 1; i++) {
        arrResidents[i] = arrResidents[i + 1];
    }
    amountOfResidents--;
}

void Flat::showInfo() const
{
    cout << "\nRooms: " << _rooms << endl;
    cout << "Square: " << _square << endl;
    cout << "Amount of residents: " << amountOfResidents << endl;

    if (amountOfResidents > 0) {
        cout << "Residents: " << endl;
        for (int i = 0; i < amountOfResidents; i++) {
            cout << "#" << i + 1 << " " << arrResidents[i].getName() << endl;
        }
    }
    else {
        cout << "There are no residents" <<endl;
    }

}

void Flat::showInfoAboutRes() const {
    if (amountOfResidents > 0) {
        cout << "Residents: " << endl;
        for (int i = 0; i < amountOfResidents; i++) {
            cout << "#" << i + 1 << " " << arrResidents[i].getName() << endl;
        }
    }
    else {
        cout << "No residents in this flat" << endl;
    }
}
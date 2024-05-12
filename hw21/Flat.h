#pragma once
#include "Resident.h"

class Flat
{
	int _rooms;
	float _square;
	int amountOfResidents;
	Resident* arrResidents;

public:
	Flat();
	Flat(int rooms, float square);
	Flat(const Flat& obj);
	Flat& operator = (const Flat& obj);
	~Flat();

	void setRooms(int rooms);
	void setSquare(float square);

	int getRooms()const;
	float getSquare()const;
	int getAmountOfResidents()const;

	void addResident(const Resident& person);
	void delResident(const Resident& obj);
	void showInfo()const;
	void showInfoAboutRes()const;
};


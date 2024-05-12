#pragma once
#include "Flat.h"

class Building
{
	char* address;
	int numberOfFlats;
	Flat** flats;

public:
	Building();
	Building(const char* address, int numberOfFlats);
	~Building();

	void setAddress(const char* address);

	const char* getAddress()const;
	int getNumberOfFlats()const;

	void addResident(const Resident& person, int nFlat);
	void delResident(const Resident& obj, int nFlat);

	void showAllFlatsList()const;
	void showAllPersonList()const;
	void showPersonsListByFlat(int nFlat)const;
};


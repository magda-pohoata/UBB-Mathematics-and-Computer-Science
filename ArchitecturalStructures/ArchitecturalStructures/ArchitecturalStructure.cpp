#include "ArchitecturalStructure.h"

int ArchitecturalStructure::idGenerator = 0;

ArchitecturalStructure::ArchitecturalStructure()
{
	idGenerator++;
	this->m_id = idGenerator;
	this->m_name = "no name";
	this->m_architect = "no architect";
	this->m_yearOfConstruction = 0;
	this->m_height = 0;
	this->m_country = "no country";
}

ArchitecturalStructure::ArchitecturalStructure(string name, string architect, int year, int height,string country)
{
	idGenerator++;
	this->m_id = idGenerator;
	this->m_name = name;
	this->m_architect = architect;
	this->m_yearOfConstruction = year;
	this->m_height = height;
	this->m_country = country;
}

int ArchitecturalStructure::getId() const
{
	return this->m_id;
}

void ArchitecturalStructure::setName(string name)
{
	this->m_name = name;
}

string ArchitecturalStructure::getName() const
{
	return this->m_name;
}

void ArchitecturalStructure::setArchitect(string architect)
{
	this->m_architect = architect;
}

string ArchitecturalStructure::getArchitect() const
{
	return this->m_architect;
}

void ArchitecturalStructure::setYear(int year)
{
	this->m_yearOfConstruction = year;
}

int ArchitecturalStructure::getYear() const
{
	return this->m_yearOfConstruction;
}

void ArchitecturalStructure::setHeight(int height)
{
	this->m_height = height;
}

int ArchitecturalStructure::getHeight() const
{
	return this->m_height;
}

void ArchitecturalStructure::setCountry(string country)
{
	this->m_country = country;
}

string ArchitecturalStructure::getCountry() const
{
	return this->m_country;
}

void ArchitecturalStructure::display(ostream& os)
{
	
	os << this->m_id << " - " << this->m_name << " - " << this->m_architect << " - " << this->m_yearOfConstruction << " - " << this->m_height << " - " << this->m_country;

}

std::ostream& operator<<(std::ostream& os, ArchitecturalStructure& as)
{
	as.display(os);
	os << endl;
	return os;
}

istream& operator>>(istream& is, ArchitecturalStructure& as)
{
	is >> as.m_name >> as.m_architect >> as.m_yearOfConstruction >> as.m_height>>as.m_country;

	return is;

}

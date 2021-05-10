#include "ArchitecturalStructure.h"
#include "Castle.h"
#include "Church.h"
#include <sstream>

int ArchitecturalStructure::idGenerator = 0;

ArchitecturalStructure::ArchitecturalStructure()
{
	idGenerator++;
	this->m_id = idGenerator;
	this->m_type = 0;
	this->m_name = "no name";
	this->m_architect = "no architect";
	this->m_yearOfConstruction = 0;
	this->m_height = 0;
	this->m_country = "no country";
}

ArchitecturalStructure::ArchitecturalStructure(int type,string name, string architect, int year, int height,string country)
{
	idGenerator++;
	this->m_type = type;
	this->m_id = idGenerator;
	this->m_name = name;
	this->m_architect = architect;
	this->m_yearOfConstruction = year;
	this->m_height = height;
	this->m_country = country;
}

void ArchitecturalStructure::setType(int type)
{
	this->m_type = type;
}

int ArchitecturalStructure::getType() const
{
	return this->m_type;
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

void ArchitecturalStructure::display(ostream& os) const
{
	
	//os << this->m_id << " - " << this->m_name << " - " << this->m_architect << " - " << this->m_yearOfConstruction << " - " << this->m_height << " - " << this->m_country;
	stringstream strType;
	strType << this->m_type << ",";
	os << strType.str();
	//os.width(20);
	os << this->m_name + ",";
	//os.width(20);
	os << this->m_architect + ",";

	//os.width(10);
	stringstream strYear;
	strYear << this->m_yearOfConstruction << ",";
	os << strYear.str();

	//os.width(10);
	stringstream strHeight;
	strHeight << this->m_height << ",";
	os << strHeight.str();

	//os.width(20);
	os << this->m_country;
	
}

std::ostream& operator<<(std::ostream& os,const ArchitecturalStructure& as)
{
	as.display(os);
	//os << endl;
	return os;
}



vector<string> tokenize(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}


istream& operator>>(istream& is, ArchitecturalStructure& as)
{
	//is >> as.m_name >> as.m_architect >> as.m_yearOfConstruction >> as.m_height>>as.m_country;
	//return is;

	
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 6)
		return is;


	int year, height,type;
	std::istringstream(tokens[0]) >> type;
	std::istringstream(tokens[3]) >> year;
	std::istringstream(tokens[4]) >> height;
	as.m_type = type;
	as.m_name = tokens[1];
	as.m_architect = tokens[2];
	as.m_yearOfConstruction = year;
	as.m_height = height;
	as.m_country = tokens[5];

	return is;
	
	
}

bool operator==(const ArchitecturalStructure& a, const ArchitecturalStructure& b)
{
	return a.m_type == b.m_type && a.m_name == b.m_name && a.m_architect == b.m_architect && a.m_yearOfConstruction == b.m_yearOfConstruction && a.m_height == b.m_height && a.m_country == b.m_country;
}

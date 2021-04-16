#pragma once
#include <string>
#include <vector>
#include <istream>
#include <ostream>

using namespace std;

typedef enum
{
	RECREATIONAL_SPACE,
	HISTORIC_REPRESENTATION,         //either representing a moment in the history, or an important person, or representing a country
	RELIGIOUS_SPACE,
	ENTERTAINMENT,
	EXPOSITIONS,
	HOUSE

}Purpose;

class ArchitecturalStructure
{
public:
	ArchitecturalStructure();
	ArchitecturalStructure(string name, string architect, int year, int height,string country);


	int getId() const;

	void setName(string name);
	string getName() const;

	void setArchitect(string architect);
	string getArchitect() const;

	void setYear(int year);
	int getYear() const;

	void setHeight(int height);
	int getHeight() const;

	void setCountry(string country);
	string getCountry() const;

	virtual void display(ostream& os);

	friend std::ostream& operator<<(std::ostream& os, ArchitecturalStructure&);
	friend istream& operator>>(istream& is, ArchitecturalStructure&);

protected:
	string m_name;
	string m_architect;
	int m_yearOfConstruction;
	int m_height;
	string m_country;
	vector<Purpose> m_purpose;
	

private:
	int m_id;

	static int idGenerator;
};


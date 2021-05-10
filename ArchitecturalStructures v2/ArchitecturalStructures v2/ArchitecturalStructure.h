#pragma once
#include <string>
#include <vector>
#include <istream>
#include <ostream>


using namespace std;


class ArchitecturalStructure
{
public:
	ArchitecturalStructure();
	ArchitecturalStructure(string name, string architect, int year, int height,string country);
	virtual ~ArchitecturalStructure() = default;


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

	virtual void display(ostream& os) const;

	friend std::ostream& operator<<(std::ostream& os,const ArchitecturalStructure&);

	friend istream& operator>>(istream& is, ArchitecturalStructure&);

protected:
	string m_name;
	string m_architect;
	int m_yearOfConstruction;
	int m_height;
	string m_country;
	

private:
	int m_id;

	static int idGenerator;
};


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
	ArchitecturalStructure(int type,string name, string architect, int year, int height,string country);
	virtual ~ArchitecturalStructure() = default;

	void setType(int type);
	int getType() const;

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

	friend ostream& operator<<(ostream& os,const ArchitecturalStructure&);

	friend istream& operator>>(istream& is, ArchitecturalStructure&);

	friend bool operator==(const ArchitecturalStructure&, const ArchitecturalStructure&);

protected:
	int m_type;
	string m_name;
	string m_architect;
	int m_yearOfConstruction;
	int m_height;
	string m_country;
	

private:
	int m_id;

	static int idGenerator;
};


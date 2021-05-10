#pragma once
#include "ArchitecturalStructure.h"
#include <string>

class Castle : public ArchitecturalStructure
{
public:
	Castle() :ArchitecturalStructure() {
		m_type = 2;
		m_royalty = "no royal family";
	}
	Castle(int type,string name, string architect, int year, int height,string country, string royalty) : ArchitecturalStructure(type,name, architect, year, height, country) {
		this->m_type = 2;
		this->m_royalty = royalty;
	}

	string getRoyal() const;
	void setRoyal(string royal);

	void display(ostream& os)const override;
	friend istream& operator>>(istream& is, Castle&);

private:
	string m_royalty;

};


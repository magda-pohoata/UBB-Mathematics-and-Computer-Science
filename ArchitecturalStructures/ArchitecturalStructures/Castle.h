#pragma once
#include "ArchitecturalStructure.h"

class Castle : public ArchitecturalStructure
{
public:
	Castle() :ArchitecturalStructure() {
		m_purpose.push_back(HISTORIC_REPRESENTATION);
		m_purpose.push_back(HOUSE);
		m_royalty = "no royal family";
	}
	Castle(string name, string architect, int year, int height,string country, string royalty) : ArchitecturalStructure(name, architect, year, height, country) {
		m_purpose.push_back(HISTORIC_REPRESENTATION);
		m_purpose.push_back(HOUSE);
		this->m_royalty = royalty;
	}

	string getRoyal() const;
	void setRoyal(string royal);

	void display(ostream& os) override;
	friend istream& operator>>(istream& is, Castle&);

private:
	string m_royalty;

};


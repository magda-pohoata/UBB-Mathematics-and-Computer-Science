#pragma once
#include "ArchitecturalStructure.h"

/*
typedef enum {
	NO_STYLE,
	BAROQUE,
	GOTHIC,
	BYZANTINE,
	ROMANESQUE,
	RENAISSANCE,
	NEOCLASSICAL,
	REVIVAL,
	MODERN
}Style;
*/

class Church : public ArchitecturalStructure
{
public:
	Church() :ArchitecturalStructure(){
		m_type = 1;
		m_religion = "no religion";
		m_style = "no style";
	}

	Church(int type,string name, string architect, int year, int height, string country, string religion,string style) : ArchitecturalStructure(type,name, architect, year, height, country) {
		this->m_type = 1;
		this->m_religion = religion;
		this->m_style = style;
	}

	string getReligion() const;
	void setReligion(string religion);

	string getStyle() const;
	void setStyle(string style);

	void display(ostream& os)const override;
	friend istream& operator>>(istream& is, Church&);

private:
	string m_religion;
	string m_style;
};


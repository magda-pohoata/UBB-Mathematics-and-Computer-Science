#pragma once
#include "ArchitecturalStructure.h"

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

class Church : public ArchitecturalStructure
{
public:
	Church() :ArchitecturalStructure(){
		m_purpose.push_back(RELIGIOUS_SPACE);
		m_religion = "no religion";
		m_style = Style(0);
	}

	Church(string name, string architect, int year, int height, string country, string religion, Style style) : ArchitecturalStructure(name, architect, year, height, country) {
		this->m_religion = religion;
		this->m_style = style;
	}

	string getReligion() const;
	void setReligion(string religion);

	Style getStyle() const;
	void setStyle(Style style);

	void display(ostream& os) override;
	friend istream& operator>>(istream& is, Church&);

private:
	string m_religion;
	Style m_style;
};


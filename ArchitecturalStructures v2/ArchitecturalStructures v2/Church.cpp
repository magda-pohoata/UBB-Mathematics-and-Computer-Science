#include "Church.h"
#include <sstream>

string Church::getReligion() const
{
	return this->m_religion;
}

void Church::setReligion(string religion)
{
	this->m_religion = religion;
}

string Church::getStyle() const
{
	return this->m_style;
}

void Church::setStyle(string style)
{
	this->m_style = style;
}

void Church::display(ostream& os) const
{
	os << "Church: ";
	ArchitecturalStructure::display(os);
	
	os << "," << m_religion << "," << m_style;
	os << endl;

}

/*
vector<string> tokenize(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}
*/

istream& operator>>(istream& is, Church& c)
{
	
	int style;
	is >> c.m_name >> c.m_architect >> c.m_yearOfConstruction >> c.m_height >> c.m_country >> c.m_religion >> c.m_style;

	return is;
	
	/*
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5)
		return is;

	c.m_name = tokens[1];
	c.m_architect = tokens[2];
	c.m_country = tokens[5];
	int year, height;
	int style;
	std::istringstream(tokens[3]) >> year;
	std::istringstream(tokens[4]) >> height;
	std::istringstream(tokens[7]) >> style;
	c.m_yearOfConstruction = year;
	c.m_height = height;
	c.m_religion = tokens[6];
	c.m_style = tokens[7];

	return is;
	*/
}

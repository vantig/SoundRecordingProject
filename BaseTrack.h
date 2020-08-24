#pragma once
#include"HeaderMain.h"
class BaseTrack
{
	std::string type;
	std::string name;
	std::string performer;
	std::string style;
	double duration;
	double size;

public:

	BaseTrack() = default;
	virtual ~BaseTrack() = default;
	std::string getName()const { return name; }
	std::string getPerfomer()const { return performer; }
	std::string getStyle()const { return style; }
	std::string getType()const { return type; }
	double getSize()const { return size; }
	double getDuration() const { return duration; }
	void setName(std::string n) { name = n; }
	void setStyle(std::string s) { style = s; }
	void setDuration(double d) { duration = d; }
	void setSize(double s) { size = s; }
	void setType(std::string str) { type = str; }
	virtual std::istream& read(std::istream& in)
	{
		in >> name >>performer>> style >> duration>>size ;
		return in;
	}
	virtual	std::ostream& print(std::ostream& out)const
	{
		out << std::setw(10) <<type<< " | name " << std::setw(20) << name << std::setw(10)  <<" style " << std::setw(15) << style  << " duration " << std::setw(5) << duration<<" size " << std::setw(4) <<size ;
		return out;
	}
	

};
std::ostream& operator<<(std::ostream& out, std::shared_ptr<BaseTrack >s1)
{
	s1->print(out);
	return out;
}
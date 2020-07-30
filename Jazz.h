#pragma once
#include"HeaderMain.h"

class Jazz :public BaseTrack
{
private:
	std::string homeland;
	std::string date;


public:
	Jazz() { this->setType("Jazz"); }
	~Jazz() = default;
	std::istream& read(std::istream& in)override
	{
		BaseTrack::read(in);
		in >> homeland >> date;
		return in;
	}

	std::ostream& print(std::ostream& out)const override
	{
		BaseTrack::print(out);
		out << " homeland " << homeland << " date " << date << std::endl;
		return out;
	}

};

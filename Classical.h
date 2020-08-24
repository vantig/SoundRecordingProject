#pragma once
#include"HeaderMain.h"

class Classical :public BaseTrack
{
private:
	std::string MainInstrument;
	bool relax;



public:
	Classical() { this->setType("Classical"); }
	~Classical() = default;
	std::istream& read(std::istream& in)override
	{
		BaseTrack::read(in);
		in >> MainInstrument>> relax;
		return in;
	}

	std::ostream& print(std::ostream& out)const override
	{
		BaseTrack::print(out);
		out << " Main Instrument " << MainInstrument <<" relax(y/n) "<< relax << std::endl;

		return out;
	}

};

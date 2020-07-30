#pragma once
#include"HeaderMain.h"

class Rock :public BaseTrack
{
private:
	std::string group;
	std::string subculture;
	

public:
	Rock() { this->setType("Rock"); }
	~Rock() = default;
	std::istream& read(std::istream& in)override
	{
		BaseTrack::read(in);
		in >> group >> subculture;
		return in;
	}

	std::ostream& print(std::ostream& out)const override
	{
		BaseTrack::print(out);
		out << " group " << group << " subculture " << subculture<<  std::endl;
		return out;
	}

};

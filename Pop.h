#pragma once
#include"HeaderMain.h"

class Pop :public BaseTrack
{
private:
	bool dancing;




public:
	Pop() { this->setType("Pop"); }
	~Pop() = default;
	std::istream& read(std::istream& in)override
	{
		BaseTrack::read(in);
		in >> dancing;
		return in;
	}

	std::ostream& print(std::ostream& out)const override
	{
		BaseTrack::print(out);
		out << " dancing(y/n) " << dancing << std::endl;

		return out;
	}

};

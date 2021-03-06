#pragma once
#include"HeaderMain.h"
std::shared_ptr<BaseTrack> getPtr(char C);
//void swap(std::shared_ptr<BaseTrack>a, std::shared_ptr<BaseTrack>b);
class Playlist
{
public:
	Playlist() = default;
	~Playlist() = default;
	void ReadinVector(std::istream& in);
	void Print(std::ostream& out);
	void createPlaylistByStyle(std::istream& ,std::string );
	void shuffle();
	void ShuffleByStyle(std::string);
	std::vector<std::shared_ptr<BaseTrack>>findMusicinRange(double start, double finish);
	std::vector<std::shared_ptr<BaseTrack>> findAllMusicInRangeWithStyle(double start, double finish, std::string str);
	std::vector<std::shared_ptr<BaseTrack>>music;

};
std::ostream& operator<<(std::ostream& out, std::vector<std::shared_ptr<BaseTrack>>v)
{
	std::copy(v.begin(), v.end(), std::ostream_iterator<std::shared_ptr<BaseTrack>>(out, "\n"));
	return out;
}
void Playlist::ShuffleByStyle(std::string str)
{
	int temp;
	bool flag = true;
	srand(time(0));
	for (size_t i = 0; i < (rand() % this->music.size()-1)+1; i++)
	{
		if (this->music[i]->getType() == str)
		{
			while (flag)
			{
				temp = rand() % this->music.size();
				if (music[temp]->getType() == str)
				{
					this->music[i].swap(this->music[temp]);
					flag = false;
				}
			}

		}

	}
}

std::vector<std::shared_ptr<BaseTrack>>Playlist::findAllMusicInRangeWithStyle
(double start, double finish, std::string str)
{
	std::vector<std::shared_ptr<BaseTrack>>music1;
	std::for_each(music.begin(), music.end(), [&music1,str,start, finish](std::shared_ptr<BaseTrack> &temp)
		{
			if (temp->getDuration() <= finish && start <= temp->getDuration()&&temp->getType()==str)
			{
				
				music1.push_back(temp);
			}
		});
	/*std::copy(music1.begin(), music1.end(), std::ostream_iterator<std::shared_ptr<BaseTrack>>(std::cout," "));*/
	return music1;

}



std::vector<std::shared_ptr<BaseTrack>> Playlist::findMusicinRange(double start, double finish)
{ 
	std::vector<std::shared_ptr<BaseTrack>>music1;
	for (auto& track : this->music) {
		double duration = track->getDuration();
		if (duration >= start && duration <= finish) {
		
			music1.push_back( track); 
		}
	}
	return music1;
}

//void swap(std::shared_ptr<BaseTrack>a, std::shared_ptr<BaseTrack>b)
//{
//	auto c = &a;
//	&a = &b;
//	&b = &c;
//}
void Playlist::shuffle()
{
	srand(time(0));
	for (size_t i = 0; i <=rand()% this->music.size(); i++)
	{
		this->music[i].swap(this->music[rand() % this->music.size()]);
	}
	/*std::for_each(music.begin(), music.end(), [](std::shared_ptr<BaseTrack>a)
		{
		
		a.swap(a.music[rand() %music.size()]);
		});*/
}
void Playlist::Print(std::ostream& out)
{
	std::copy(music.begin(), music.end(), std::ostream_iterator<std::shared_ptr<BaseTrack>>(out, "\n"));

}
void Playlist:: createPlaylistByStyle(std::istream& in,std::string str)
{
	char simbol1(str[0]), simbol2;
	
	while (!in.eof())
	{
		in >> simbol2;
		getline(in, str);
		std::istringstream input(str);
		if (simbol1 == simbol2)
		{
			music.push_back(getPtr(simbol2));
			std::string str;
			
			music.back()->read(input);
		}
		
	}

}

void Playlist::ReadinVector(std::istream& in)
{



	while (!in.eof())
	{
		char simbol;
		in >> simbol;
		music.push_back(getPtr(simbol));
		std::string str;
		getline(in, str);
		std::istringstream input(str);
		music.back()->read(input);

	}

}
std::shared_ptr<BaseTrack> getPtr(char C)
{
	switch (C)
	{
	case 'c':
	{
		return std::make_shared<Classical>();
	}
	case 'r':
	{
		return std::make_shared<Rock>();
	}
	case 'p':
	{
		return std::make_shared<Pop>();
	}
	case 'j':
	{
		return std::make_shared<Jazz>();
	}
	default:
		break;
	}
}

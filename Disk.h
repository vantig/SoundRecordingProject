#pragma once
#include"HeaderMain.h"
class Disk
{
private:
	std::vector<std::shared_ptr<BaseTrack>>playlist;
	double freeSize ;
protected:
	void setsize(double d) { freeSize = d; }
public:
	void ShuffleByStyle(std::string);
	
	Disk(double s) 
	{
		freeSize = s;
    };

	~Disk() = default;
	double DurationOfMusic();
	double getsizeDisk()const { return freeSize; }
	void copyPlaylist(Playlist&);

	void Print(std::ostream&);
	std::shared_ptr<BaseTrack> findMusicinRange(double start, double finish);

	std::vector<std::shared_ptr<BaseTrack>>findAllMusicInRangeWithStyle(double start, double finish, std::string str, std::vector<std::shared_ptr<BaseTrack>>&);

};
std::vector<std::shared_ptr<BaseTrack>>Disk::findAllMusicInRangeWithStyle
(double start, double finish, std::string str, std::vector<std::shared_ptr<BaseTrack>>&music)
{
	std::for_each(playlist.begin(), playlist.end(), [&music, str, start, finish](std::shared_ptr<BaseTrack> temp)
		{
			if (temp->getDuration() <= finish && start <= temp->getDuration() && temp->getType() == str)
			{

				music.push_back(temp);
			}
		});
	std::copy(music.begin(), music.end(), std::ostream_iterator<std::shared_ptr<BaseTrack>>(std::cout, " "));
	return music;

}

std::shared_ptr<BaseTrack> Disk::findMusicinRange(double start, double finish)
{
	std::for_each(playlist.begin(), playlist.end(), [start, finish](std::shared_ptr<BaseTrack> temp)
		{
			if (temp->getDuration() <= finish && start <= temp->getDuration())
			{
				std::cout << temp;
				return temp;
			}

		});
	std::shared_ptr<BaseTrack>a;
	return a;
}
void Disk::ShuffleByStyle(std::string str)
{
	int temp;
	bool flag = true;
	srand(time(0));
	for (size_t i = 0; i < this->playlist.size(); i++)
	{
		if (this->playlist[i]->getType()==str)
		{
			while (flag)
			{
				temp = rand() % this->playlist.size();
				if (playlist[temp]->getType() == str)
				{
					this->playlist[i].swap(this->playlist[temp]);
					flag = false;
				}
			}

		}
		
	}
}

double Disk:: DurationOfMusic()
{
	double temp = 0;
	std::for_each(playlist.begin(), playlist.end(), [&temp](std::shared_ptr<BaseTrack>b) {temp += b->getDuration(); });
	temp *= 100;
	if ((int)temp % 100 < 60)
	{
		return temp / 100;
	}
	else
	{
		int min, sec;
		min = (int)temp / 100;
		sec = (int)temp % 100;
		min += sec / 60;
		sec = sec % 60;
		temp = min + ((double)sec / 100.0);
		return temp;
	}



}

void Disk:: copyPlaylist(Playlist& p)
{
	double temp=this->freeSize ;
	std::copy_if(p.music.begin(), p.music.end(),back_inserter(playlist), [&temp,this]( std::shared_ptr<BaseTrack> b)
	{

			if (b->getSize() <= temp)
			{
				temp = temp - b->getSize();

				return true;
			}
			else
			{
			    
				return false;
			}
			
	});
	this->setsize(temp);
}

void Disk::Print(std::ostream& out)
{
	std::copy(playlist.begin(), playlist.end(), std::ostream_iterator<std::shared_ptr<BaseTrack>>(out));
}

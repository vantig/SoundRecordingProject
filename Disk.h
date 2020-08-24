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

	
	Disk(double s) 
	{
		freeSize = s;
    };

	~Disk() = default;
	
	double DurationOfMusic();
	double getsizeDisk()const { return freeSize; }
	void copyPlaylist(Playlist&);

	void Print(std::ostream&);
	
	std::vector<std::shared_ptr<BaseTrack>> findMusicinRange(double start, double finish);
	std::vector<std::shared_ptr<BaseTrack>>findAllMusicInRangeWithStyle(double start, double finish, std::string str);

};

std::vector<std::shared_ptr<BaseTrack>>Disk::findAllMusicInRangeWithStyle
(double start, double finish, std::string str)
{
	std::vector<std::shared_ptr<BaseTrack>>music1;
	std::for_each(playlist.begin(), playlist.end(), [&music1, str, start, finish](std::shared_ptr<BaseTrack>& temp)
		{
			if (temp->getDuration() <= finish && start <= temp->getDuration() && temp->getType() == str)
			{

				music1.push_back(temp);
			}
		});
	return music1;

}
std::vector<std::shared_ptr<BaseTrack>> Disk::findMusicinRange(double start, double finish)
{
	std::vector<std::shared_ptr<BaseTrack>>music1;
	for (auto& track : this->playlist) {
		double duration = track->getDuration();
		if (duration >= start && duration <= finish) {

			music1.push_back(track);
		}
	}
	return music1;
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

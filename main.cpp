#include"HeaderMain.h"


int main()
{
		Playlist playlist;
		std::ifstream in("Text.txt");
		Disk disk(600);

	/*	std::cout << " enter style ";
		std::string str;		std::cin >> str;
		playlist.createPlaylistByStyle(in,str);*/
		
		double temp = disk.getsizeDisk();
		playlist.ReadinVector(in);
		playlist.Print(std::cout);
		playlist.findMusicinRange(0.37, 2.0);
		
	

	/*	disk.Print(std::cout);
		std::cout<<std::endl;
		int temp1= disk.DurationOfMusic()*100;
		std::cout <<" duration of music "<<(int)temp1/100<<" min "<<(int)temp1%100<<" sec "<<std::endl<<"size of music on disk(MB)"<<temp-disk.getsizeDisk()<<std::endl<<"free size on disk(MB)"<< disk.getsizeDisk();*/

	




	return 0;
}
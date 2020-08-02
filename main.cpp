#include"HeaderMain.h"


int main()
{
	int  choice;
	bool flag=1;
	Playlist playlist;
	std::ifstream in("Text.txt");
	while (flag)
	{
		std::cout <<
			"1.create and initial playlist" << std::endl
			<< "2.create and initial playlist by style" << std::endl
			<< "0.exit" << std::endl;
		std::cin >> choice;
			
		switch (choice)
		{
		case 1:
		{

			
			playlist.ReadinVector(in);	
			bool flag=1;
			while (flag)
			{
				std::cout <<
					"1.create disk" << std::endl
					<<"2.copy playlist on the disk"<< std::endl
					<< "0.exit" << std::endl;
				int  choice;
				std::cin >> choice;
				switch (choice)
				{
				case 1:
				{
					std::cout << " Enter size of the disk" << std::endl;
					int temp;
					std::cin >> temp;
					Disk disk(temp);

				}
				
				case 0:
				{
					exit;
				}
				default:continue;
					break;
				}
			}
		}
		
		case 2:
		{
			std::string s;
			std::cout << "Enter style" << std::endl;
			std::cin >> s;
			playlist.createPlaylistByStyle(in,s);
			bool flag=1;
			while (flag)
			{
				std::cout <<
					"1.create disk" << std::endl
					<< "2.copy playlist on the disk" << std::endl
					<< "0.exit" << std::endl;
				int  choice;
				std::cin >> choice;
				switch (choice)
				{
				case 1:
				
				{
					std::cout << " Enter size of the disk" << std::endl;
					int temp;
					std::cin >> temp;
					Disk disk(temp);
					
				}
				case 2:
				
				 
				
				case 0:
				
					exit;
				
				default:continue;
					break;
				}
			}
		}
		
		case 0:
		{
			exit;
		}
		default:
			break;
		}
	}
	

	/*	std::cout << " enter style ";
		std::string str;		std::cin >> str;
		playlist.createPlaylistByStyle(in,str);
		
		double temp = disk.getsizeDisk();*/
	
		std::vector<std::shared_ptr<BaseTrack>>playlist1;
		//playlist.findAllMusicInRangeWithStyle(0.37, 7.0, "Classical", playlist1); 
		std::copy(playlist1.begin(), playlist1.end(), std::ostream_iterator<std::shared_ptr<BaseTrack>>(std::cout, " "));

	

	/*	disk.Print(std::cout);
		std::cout<<std::endl;
		int temp1= disk.DurationOfMusic()*100;
		std::cout <<" duration of music "<<(int)temp1/100<<" min "<<(int)temp1%100<<" sec "<<std::endl<<"size of music on disk(MB)"<<temp-disk.getsizeDisk()<<std::endl<<"free size on disk(MB)"<< disk.getsizeDisk();*/

	




	return 0;
}
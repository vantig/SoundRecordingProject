#include"HeaderMain.h"


int main()
{
	
	Playlist playlist;
	bool flag = 1;
	int  temp;
	std::cout << "\nto create a playlist ENTER the name of the music file" << std::endl;
	std::string str;
tryAgain:	std::cin >> str;
	std::ifstream in(str);
	if (in.is_open())
	{
		
		std::cout << "\nsuccessfully\n" << std::endl;

	}
	else
	{
		std::cout << "\n NOT FOUND, try again\n" << std::endl;

		goto tryAgain;
	}
	std::cout << "\n1 .Create Playlist\n2 .Create Playlist By Style\n\n";

	std::cin >> temp;
	switch (temp)
	{
	case 1:
	{
		
		playlist.ReadinVector(in);
		std::cout << "\nsuccessfully\n" << std::endl;
		break;
	}
	case 2:
	{
		std::cout << "\n1 .Rock\n2 .Pop\n3 .Jazz\n4 .Classical\n\n";
		std::cin >> temp;
		switch (temp)
		{
		case 1:
		{
			str = "r";
			break;
		}
		case 2:
		{
			str = "p";
			break;

		}
		case 3:
		{
			str = "j";
			break;

		}
		case 4:
		{
			str = "c";
			break;

		}
		default:
			break;
		}
		
		playlist.createPlaylistByStyle(in,str);
		std::cout << "\nsuccessfully\n" << std::endl;
		break;
	}
	default:
		break;
	}

	std::cout << "\nto create a disk ENTER the size of the disk" << std::endl;

		std::cin >> temp;
		Disk disk(temp);
		std::cout << "\nsuccessfully\n" << std::endl;
		disk.copyPlaylist(playlist);
		std::cout << "\playlist copied to disk\n" << std::endl;
		do
		{
			std::cout << "MENU:\n1 .Disk\n2 .Playlist\n0 .Exit\n";
			std::cin >> temp;
			switch (temp)
			{
			case 1:
			{
				//Disk
				std::cout << "DISK:\n1 .Free size\n2 .Duration of music\n3 .Find Music in Range\n4 .Find All Music In Range With Style\n5 .Print\n6 .Copy playlist\n7 .Back\n";
				std::cin >> temp;
				switch (temp)
				{
				case 1:
				{
					std::cout << disk.getsizeDisk()<<std::endl;
					break;
				}
				case 2:
				{
					std::cout << disk.DurationOfMusic() << std::endl;
					break;
				}
				case 3:
				{
					double start, finish;
					std::cout << "\nEnter start\n";
					std::cin >> start;
					std::cout << "\nEnter finish\n";
					std::cin >> finish;
					std::cout << disk.findMusicinRange(start,finish) << std::endl;
					break;
				}
				case 4:
				{
					double start, finish;
					std::cout << "\nEnter start\n";
					std::cin >> start;
					std::cout << "\nEnter finish\n";
					std::cin >> finish;
					std::cout << "\nEnter style\n";
					std::cout << "\n1 .Rock\n2 .Pop\n3 .Jazz\n4 .Classical\n\n";
					std::cin >> temp;
					switch (temp)
					{
					case 1:
					{
						str = "Rock";
						break;
					}
					case 2:
					{
						str = "Pop";
						break;

					}
					case 3:
					{
						str = "Jazz";
						break;

					}
					case 4:
					{
						str = "Classical";
						break;

					}
					default:
						break;
					}
					
					std::cout << disk.findAllMusicInRangeWithStyle(start, finish, str);
					break;
				}
				case 5:
				{
					disk.Print(std::cout);
					break;
				}
				case 6:
				{
					
				    disk.copyPlaylist(playlist);
					break;
				}
				default:
					temp = 10;
					break;
				}



				break;

			

			}
			case 2:
			{

				

			
				//Playlist
				std::cout << "PLAYLIST:\n1 .Shuffle\n2 .Shuffle By Style\n3 .Find Music in Range\n4 .Find All Music In Range With Style\n5 .Print\n6 .Back\n";
				std::cin >> temp;
				switch (temp)
				{
				case 1:
				{
					playlist.shuffle();
					
					playlist.Print(std::cout);
					std::cout << "\nsuccessfully\n" << std::endl;
					break;
				}
				case 2:
					std::cout << "\nEnter style\n";
					
				{std::cout << "\n1 .Rock\n2 .Pop\n3 .Jazz\n4 .Classical\n\n";
				std::cin >> temp;
				switch (temp)
				{
				case 1:
				{
					str = "Rock";
					break;
				}
				case 2:
				{
					str = "Pop";
					break;

				}
				case 3:
				{
					str = "Jazz";
					break;

				}
				case 4:
				{
					str = "Classical";
					break;

				}
				default:
					break;
				}
					

					playlist.ShuffleByStyle(str);
					playlist.Print(std::cout);
					break;
				}
				case 3:
				{
					double start, finish;
					std::cout<< "\nEnter start\n";
					std::cin >> start;
					std::cout << "\nEnter finish\n";
					std::cin >> finish;
					std::cout <<playlist.findMusicinRange(start,finish);
					break;
				}
				case 4:
				{ double start, finish;
				    std::cout << "\nEnter start\n";
				    std::cin >> start;
				    std::cout << "\nEnter finish\n";
			     	std::cin >> finish;
					std::cout << "\nEnter style\n";
					std::cout << "\n1 .Rock\n2 .Pop\n3 .Jazz\n4 .Classical\n\n";
					
					std::cin >> temp;
					switch (temp)
					{
					case 1:
					{
						str = "Rock";
						break;
					}
					case 2:
					{
						str = "Pop";
						break;

					}
					case 3:
					{
						str = "Jazz";
						break;

					}
					case 4:
					{
						str = "Classical";
						break;

					}
					default:
						break;
					}
			    	
				    
					std::cout << playlist.findAllMusicInRangeWithStyle(start, finish,str);
					break;
				}
				case 5:
				{
					playlist.Print(std::cout);
					break;
				}
				default:
					temp = 10;
					break;
				}

				break;
			}
			case 0:
			{
				exit;
				break;
			}
			default:
				std::cout << "WRONG NUMBER , TRY AGAIN\n";
				break;
			}
		}while (temp);

	

	return 0;
}
#include <iostream>
#include <map>
#include <conio.h>

#include "list.h"
#include "bus.h"
#include "commands.h"


int main()
{
	List<Bus> parkedBusList = List<Bus>();
	List<Bus> activeBusList = List<Bus>();
	
	parkedBusList.add(Bus(1, 1, "Ivanov I.I."));
	parkedBusList.add(Bus(2, 1, "Petrov P.P."));
	parkedBusList.add(Bus(3, 2, "Ivanov P.P."));
	
	activeBusList.add(Bus(4, 2, "Petrov I.I."));
	activeBusList.add(Bus(5, 1, "Afanasyev A.A."));
	
	std::map<std::string, int> commandMap{
		{"exit", COMMAND_EXIT},
		{"info", COMMAND_INFO},
		{"recall", COMMAND_RECALL},
		{"send", COMMAND_SEND}
	};
	
	
	while(true)
	{
		std::string command;
		
		std::cout << ">";
		std::cin >> command;
		
		switch(commandMap.count(command) ? commandMap[command] : COMMAND_DEFAULT)
		{
			case COMMAND_EXIT:
				break;
			case COMMAND_INFO:
				std::cout << "Parked buses:\t";
				parkedBusList.print();
				
				std::cout << "\nActive buses:\t";
				activeBusList.print();
				
				std::cout << std::endl;
				
				continue;
			case COMMAND_RECALL:
			{
				size_t number;
				std::cin >> number;
				
				if(activeBusList.contains(Bus(number)))
				{
					Bus bus = activeBusList.get(Bus(number));
					
					activeBusList.remove(bus);
					parkedBusList.add(bus);
					
					std::cout << "Bus " << number << " successfully recalled." << std::endl;
					continue;
				}
				
				std::cout << "Bus " << number << " is currently inactive or does not exist." << std::endl;
				continue;
			}
			case COMMAND_SEND:
			{
				size_t number;
				std::cin >> number;
				
				if(parkedBusList.contains(Bus(number)))
				{
					Bus bus = parkedBusList.get(Bus(number));
					
					parkedBusList.remove(bus);
					activeBusList.add(bus);
					
					std::cout << "Bus " << number << " successfully send out." << std::endl;
					continue;
				}
				
				std::cout << "Bus " << number << " is currently active or does not exist." << std::endl;
				continue;
			}
			default:
			{
				std::cout << "Command list:\n\texit:\tClose the program.\n\tinfo:\tDisplay bus info.\n\trecall N:\tRecall bus N.\n\tsend N:\tSend out bus N.\n";
				continue;
			}
		}
		
		break;
	}
	
	return 0;
}


#include "Pipe.h"
#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include "Board.h"
#include "Piece.h"

void main()
{
	srand(time_t(NULL));
	
	
	Pipe p;
	
	bool isConnect = p.connect();
	
	std::string ans;
	while (!isConnect)
	{
		std::cout << "cant connect to graphics" << std::endl;
		std::cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << std::endl;
		std::cin >> ans;

		if (ans == "0")
		{
			std::cout << "trying connect again.." << std::endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE
	//strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1");
	strcpy_s(msgToGraphics, "r###k##rpppppppp################################PPPPPPPPR##K###R0"); // just example...
	
	std::string temp = msgToGraphics;
	std::cout << msgToGraphics << " " << temp.length() << std::endl;
	try
	{
		Board game(temp);
		p.sendMessageToGraphics(msgToGraphics);   // send the board string
		game.printBoard();
												  // get message from graphics
		std::string msgFromGraphics = p.getMessageFromGraphics();
		while (msgFromGraphics != "quit")
		{
			// should handle the string the sent from graphics
			// according the protocol. Ex: e2e4           (move e2 to e4)

			// YOUR CODE
			ans = game.movePiece(Point(msgFromGraphics[0], msgFromGraphics[1]), Point(msgFromGraphics[2], msgFromGraphics[3]));
			game.printBoard();
			strcpy_s(msgToGraphics, ans.c_str()); // msgToGraphics should contain the result of the operation



												  // return result to graphics		
			p.sendMessageToGraphics(msgToGraphics);

			// get message from graphics
			msgFromGraphics = p.getMessageFromGraphics();
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		system("PAUSE");
	}
	p.close();
}
// required header file 
#include <conio.h> 
#include <iostream> 
#include <windows.h> 
#include <vector>
#include <map>
#include <limits>



const int width = 80; 
const int height = 20; 

enum idkWhatToCallTheseThings { empty, X, O };  
bool isGameOver; 
bool didUserWin;
bool didCompWin;


std::map<int, idkWhatToCallTheseThings> boardMap;
 

constexpr std::string_view getThingOnBoard(idkWhatToCallTheseThings name)
{
    switch (name)
    {
    case empty: return " ";
    case X:   return "X";
    case O:  return "O";
    default:    return " ";
    }
}


void GameInit() //2 diag  horizontal 3 vert
{ 
	isGameOver = false; 
	didUserWin = false;
	didCompWin = false;
	boardMap = {
	{0, empty}, {1, empty}, {2, empty}, 
	{3, empty}, {4, empty}, {5, empty},
	{6, empty}, {7, empty}, {8, empty}
	};
} 

void GameRender() 
{ 
	int counter = 0;
	for (const auto& x : boardMap)
	{	
		if(counter == 1 || counter == 4 || counter == 7)
			std::cout << " | " << getThingOnBoard(x.second) << " | ";
		else 
			std::cout << getThingOnBoard(x.second);
		
		if(counter == 2 || counter == 5)
			std::cout << std::endl;
		counter ++;
	}	
} 

bool GameChecker()
{
	if(boardMap.at(0) != empty && (boardMap.at(0) == boardMap.at(4) && boardMap.at(0) == boardMap.at(8)))
	{
		if(boardMap.at(0) == X)
			didUserWin = true;
		else 
			didCompWin = true;
		return true;
	}
	if(boardMap.at(6) != empty && ((boardMap.at(6) == boardMap.at(4)) && boardMap.at(6) == boardMap.at(2)))
	{
		if(boardMap.at(6) == X)
			didUserWin = true;
		else 
			didCompWin = true;
		return true;
	}
	if(boardMap.at(0) != empty && (boardMap.at(0) == boardMap.at(1) && boardMap.at(0) == boardMap.at(2)))
	{
		if(boardMap.at(0) == X)
			didUserWin = true;
		else 
			didCompWin = true;
		return true;
	}
	if(boardMap.at(3) != empty && (boardMap.at(3) == boardMap.at(4) && boardMap.at(3) == boardMap.at(5)))
	{
		if(boardMap.at(3) == X)
			didUserWin = true;
		else 
			didCompWin = true;
		return true;
	}
	if(boardMap.at(6) != empty && (boardMap.at(6) == boardMap.at(7) && boardMap.at(6) == boardMap.at(8)))
	{
		if(boardMap.at(6) == X)
			didUserWin = true;
		else 
			didCompWin = true;
		return true;
	}
	if(boardMap.at(0) != empty && (boardMap.at(0) == boardMap.at(3) && boardMap.at(0) == boardMap.at(6)))
	{
		if(boardMap.at(0) == X)
			didUserWin = true;
		else 
			didCompWin = true;
		return true;
	}
	if(boardMap.at(1) != empty && (boardMap.at(1) == boardMap.at(4) && boardMap.at(1) == boardMap.at(7)))
	{
		if(boardMap.at(1) == X)
			didUserWin = true;
		else 
			didCompWin = true;
		return true;
	}
	if(boardMap.at(3) != empty && (boardMap.at(3) == boardMap.at(5) && boardMap.at(3) == boardMap.at(8)))
	{
		if(boardMap.at(3) == X)
			didUserWin = true;
		else 
			didCompWin = true;
		return true;
	}
	for (const auto& x : boardMap)
	{
		if(x.second == empty)
		{
			std::cout << "Not done yet";
			return false;
		}
	}
	return true;
}

bool GameFilled()
{
	for (const auto& x : boardMap)
	{
		if(x.second == empty)
		{
			return false;
		}
	}
	return true;
}

bool Checker(int a, int b, int c)
{
	if(boardMap[a] == empty && ((boardMap[b] == O && boardMap[c] == O) || (boardMap[b] == X && boardMap[c] == X)))
	{
		boardMap[a] = O;
		return true;
	} else if(boardMap[b] == empty && ((boardMap[a] == O && boardMap[c] == O) || (boardMap[a] == X && boardMap[c] == X)))
	{
		boardMap[a] = O;
		return true;
	} else if(boardMap[c] == empty && ((boardMap[a] == O && boardMap[b] == O) || (boardMap[a] == X && boardMap[b] == X)))
	{
		boardMap[c] = O;
		return true;
	}
	return false;
}

bool CheckForWinningMoves(idkWhatToCallTheseThings stillDontKnowWhatToCallThem)
{
	if(Checker(0, 1, 2))
	{
		return true;
	} else if(Checker(3, 4, 5))
	{
		return true;
	} else if(Checker(6, 7, 8))
	{
		return true;
	} else if(Checker(0, 3, 6))
	{
		return true;
	} else if(Checker(1, 4, 7))
	{
		return true;
	} else if(Checker(2, 5, 8))
	{
		return true;
	} else if(Checker(0, 4, 8))
	{
		return true;
	} else if(Checker(2, 4, 6))
	{
		return true;
	}
	return false;
}
void UpdateGame() 
{ 	
	if(CheckForWinningMoves(O))
	{
		return;
	} else if(CheckForWinningMoves(X))
	{
		return;
	} else
	{
		if(boardMap[4] == empty)
		{
			boardMap[4] = O;
		} else if(boardMap[0] == empty)
		{
			boardMap[0] = O;
		}else if(boardMap[2] == empty)
		{
			boardMap[2] = O;
		}else if(boardMap[6] == empty)
		{
			boardMap[6] = O;
		}else if(boardMap[8] == empty)
		{
			boardMap[8] = O;
		}else if(boardMap[1] == empty)
		{
			boardMap[1] = O;
		}else if(boardMap[3] == empty)
		{
			boardMap[3] = O;
		}else if(boardMap[5] == empty)
		{
			boardMap[5] = O;
		}else if(boardMap[7] == empty)
		{
			boardMap[7] = O;
		}
	}
} 

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool hasUnextractedInput()
{
    return !std::cin.eof() && std::cin.peek() != '\n';
}

void UserInput() 
{ 
	std::string sTest { };
	std::cout << std::endl;
	std::cout << "Enter your move: ";
	while(true)
	{
		std::cin >> sTest;
		int usersMove = std::stoi(sTest);
		if(usersMove < 0 || usersMove > 8)
		{
			std::cout << "Reenter your move: ";	
			std::cout << std::endl;
			continue;
		}

		std::cout << std::endl;
		if(boardMap[usersMove] == empty)
		{
			boardMap[usersMove] = X;
			break;
		}
		else if(boardMap[usersMove] == O)
		{
			std::cout << "Reenter your move: ";	
			std::cout << std::endl;
			continue;
		} else{
			std::cout << "idiot";
			std::cout << std::endl;
			break;
		}
	}	
} 

// Main function / game looping function 
int main() 
{ 
	GameInit(); 
	while (!isGameOver) { 
		if(GameFilled())
		{
			break;
		}
		GameRender(); 
		UserInput(); 
		if(GameChecker())
			isGameOver = true;

		UpdateGame(); 

		// creating a delay for according to the chosen 
		// difficulty 
	} 
	GameRender();
	std::cout << std::endl;
	if(didUserWin)
	{
		std::cout << "You won";
	} else if(didCompWin)
		std::cout << "You lost";
	else
		std::cout << "You tied";
	return 0; 
}

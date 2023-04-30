// Chess 
#include "Chess.h"
#include "board.h"

int main()
{
	//string board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr"; 
	string board = "B#########K##################q############R#############r#r#####";
	std::cout << board.size();
	Chess a(board);
	Board b(board);//create a board object by sending it the board
	int codeResponse = 0;
	string res = a.getInput();
	while (res != "exit")
	{
		/* 
		codeResponse value : 
		Illegal movements : 
		11 - there is not piece at the source  
		12 - the piece in the source is piece of your opponent
		13 - there one of your pieces at the destination 
		21 - illegal movement of that piece 
		31 - this movement will cause you checkmate

		legal movements : 
		41 - the last movement was legal and cause check 
		42 - the last movement was legal, next turn 
		*/
		codeResponse = b.getResponse(res);//call the get response funn to get 
							//the code response

		a.setCodeResponse(codeResponse);
		res = a.getInput(); 
	}

	cout << endl << "Exiting " << endl; 
	return 0;
}
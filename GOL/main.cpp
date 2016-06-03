#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

void displayBoard(int, vector<char>&);
void fillVector(int, vector<char>&);
void startPosition(int, vector<char>&);
void updateCells(int, vector<char>&);
int checkNeighbors(int, vector<char>&);

int main(){

    vector<char> board;
    int Size;

    cout << "Enter the size of the board: ";
    cin >> Size;

    fillVector(Size, board);

    cin.get();
    cout << "\nHere is your board!\n\n";
    displayBoard(Size, board);

    cin.get();
    system("CLS");
    //cin.get();


    startPosition(Size, board);
    displayBoard(Size, board);

    updateCells(Size, board);
    cin.get();
    system("CLS");
    cin.get();
    displayBoard(Size, board);
}

int checkNeighbors(int Size, vector<char>& board){

    int counter = 0;

    for(size_t i = 0; i < board.size(); i++){

        if(board[i]==0){ ///Special case, upper left corner

            if(board[i+Size] = '*'){ //Checks down one row
                counter++;
            }
            if(board[i+(Size+1)] = '*'){    //Checks down one, then right one
                counter++;
            }
            if(board[i+1] = '*'){   //Checks right one
                counter++;
            }
            //board[i+(Size-1)] = '*'; //Checks down one, then left one
            //board[i-(Size)] = '*';    //Checks up one row
            //board[i-(Size+1)] = '*';    //Checks up one, then right one
            //board[i-(Size-1)] = '*';    //Checks up one, then left one
            //board[i-1] = '*';   //Checks left one
        }
        else if(board[i]==(Size-1)){   ///special case, upper right corner
            if(board[i+Size]== '*'){ //Checks down one
                counter++;
            }
            if(board[i-1]== '*'){   //checks left one
                counter++;
            }
            if(board[i+(Size-1)]== '*'){    //Checks down one, then left
                counter++;
            }
        }
        else if(board[i]==((Size*Size)-1)){    ///special case, lower right corner
            if(board[i-Size]== '*'){    //Checks up one
                counter++;
            }
            if(board[i-1]== '*'){   //Checks left one
                counter++;
            }
            if(board[i-(Size-1)]== '*'){    //Checks up one, left one
                counter++;
            }
        }
        else if(board[i]==((Size*Size)-Size)){  ///special case, lower left corner
            if(board[i-Size]== '*'){    //checks up one
                counter++;
            }
            if(board[(i-Size)+1]== '*'){    //checks up one, right one
                counter++;
            }
            if(board[i+1]== '*'){   //checks right one
                counter++;
            }
        }

        ///Special Case: Left column
        else if(board[i]%Size==0){
            if(board[i+Size] = '*'){ //Checks down one row
                counter++;
            }
            if(board[i+(Size+1)] = '*'){    //Checks down one, then right one
                counter++;
            }
            if(board[i+1] = '*'){   //Checks right one
                counter++;
            }
            if(board[i-Size]== '*'){    //checks up one
                counter++;
            }
            if(board[(i-Size)+1]== '*'){    //checks up one, right one
                counter++;
            }
        }

        ///Special Case: Right column
        else if(board[i]%Size==1){
            if(board[i+Size] = '*'){ //Checks down one row
                counter++;
            }
            if(board[i+(Size-1)] = '*'){    //Checks down one, then left one
                counter++;
            }
            if(board[i-1] = '*'){   //Checks left one
                counter++;
            }
            if(board[i-Size]== '*'){    //checks up one
                counter++;
            }
            if(board[(i-Size)-1]== '*'){    //checks up one, left one
                counter++;
            }
        }

        ///Special Case: Top row
        else if(board[i]/Size==0){
            if(board[i+Size] = '*'){ //Checks down one row
                counter++;
            }
            if(board[i+(Size+1)] = '*'){    //Checks down one, then right one
                counter++;
            }
            if(board[i+(Size-1)] = '*'){    //Checks down one, then left one
                counter++;
            }
            if(board[i+1] = '*'){   //Checks right one
                counter++;
            }
            if(board[i-1] = '*'){   //Checks left one
                counter++;
            }
        }


        ///Special Case: Bottom row
        else if(board[i]/Size==(Size-1)){
            if(board[i-Size] = '*'){ //Checks up one row
                counter++;
            }
            if(board[i-(Size+1)] = '*'){    //Checks up one, then right one
                counter++;
            }
            if(board[i-(Size-1)] = '*'){    //Checks up one, then left one
                counter++;
            }
            if(board[i+1] = '*'){   //Checks right one
                counter++;
            }
            if(board[i-1] = '*'){   //Checks left one
                counter++;
            }
        }

        ///The rest of the body positions

        else{
            if(board[i-Size] = '*'){ //Checks up one row
                counter++;
            }
            if(board[i-(Size+1)] = '*'){    //Checks up one, then right one
                counter++;
            }
            if(board[i-(Size-1)] = '*'){    //Checks up one, then left one
                counter++;
            }
            if(board[i+1] = '*'){   //Checks right one
                counter++;
            }
            if(board[i-1] = '*'){   //Checks left one
                counter++;
            }
            if(board[i+Size] = '*'){ //Checks down one row
                counter++;
            }
            if(board[i+(Size+1)] = '*'){    //Checks down one, then right one
                counter++;
            }
            if(board[i+(Size-1)] = '*'){    //Checks down one, then left one
                counter++;
            }
        }
    }

    return counter;
}

void startPosition(int Size, vector<char>& board){

    int center = ((Size*Size/2)+(Size/2));
    int choice;

    cout << "Make a choice for your starting position: ";
    cout << "\n1. Glider"
         << "\n2. Something\n";
    cin >> choice;


    switch(choice){
        case 1 :    //Glider
            board[center] = '*';
            board[center+(Size+1)] = '*';
            board[center+(Size*2+1)] = '*';
            board[center+(Size*2-1)] = '*';
            board[center+(Size*2)] = '*';


    }


}

void updateCells(int Size, vector<char>& board){

    for(size_t i = 0; i < board.size(); i++){

        if(board[i]=='*' && (checkNeighbors(Size, board) < 2 || checkNeighbors(Size, board) > 3)){
            board[i] = '0';
        }
        else if(board[i]=='0' && checkNeighbors(Size, board) == 3){
            board[i] = '*';
        }
        else if(board[i]=='*' && (checkNeighbors(Size, board) == 2 || checkNeighbors(Size, board) == 3)){
        }
        else{
            board[i] = '0';
        }
    }
}

void displayBoard(int Size, vector<char>& board){

    //Here we are creating the board
    for(size_t i = 0; i <  board.size(); i++){

        if(board[i]=='*'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        }
        else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        }


        //output the elements of board
        cout << board[i];

        //Here is where the rows are created.
        //It's also i+1, so we can have the board sides be equal.
        if((i+1)%Size==0){
            cout << endl;
        }
    }
}

void fillVector(int Size, vector<char>& board){

    char cell = '0';

    for(int i = 0; i < Size*Size; i++){

        //Here are are filling the vector with the character '*'
        board.push_back(cell);
    }
}

#include <iostream>
#include <vector>
#include <random>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;


int main() {
    short board[9][9];
    string input = "";

    // initializing board
    // UNCOMMENT THIS PART TO ENABLE USER INPUT
    /* for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
        {
            cout << "Enter entry for column " << (char)('A'+i) << " and row " << (char)('P'+j) <<":";
            cin >> board[i][j];
        } */

    //THIS GENERATE RANDOM NUMBERS FOR ENTRIES
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
             board[i][j] = rand() % 9 + 1;

    //Interactive loop
    while (input != "quit") {
        if (input == "show" || input == "") {
            char horizontalLetters = 'A';
            char verticalLetters = 'P';
            // displaying board
            cout << "  ";
            for (int k = 0; k < 9; ++k)
                cout << horizontalLetters++ << " ";
            cout << endl;

            for (int i = 0; i < 9; ++i) {
                cout << verticalLetters++ << " ";
                for (int j = 0; j < 9; ++j)
                    (board[i][j] != -1) ? cout << board[i][j] << " " : cout << "-" << " ";
                cout << endl;

            }
            cin >> input;
        }

        else if (input == "swap")
        {
            short rowOrColumn = rand() % 10, whichLetter1 = rand() % 10, whichLetter2 = rand() % 10, temp;

            if (rowOrColumn%2 == 0) // randomly select whether to swap rows and columns
            {
                //swap rows
                cout << "Trying to swap rows " << (char)('A'+whichLetter1) << " and " << (char)('A'+whichLetter2) << endl;
                for (int i = 0; i < 9; ++i)
                {
                    temp = board[whichLetter1][i];
                    board[whichLetter1][i] = board[whichLetter2][i];
                    board[whichLetter2][i] = temp;
                }
                cin >> input;
            } else
            {
                //swap columns
                cout << "Trying to swap columns " << (char)('P'+whichLetter1) << " and " << (char)('P'+whichLetter2) << endl;

                for (int i = 0; i < 9; ++i)
                {
                    temp = board[i][whichLetter1];
                    board[i][whichLetter1] = board[i][whichLetter2];
                    board[i][whichLetter2] = temp;
                }
                cin >> input;
            }
        }

        else if (input == "erase")
        {
            short coordinate1 = rand() % 10, coordinate2 = rand() % 10;
            cout << "Trying to erase row " << (char)('p'+coordinate1) << " and column " << (char)('A'+coordinate2) << endl;
            board[coordinate1][coordinate2] = -1;
            cin >> input;
        }

        else if ( input == "verify")
        {
            short sum = 0;
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j)
                    sum += board[i][j];
                if (sum != 45)
                    cout << "inconsistency in row " << i+1 << endl;
                sum = 0;
            }

                for (int i = 0; i < 9; ++i) {
                    for (int j = 0; j < 9; ++j)
                        sum += board[j][i];
                    if (sum != 45)
                        cout << "inconsistency in column " << i+1 << endl;
                }
            cin >> input;
            }
        }

    cout << "Bye..." << endl;

    return 0;
}

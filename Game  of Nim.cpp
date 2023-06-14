#include <iostream>
using namespace std;

bool isValidMove(int userMove, int stones) {
    return !(userMove < 1 || userMove>3 || userMove >= stones);
}

int computerMove(int stones) {
    if (stones == 1) {
        return 1;
    }
    else if (stones <=4) {
        return stones - 1;
    }
    else {
        return rand() % 3 + 1;
    }

}

bool checkWin(int stones) {
    return stones <= 1;
}

int main()
{
    srand(time(0));
    int stones = rand () % 21 + 10;
    int userAnswer, computerTurn;
    while (true) {
        cout << "Stones in the pile: " << stones<<endl;
        if (checkWin(stones)) {
            cout << "You lose!";
            break;
        }
        cout << "How many will you take (1-3)? ";
        cin >> userAnswer;
        if (isValidMove(userAnswer, stones)) {
            stones -= userAnswer;
            if (checkWin(stones)) {
                cout << "Stones in the pile: " << stones << endl;
                cout << "You win!";
                break;
            }
            computerTurn = computerMove(stones);
            cout << "Computer takes " << computerTurn<< endl;
            stones -= computerTurn;
        }
        else {
            cout << "That is not a valid amount."<< endl;
        }
    }
}


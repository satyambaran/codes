#include<bits/stdc++.h>
using namespace std;
#define int long long

class Game {
public:
    vector<int> playerList;
    int lastPlayed = -1;
    int totalPlayer;
    vector<int> playerNames;
    vector<string>gameStatusArray = { "yet_to_start", "playing", "finished" };
    int gameStatus = 0;
    int boardSize;
    int dice;
    Game(int height, int width, int _totalPlayer, int _dice) {
        boardSize = height*width;
        totalPlayer = _totalPlayer;
        dice = _dice;
    }
    int rollDice() {
        return rand() % (dice)+1;
    }
};
class Dice {

};
int32_t main() {
    srand(time(0));
    return 0;
}



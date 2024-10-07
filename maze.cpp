#include <iostream>
#include <vector>

using namespace std;

const char WALL = '#';
const char PATH = ' ';
const char PLAYER = 'P';
const char EXIT = 'E';

// Maze layout: 1 = Wall, 0 = Path
vector<vector<int>> maze = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
};

void printPlayerPosition(int playerX, int playerY) {
    cout << "Player is now at (" << playerX << ", " << playerY << ")." << endl;
}

// Function to check if the move is valid
bool isValidMove(int x, int y) {
    return (x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 0);
}

int main() {
    int playerX = 1, playerY = 1; // Player starts at (1, 1)
    int exitX = 6, exitY = 6;     // Exit is at (6, 6)
    vector<pair<int, int>> path;  // Store player's movement path

    cout << "Welcome to the Maze Game!" << endl;
    cout << "Navigate to the exit (E) at 6,6 using w (up), a (left), s (down), d (right)." << endl;
    cout << "You start at position (1, 1)." << endl;

    // Print initial player position
    printPlayerPosition(playerX, playerY);

    while (true) {
        char move;
        cout << "Enter your move (WASD): ";
        cin >> move;

        int newX = playerX;
        int newY = playerY;

        // Determine new position based on input
        switch (move) {
            case 'w': newX--; break; // Move up
            case 'a': newY--; break; // Move left
            case 's': newX++; break; // Move down
            case 'd': newY++; break; // Move right
            default:
                cout << "Invalid move! Use W, A, S, D." << endl;
                continue;
        }

        // Check if move is valid
        if (isValidMove(newX, newY)) {
            playerX = newX;
            playerY = newY;
            path.push_back({playerX, playerY});
            printPlayerPosition(playerX, playerY);
        } else {
            cout << "Invalid move! You hit a wall. Try again." << endl;
        }

        // Check if player reached the exit
        if (playerX == exitX && playerY == exitY) {
            cout << "Congratulations! You've found the exit!" << endl;
            break;
        }
    }

    // Print the player's path
    cout << "Your path through the maze: ";
    for (const auto& pos : path) {
        cout << "(" << pos.first << ", " << pos.second << ") ";
    }
    cout << endl;

    return 0;
}

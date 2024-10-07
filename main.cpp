#include <iostream>
#include <random>
using namespace std;

int fibonacciTree(int n, int depth = 0) {
    // Base case
    if (n <= 2) {
        for (int i = 0; i < depth; ++i) {
            cout << "  ";
        }
        cout << "fibonacci(" << n << ") " << n << endl;
        return n;
    }

    // Recursive calls with increased depth
    int fib1 = fibonacciTree(n - 1, depth + 1);
    int fib2 = fibonacciTree(n - 2, depth + 1);

    for (int i = 0; i < depth; ++i) {
        cout << "  ";
    }
    cout << "fibonacci(" << n << ") " << fib1 + fib2 << endl;

    return fib1 + fib2;
}

void montyHall() {
    // Monty Hall problem
    int choice;
    cout << "Monty Hall Problem" << endl;
    cout << "Choose a door (1, 2, or 3): ";
    cin >> choice;
    int car = rand() % 3 + 1;
    // Reveal a door with a goat
    int reveal;
    do {
        reveal = rand() % 3 + 1;
    } while (reveal == car || reveal == choice);
    cout << "There is a goat behind door " << reveal << "!" << endl;
    // Give the option to switch doors
    char answer;
    cout << "Do you want to switch doors? (y/n): ";
    cin >> answer;
    if (answer == 'y') {
        // Switch the door
        int newChoice;
        do {
            newChoice = rand() % 3 + 1;
        } while (newChoice == choice || newChoice == reveal);
        choice = newChoice;
    }
    // Reveal the final choice
    cout << "You chose door " << choice << "." << endl;
    if (choice == car) {
        cout << "Congratulations! There is a car behind door " << car << "!" << endl;
    } else {
        cout << "Sorry, there is a goat behind door " << car << "." << endl;
    }
}

int main() {
    int n;
    cout << "Would you like to play the monte hall game or the fibonacci game? (1/2): ";
    cin >> n;
    if (n == 1) {
        montyHall();
    } else if (n == 2) {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << "Fibonacci number at position " << num << " is " << fibonacciTree(num) << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }
    return 0;
}
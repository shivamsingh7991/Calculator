#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));
    
    int secretNumber = rand() % 100 + 1;
    
    int guess;
    int attempts = 0;
    
    while (true) {
        cout << "Guess the number (between 1 and 100): ";
        cin >> guess;
        
        attempts++;
        
        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts." << std::endl;
            break;
        } else if (guess < secretNumber) {
            cout << "Too low. Try again." << std::endl;
        } else {
            cout << "Too high. Try again." << std::endl;
        }
    }
    
    return 0;
}
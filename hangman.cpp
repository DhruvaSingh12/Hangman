#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x) * 1000)
#endif

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printHangman(int incorrectGuesses) {
    switch (incorrectGuesses) {
        case 0:
            cout << " _____\n";
            cout << "|    |\n";
            cout << "|\n";
            cout << "|\n";
            cout << "|\n";
            cout << "|_____\n";
            break;
        case 1:
            cout << " _____\n";
            cout << "|    |\n";
            cout << "|    O\n";
            cout << "|\n";
            cout << "|\n";
            cout << "|_____\n";
            break;
        case 2:
            cout << " _____\n";
            cout << "|    |\n";
            cout << "|    O\n";
            cout << "|    |\n";
            cout << "|\n";
            cout << "|_____\n";
            break;
        case 3:
            cout << " _____\n";
            cout << "|    |\n";
            cout << "|    O\n";
            cout << "|   /|\n";
            cout << "|\n";
            cout << "|_____\n";
            break;
        case 4:
            cout << " _____\n";
            cout << "|    |\n";
            cout << "|    O\n";
            cout << "|   /|\\ \n";
            cout << "|\n";
            cout << "|_____\n";
            break;
        case 5:
            cout << " _____\n";
            cout << "|    |\n";
            cout << "|    O\n";
            cout << "|   /|\\ \n";
            cout << "|   / \n";
            cout << "|_____\n";
            break;
        case 6:
            cout << " _____\n";
            cout << "|    |\n";
            cout << "|    O\n";
            cout << "|   /|\\ \n";
            cout << "|   / \\ \n";
            cout << "|_____\n";
            break;
    }
}

void displayWord(const string& word, const vector<bool>& guessedLetters) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (guessedLetters[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    const vector<string> periodicTable = {
        "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen",
        "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur",
        "Chlorine", "Argon", "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium",
        "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium", "Germanium", "Arsenic",
        "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium",
        "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium",
        "Tin", "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium",
        "Praseodymium", "Neodymium", "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium",
        "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium", "Tantalum",
        "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury", "Thallium", "Lead",
        "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium", "Protactinium",
        "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium",
        "Fermium", "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium",
        "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium",
        "Livermorium", "Tennessine", "Oganesson"
    };

    int totalElements = periodicTable.size();
    int totalScore = 0;
    int remainingLives = 10;

    while (totalScore < totalElements && remainingLives > 0) {
        int randomIndex = rand() % totalElements;
        string currentElement = periodicTable[randomIndex];
        int elementLength = currentElement.length();
        
        vector<bool> guessedLetters(elementLength, false);
        int incorrectGuesses = 0;

        cout << "Guess the element (";
        cout << "Atomic Number: " << randomIndex + 1 << "):" << endl;
        Sleep(3000); 

        while (incorrectGuesses < 6) {
            clearScreen(); 

            displayWord(currentElement, guessedLetters);

            cout << "Incorrect Guesses Remaining: " << 6 - incorrectGuesses << endl;
            cout << "Remaining Lives: " << remainingLives << endl;
            cout << "Total Score: " << totalScore << "/" << totalElements << endl;

            printHangman(incorrectGuesses);

            char guess;
            cout << "Enter a letter: ";
            cin >> guess;

            bool found = false;
            for (int i = 0; i < elementLength; ++i) {
                if (tolower(currentElement[i]) == tolower(guess)) {
                    guessedLetters[i] = true;
                    found = true;
                }
            }

            if (!found) {
                ++incorrectGuesses;
            }

            if (count(guessedLetters.begin(), guessedLetters.end(), true) == elementLength) {
                cout << "Congratulations! You guessed the element: " << currentElement << endl;
                ++totalScore;
                Sleep(1500); 
                break;
            }
        }

        if (incorrectGuesses == 6) {
            cout << "Sorry! You couldn't guess the element. The correct element was: " << currentElement << endl;
            --remainingLives;
            Sleep(1500); 
        }
    }

    if (remainingLives == 0) {
        cout << "Game Over! You ran out of lives. Your final score is: " << totalScore << "/" << totalElements << endl;
    } else {
        cout << "Congratulations! You guessed all elements. Your final score is: " << totalScore << "/" << totalElements << endl;
    }

    return 0;
}

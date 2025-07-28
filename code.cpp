#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <iomanip>
using namespace std;

// ANSI color codes for better visual appeal
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string BOLD = "\033[1m";
const string RESET = "\033[0m";

struct GameStats {
    int gamesPlayed = 0;
    int gamesWon = 0;
    int totalGuesses = 0;
};

string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

bool word_check(const string& inputWord, const string& targetWord) {
    return toLower(inputWord) == toLower(targetWord);
}

void displayHangman(int wrongGuesses) {
    cout << CYAN << "\n";
    switch (wrongGuesses) {
        case 0:
            cout << "   +---+\n";
            cout << "   |   |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "=========\n";
            break;
        case 1:
            cout << "   +---+\n";
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "=========\n";
            break;
        case 2:
            cout << "   +---+\n";
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "   |   |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "=========\n";
            break;
        case 3:
            cout << "   +---+\n";
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "  /|   |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "=========\n";
            break;
        case 4:
            cout << "   +---+\n";
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "  /|\\  |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "=========\n";
            break;
        case 5:
            cout << "   +---+\n";
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "  /|\\  |\n";
            cout << "  /    |\n";
            cout << "       |\n";
            cout << "=========\n";
            break;
        case 6:
            cout << RED;
            cout << "   +---+\n";
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "  /|\\  |\n";
            cout << "  / \\  |\n";
            cout << "       |\n";
            cout << "=========\n";
            cout << "  GAME OVER!\n";
            break;
    }
    cout << RESET;
}

void displayTitle() {
    cout << BOLD << MAGENTA;
    cout << "\n";
    cout << "██╗  ██╗ █████╗ ███╗   ██╗ ██████╗ ███╗   ███╗ █████╗ ███╗   ██╗\n";
    cout << "██║  ██║██╔══██╗████╗  ██║██╔════╝ ████╗ ████║██╔══██╗████╗  ██║\n";
    cout << "███████║███████║██╔██╗ ██║██║  ███╗██╔████╔██║███████║██╔██╗ ██║\n";
    cout << "██╔══██║██╔══██║██║╚██╗██║██║   ██║██║╚██╔╝██║██╔══██║██║╚██╗██║\n";
    cout << "██║  ██║██║  ██║██║ ╚████║╚██████╔╝██║ ╚═╝ ██║██║  ██║██║ ╚████║\n";
    cout << "╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝\n";
    cout << RESET;
    cout << YELLOW << "\n          🎮 Welcome to the Ultimate Hangman Experience! 🎮\n" << RESET;
}

vector<string> getWordsByDifficulty(int difficulty) {
    vector<string> easyWords = {
        "Cat", "Dog", "Sun", "Moon", "Book", "Tree", "Fish", "Bird", "Star", "Rock"
    };
    vector<string> mediumWords = {
        "Elephant", "Banana", "Computer", "Guitar", "Science", "Mountain", 
        "Library", "Keyboard", "Rainbow", "Dragon"
    };
    vector<string> hardWords = {
        "Programming", "Algorithm", "Metaphysical", "Extraordinary", "Philosophical",
        "Championship", "Revolutionary", "Mediterranean", "Incomprehensible", "Sophisticated"
    };
    
    switch (difficulty) {
        case 1: return easyWords;
        case 2: return mediumWords;
        case 3: return hardWords;
        default: return mediumWords;
    }
}

string selectRandomWord(int difficulty) {
    vector<string> words = getWordsByDifficulty(difficulty);
    srand(static_cast<unsigned int>(time(nullptr)));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

void displayGuessedWord(const string& guessedWord) {
    cout << BOLD << GREEN << "Word: ";
    for (size_t i = 0; i < guessedWord.length(); ++i) {
        cout << guessedWord[i];
        if (i < guessedWord.length() - 1) cout << " ";
    }
    cout << RESET << endl;
}

void displayGuessedLetters(const set<char>& guessedLetters) {
    if (!guessedLetters.empty()) {
        cout << YELLOW << "Guessed letters: ";
        for (char c : guessedLetters) {
            cout << static_cast<char>(toupper(c)) << " ";
        }
        cout << RESET << endl;
    }
}

int chooseDifficulty() {
    int difficulty;
    cout << CYAN << "\n🎯 Choose your difficulty level:\n" << RESET;
    cout << GREEN << "1. 😊 Easy (3-4 letters, 8 tries)\n" << RESET;
    cout << YELLOW << "2. 😐 Medium (5-8 letters, 7 tries)\n" << RESET;
    cout << RED << "3. 😤 Hard (9+ letters, 6 tries)\n" << RESET;
    cout << "Enter your choice (1-3): ";
    
    while (!(cin >> difficulty) || difficulty < 1 || difficulty > 3) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << RED << "Invalid input! Please enter 1, 2, or 3: " << RESET;
    }
    return difficulty;
}

int getMaxTries(int difficulty) {
    switch (difficulty) {
        case 1: return 8;  // Easy
        case 2: return 7;  // Medium
        case 3: return 6;  // Hard
        default: return 7;
    }
}

void displayStats(const GameStats& stats) {
    if (stats.gamesPlayed > 0) {
        cout << BLUE << "\n📊 Your Statistics:\n" << RESET;
        cout << "Games played: " << stats.gamesPlayed << endl;
        cout << "Games won: " << stats.gamesWon << endl;
        cout << "Win rate: " << fixed << setprecision(1) 
             << (double)stats.gamesWon / stats.gamesPlayed * 100 << "%" << endl;
        cout << "Average guesses per game: " << fixed << setprecision(1)
             << (double)stats.totalGuesses / stats.gamesPlayed << endl;
    }
}

void showHint(const string& word, const string& guessedWord) {
    // Count revealed letters
    int revealed = 0;
    for (char c : guessedWord) {
        if (c != '_') revealed++;
    }
    
    // Only give hint if less than half the word is revealed
    if (revealed < word.length() / 2) {
        cout << YELLOW << "💡 Hint: This word has " << word.length() 
             << " letters and starts with '" << word[0] << "'" << RESET << endl;
    } else {
        cout << YELLOW << "💡 You're doing great! Keep going!" << RESET << endl;
    }
}

int main() {
    displayTitle();
    
    GameStats stats;
    char playAgain;
    
    do {
        int difficulty = chooseDifficulty();
        string randomWord = selectRandomWord(difficulty);
        string randomWordLower = toLower(randomWord);
        int maxTries = getMaxTries(difficulty);
        int tries = maxTries;
        int wrongGuesses = 0;
        int guessCount = 0;
        
        cout << GREEN << "\n🎯 Game started! You have " << tries << " tries.\n" << RESET;
        cout << BLUE << "💡 Choose option 3 anytime to get a hint!\n" << RESET;
        
        int option;
        string wordGuess;
        string letterInput;
        char letter;
        string guessedWord(randomWord.length(), '_');
        set<char> guessedLetters;
        
        while (tries > 0 && wrongGuesses < 6) {
            cout << "\n" << string(50, '=') << "\n";
            displayHangman(wrongGuesses);
            cout << BOLD << RED << "Tries left: " << tries << RESET << endl;
            displayGuessedWord(guessedWord);
            displayGuessedLetters(guessedLetters);
            
            cout << CYAN << "\n🎮 What would you like to do?\n" << RESET;
            cout << "1. 🎯 Guess the entire word\n";
            cout << "2. 🔤 Guess a letter\n";
            cout << "3. 💡 Get a hint\n";
            cout << "Enter option (1-3): ";
            
            if (!(cin >> option)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << RED << "Invalid input. Try again.\n" << RESET;
                continue;
            }
            
            guessCount++;
            
            switch (option) {
                case 1: {
                    cout << "Enter your word guess: ";
                    cin >> wordGuess;
                    if (word_check(wordGuess, randomWord)) {
                        cout << GREEN << "🎉 Congratulations! You guessed the word correctly!" << RESET << endl;
                        guessedWord = randomWord;
                        tries = 0;
                        stats.gamesWon++;
                    } else {
                        cout << RED << "❌ Wrong guess!" << RESET << endl;
                        tries--;
                        wrongGuesses++;
                    }
                    break;
                }
                case 2: {
                    cout << "Enter a letter: ";
                    cin >> letterInput;
                    
                    if (letterInput.length() != 1) {
                        cout << RED << "Please enter only one letter!" << RESET << endl;
                        guessCount--;
                        break;
                    }
                    
                    letter = tolower(letterInput[0]);
                    
                    if (!isalpha(letter)) {
                        cout << RED << "Please enter a valid letter!" << RESET << endl;
                        guessCount--;
                        break;
                    }
                    
                    if (guessedLetters.count(letter)) {
                        cout << YELLOW << "⚠️  You already guessed that letter!" << RESET << endl;
                        guessCount--;
                        break;
                    }
                    
                    guessedLetters.insert(letter);
                    bool found = false;
                    
                    for (size_t i = 0; i < randomWordLower.length(); ++i) {
                        if (randomWordLower[i] == letter) {
                            guessedWord[i] = randomWord[i];
                            found = true;
                        }
                    }
                    
                    if (found) {
                        cout << GREEN << "✅ Correct guess!" << RESET << endl;
                    } else {
                        cout << RED << "❌ Incorrect guess!" << RESET << endl;
                        tries--;
                        wrongGuesses++;
                    }
                    break;
                }
                case 3: {
                    showHint(randomWord, guessedWord);
                    guessCount--; // Don't count hint as a guess
                    break;
                }
                default:
                    cout << RED << "Invalid option. Please enter 1, 2, or 3." << RESET << endl;
                    guessCount--;
                    break;
            }
            
            // Check if word is complete
            if (guessedWord.find('_') == string::npos) {
                cout << "\n" << string(50, '=') << "\n";
                cout << GREEN << BOLD;
                cout << "🎉🎉🎉 CONGRATULATIONS! 🎉🎉🎉\n";
                cout << "You successfully completed the word!\n";
                cout << RESET;
                displayGuessedWord(guessedWord);
                stats.gamesWon++;
                break;
            }
        }
        
        stats.gamesPlayed++;
        stats.totalGuesses += guessCount;
        
        if (guessedWord.find('_') != string::npos && wrongGuesses >= 6) {
            displayHangman(6);
            cout << RED << BOLD << "\n💀 GAME OVER! 💀\n" << RESET;
            cout << "You ran out of tries!\n";
        }
        
        cout << YELLOW << "The word was: " << BOLD << randomWord << RESET << endl;
        cout << "You made " << guessCount << " guesses.\n";
        
        displayStats(stats);
        
        cout << CYAN << "\n🎮 Would you like to play again? (y/n): " << RESET;
        cin >> playAgain;
        
    } while (tolower(playAgain) == 'y');
    
    cout << MAGENTA << BOLD;
    cout << "\n🎮 Thanks for playing Hangman! 🎮\n";
    cout << "Hope you had fun! Come back anytime! 👋\n";
    cout << RESET;
    
    displayStats(stats);
    
    return 0;
}

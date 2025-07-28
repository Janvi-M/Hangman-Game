# Enhanced Hangman Game

A modern, feature-rich C++ implementation of the classic Hangman word-guessing game with ASCII art, multiple difficulty levels, and comprehensive statistics tracking.

## Features

- Visual ASCII Art: Beautiful hangman drawings and colorful interface
- 3 Difficulty Levels: Easy (8 tries), Medium (7 tries), Hard (6 tries)
- Hint System: Get helpful clues without penalty
- Statistics Tracking: Win rate, games played, average guesses
- Replay Option: Play multiple rounds without restarting
- Colorful UI: ANSI colors for better visual experience
- Smart Validation: Robust input handling and error prevention

## How to Play

1. Choose Difficulty: Select Easy, Medium, or Hard
2. Guess Strategy: 
   - Option 1: Guess the entire word
   - Option 2: Guess individual letters
   - Option 3: Get a hint (free!)
3. Win Condition: Complete the word before running out of tries
4. Avoid the Gallows: Each wrong guess adds to the hangman drawing

## Quick Start

### Compile & Run
```bash
g++ -o hangman hangman.cpp
./hangman
```

### Requirements
- C++ compiler (g++, clang++, etc.)
- Terminal with ANSI color support (most modern terminals)

## Difficulty Levels

| Level | Word Length | Max Tries | Examples |
|-------|-------------|-----------|----------|
| Easy | 3-4 letters | 8 tries | Cat, Dog, Sun |
| Medium | 5-8 letters | 7 tries | Computer, Guitar |
| Hard | 9+ letters | 6 tries | Programming, Algorithm |

## Game Statistics

Track your performance with:
- Total games played
- Games won
- Win percentage
- Average guesses per game

## Features Showcase

- Progressive Hangman Art: 7 stages from empty gallows to game over
- Color-Coded Feedback: Green for success, red for errors, yellow for warnings
- Input Validation: Prevents invalid inputs and duplicate guesses



Enjoy playing!

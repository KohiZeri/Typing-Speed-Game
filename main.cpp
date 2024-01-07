// Programmed by: Sean Wei
// Programmed for: Summative
// Programmed on: 2023-06-02

#include <iostream>
#include <fstream>
#include <chrono>
#include "conio.h"
#include <random>
#include <cmath>

// https://stackoverflow.com/questions/42973749/need-help-creating-typing-speed-game-with-time
// https://stackoverflow.com/questions/57327896/dividing-and-multiplying-stdchronodurations
// https://www.ef.com/ca/english-resources/english-vocabulary/top-100-words/

using namespace std;
using namespace chrono;

// Declare global variable
string array[100];

/*
* This function will output the introduction to the 
* program and the menu.
*/

void printInstruction(){
  system("clear");
  cout << "**********************************************************************";
  cout << "\n";
  cout << "\n" << "                       TYPING SPEED GAME IN C++";
  cout << "\n";
  cout << "\n**********************************************************************" << endl;
  cout << "Press TAB to restart" << endl;
  cout << "Press ENTER to end" << endl;
}

/*
* This function is used to store a list of words in 
* a file into an array.
*/

void populateStringArray(){
  // Read and write from a file
  ifstream file;
  ofstream fileIn;

  // Declare variable
  int lineNumber = 0;
  
  // Open file
  // Run until end of the file
  // Designate words to an array
  // Close file
  file.open("Random Words.txt");
  while(!file.eof()){
    file >> array[lineNumber];
    lineNumber++;
  }
  file.close();
}



int main() {

  // Declare variables
  string sentences = ""; 
  double wpm;
  int length, wordsInSentence, runOnce = 0, wpmAggregate = 0;
  char userTyping;
  float letters = 0.0, wordCounter = 0.0;
  bool stopEndless = false, tabPress = false, enterPress = false, timerStart = true, backspacePress = false;

  // Call functions
  printInstruction();
  populateStringArray();

  auto timeStart = steady_clock::now();
  // Use while loop to continuously run block of code
  while(stopEndless == false){

    // Limit words printed out
    // Randomize index to get random words
    // Append words to sentences
    sentences = "";
    wordsInSentence = 10;
    for (int i = 0; i < wordsInSentence; i++){
      int wordIndex = rand() % 100;

      // Check for first word
      if (i == 0){
        sentences.append(array[wordIndex]);

      // If not the first word put a space before it
      }else{
        sentences.append(" ");
        sentences.append(array[wordIndex]);
      }
    }

    // Get sentence length
    length = sentences.length();

    // Print sentence
    if (runOnce == 0){
      cout << sentences << endl;
      runOnce = 1 ;
    }else{
      cout << "\n";
      cout << sentences << endl;
    }

    letters = 0;
    
    // Runs until the end of sentences
    for (int j = 0; j < length; j++){      

      // Detects character input without buffers
      userTyping = getch();

      // Start timer when code detects user input
      if (timerStart == true){
        timeStart = steady_clock::now();
        timerStart = false;
      }

      // Check ASCII value for BACKSPACE
      // Go back 1 character
      // Dont allow characters to be negative
      // Subtract 1 from character counter to reset counter
      if (userTyping == 127){
        j -= 2;
        cout << "\b";

        backspacePress = true;
        if (letters>0){
          letters -= 1;
        }

      }else{
        backspacePress = false;
      }

      // Check ASCII value for ENTER
      // Stop both while andD for loop once Enter is detected
      if (userTyping == 10){
        enterPress = true;
        stopEndless = true;
        break;
      }

      // Check ASCII value for TAB
      // Reset each counter
      // Ouput program header again
      // Reset timer
      // Stop for loop
      if (userTyping == 9){
        timerStart = true;
        wordCounter = 0.0;
        runOnce = 0;
        letters = 0;
        wpmAggregate = 0;
        tabPress = true;
        printInstruction();
        break;
      }

      // Check if characters in getch() are correct
      // Output bolded text
      if (sentences[j] == userTyping){ 
        cout << "\e[1m" << sentences[j] << "\e[0m";

        // Check ASCII value for SPACE
        // Count words
        if (userTyping == 32 || j == length - 1){
          wordCounter+=1.0;
        }
        
      // Output red text 
      }else{
        cout << "\x1b[31m" << userTyping << "\x1b[0m";
      }

      // Count each correct charcter inputed
      if (backspacePress == false){
        letters++;
      }
    }

    // Keeps running until user presses TAB
    if (tabPress == false){
      cout << "\n";
    }

    // Update value in wpmAggregate
    wpmAggregate = wpmAggregate + letters;
  }

  // End timer
  auto timeEnd = steady_clock::now();

  // Calculate wpm
  wpm = wordCounter/(((timeEnd - timeStart).count()/1000000000.0)/seconds(60).count());

  // Output user stats
  cout << "\nTYPING STATS" << endl;
  cout << "\nTotal words   : " << wordCounter << endl;
  cout << "Total letters : " << wpmAggregate << endl;
  cout << "Total time    : " << (timeEnd - timeStart).count()/1000000000 << "s" << endl;
  cout << "Words/minute  : " << round(wpm) << endl;
}

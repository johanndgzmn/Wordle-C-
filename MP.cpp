#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int difficultyPicker() // Picks a difficulty
{
    int chosenDiff;
    bool diffCheck = false;
    cout << "Wordle in C++" << endl;
    cout << "WWWWWWWW                           WWWWWWWW                                              d::::::dlllllll                            iiii                                CCCCCCCCCCCCC                                          "<<endl; //fancy wordle title lmao
    cout << "W::::::W                           W::::::W                                              d::::::dl:::::l                           i::::i                            CCC::::::::::::C                                          "<<endl;
    cout << "W::::::W                           W::::::W                                              d::::::dl:::::l                            iiii                           CC:::::::::::::::C                                          "<<endl;
    cout << "W::::::W                           W::::::W                                              d:::::d l:::::l                                                          C:::::CCCCCCCC::::C       +++++++              +++++++       "<<endl;
    cout << " W:::::W           WWWWW           W:::::W ooooooooooo   rrrrr   rrrrrrrrr       ddddddddd:::::d  l::::l     eeeeeeeeeeee         iiiiiiinnnn  nnnnnnnn          C:::::C       CCCCCC       +:::::+              +:::::+       "<<endl;
    cout << "  W:::::W         W:::::W         W:::::Woo:::::::::::oo r::::rrr:::::::::r    dd::::::::::::::d  l::::l   ee::::::::::::ee       i:::::in:::nn::::::::nn       C:::::C                     +:::::+              +:::::+       "<<endl;
    cout << "   W:::::W       W:::::::W       W:::::Wo:::::::::::::::or:::::::::::::::::r  d::::::::::::::::d  l::::l  e::::::eeeee:::::ee      i::::in::::::::::::::nn      C:::::C               +++++++:::::+++++++  +++++++:::::+++++++ "<<endl;
    cout << "    W:::::W     W:::::::::W     W:::::W o:::::ooooo:::::orr::::::rrrrr::::::rd:::::::ddddd:::::d  l::::l e::::::e     e:::::e      i::::inn:::::::::::::::n     C:::::C               +:::::::::::::::::+  +:::::::::::::::::+ "<<endl;
    cout << "     W:::::W   W:::::W:::::W   W:::::W  o::::o     o::::o r:::::r     r:::::rd::::::d    d:::::d  l::::l e:::::::eeeee::::::e      i::::i  n:::::nnnn:::::n     C:::::C               +:::::::::::::::::+  +:::::::::::::::::+ "<<endl;
    cout << "      W:::::W W:::::W W:::::W W:::::W   o::::o     o::::o r:::::r     rrrrrrrd:::::d     d:::::d  l::::l e:::::::::::::::::e       i::::i  n::::n    n::::n     C:::::C               +++++++:::::+++++++  +++++++:::::+++++++ "<<endl;
    cout << "       W:::::W:::::W   W:::::W:::::W    o::::o     o::::o r:::::r            d:::::d     d:::::d  l::::l e::::::eeeeeeeeeee        i::::i  n::::n    n::::n     C:::::C                     +:::::+              +:::::+       "<<endl;
    cout << "        W:::::::::W     W:::::::::W     o::::o     o::::o r:::::r            d:::::d     d:::::d  l::::l e:::::::e                 i::::i  n::::n    n::::n      C:::::C       CCCCCC       +:::::+              +:::::+       "<<endl;
    cout << "         W:::::::W       W:::::::W      o:::::ooooo:::::o r:::::r            d::::::ddddd::::::ddl::::::le::::::::e               i::::::i n::::n    n::::n       C:::::CCCCCCCC::::C       +++++++              +++++++       "<<endl;
    cout << "          W:::::W         W:::::W       o:::::::::::::::o r:::::r             d:::::::::::::::::dl::::::l e::::::::eeeeeeee       i::::::i n::::n    n::::n        CC:::::::::::::::C                                          "<<endl;
    cout << "           W:::W           W:::W         oo:::::::::::oo  r:::::r              d:::::::::ddd::::dl::::::l  ee:::::::::::::e       i::::::i n::::n    n::::n          CCC::::::::::::C                                          "<<endl;
    cout << "            WWW             WWW            ooooooooooo    rrrrrrr               ddddddddd   dddddllllllll    eeeeeeeeeeeeee       iiiiiiii nnnnnn    nnnnnn             CCCCCCCCCCCCC                                          "<<endl;
    cout << endl << "Here is your guide for the word verification: "<<endl;
    cout << "C - The letter is in the correct place." << endl;
    cout << "? - The letter is in the word but not in the correct place." << endl;
    cout << "X - The letter is not in the word." << endl;
    cout << endl << "1: Easy" << endl;
    cout << "2: Medium" << endl;
    cout << "3: Hard" << endl;
    cout << "4: Expert" << endl;
    while(diffCheck != true)
    {
        cout << "Enter chosen difficulty(1-4): ";
        cin >> chosenDiff;
        if(chosenDiff > 4 || chosenDiff < 1)
        {
            cout << "\n" << "You entered an invalid number. Please try again." << endl;
        }
        else
        {
            diffCheck = true;
        }
    }
    return chosenDiff;
}

string wordList(int diffPick) //Picks a word
{
    string easyWord[5] = {"THREE", "NIGHT", "DAILY", "SNIPE", "TODAY"};
    string mediumWord[5] = {"HERON", "PLUCK", "MADAM", "ATONE", "CACAO"};
    string hardWord[5] = {"LILAC", "PIETY", "PRIMO", "FARCE", "SAUTE"};
    string expertWord[5] = {"EGRET", "AGAPE", "BAYOU", "OXIDE", "NATAL"};
    int wordPick;
    string wordGuess;
    bool pickCheck = false;
    while(pickCheck != true)
    {
        cout << "Pick a number from 1-5: ";
        cin >> wordPick;
        if(wordPick > 5 || wordPick < 1)
        {
            cout << "\n" << "You entered an invalid number. Please try again." << endl;
        }
        else
        {
            wordPick--;
            pickCheck = true;
        }
    }

    switch(diffPick)
    {
        case 1:
            wordGuess = easyWord[wordPick];
            break;
        case 2:
            wordGuess = mediumWord[wordPick];
            break;
        case 3:
            wordGuess = hardWord[wordPick];
            break;
        case 4:
            wordGuess = expertWord[wordPick];
            break;
    }
    return wordGuess;
}

bool wordComparison(string userInput, string wordtoGuess) //Checks if the user input is equal to the unknown word
{
    transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
    char extractCharGuess[5];
    char userInputAnswer[5];
    char answerState[5];

    for(int i=0; i < 5; i++) //Extracts individual character of the unknown word
    {
        extractCharGuess[i] = wordtoGuess.at(i); 
    }

    for(int j=0; j < 5; j++) //Extracts individual character of the user input
    {
        userInputAnswer[j] = userInput.at(j); 
    }
    
    for(int i=0; i < 5; i++)
    {
        for(int j=0; j < 5; j++)
        {
            switch (answerState[i])
            {
            case 'C':
                break;
        
            default:
                if (userInputAnswer[i]==extractCharGuess[j] && i==j) //Correct position
                {
                    answerState[i]='C';
                    j = 5;
                }
                else if (userInputAnswer[i]==extractCharGuess[j]) //In the word but not in the right position
                {
                    answerState[i]='?';
                }
                else if (answerState [i] == '?');
                else //Not in the word
                {
                    answerState[i]='X';
                }
                break;
            }
        }
    }

    for(int i=0; i<5; i++) //Shows the places of the letter to the word to guess
    {
        cout << answerState[i];
    }
    cout<<endl;
    for(int i=0; i<5; i++) // Outputs user input
    {
        cout << userInputAnswer[i];
    }
    bool ansCheck = true;
    for(int i=0; i<5; i++) //Checks if the user input is correct
    {
        if (answerState[i]=='C');
        else
        {
            ansCheck = false;
        }
        
    }
    cout<<endl;
    return ansCheck;
}

int main()
{
    string endGame;
    while(endGame != "N" && endGame != "n")
    {
        endGame = ".";
        int chosenDiff;
        string wordtoGuess;
        chosenDiff = difficultyPicker();
        wordtoGuess = wordList(chosenDiff);
        int attemptsLeft = 6;
        bool answerCheck = false;

        ifstream inputFile("wordlist.dat");
        string dictionary[5757];
        string userInput;
        int size = 5757;
        bool validityCheck = false;
        for(int i=0; i < size; i++) // Assigns dictionary file to array
        {
            inputFile >> dictionary[i];
        }
        inputFile.close();
            
        while(attemptsLeft != 0)
        {
            while(validityCheck != true) //Checks if the word is in the dictionary
            {
                cout << "\n" << "Enter a 5 letter word: ";
                cin >> userInput;
                transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
                for(int n = 0; n < size; n++)
                {
                    if(userInput == dictionary[n])
                    {
                        validityCheck = true;
                    }
                }
                if(validityCheck != true)
                {
                    cout << "\n" << "The word you entered is not in the dictionary. Please try again." << endl; 
                }
            }
            validityCheck = false;
            answerCheck = wordComparison(userInput, wordtoGuess);
            if(answerCheck == false)
            {
                attemptsLeft--;
                cout << endl << "You have " << attemptsLeft << " attempts left." << endl;
            }
            else if(answerCheck == true)
            {
                attemptsLeft = 0;
                cout << endl << "You guessed the word!" << endl;
            }
        }
        cout << "The word is " << wordtoGuess << "!" << endl;
        while(endGame != "Y" && endGame != "y" && endGame != "N" && endGame != "n")
        {
            cout << "Would you like to play again? (Y/N)" << endl;
            cin >> endGame;
            if(endGame != "Y" && endGame != "y" && endGame != "N" && endGame != "n")
            {
                cout << "Please enter (Y/N)." << endl;
            }
        }
    }
    cout << endl << "Thank you for playing!";
    return 0;
}
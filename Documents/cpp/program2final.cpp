/*
    PROJECT NAME: ASSIGNMENT 1
    GROUP: 6
    TUTORIAL: TT6L
    GROUP MEMBERS: AMMAR HAKIMI BIN ADNAN (241UC24026)
                   AZRUL ISKANDAR BIN ZAINAL ABIDIN (241UC24029)
                   NUR AQILAH TAN BIN ALNUR IRWAN TAN ABDULLAH (241UC2407T)
*/

// PROGRAM 2 SOURCE CODES
#include <iostream>  // Library for general tasks/actions
#include <cstdlib>   // Library to generate the random numbers
#include <ctime>     // Library to read the current time
#include <string>    // Library to store a string
#include <iomanip>   // Library for formatted output
using namespace std;

// Function declaration for displaying the racetrack
void display_track (int xWingPosition, int tieFighterPosition, int chewbaccaPosition, char xWing_char, char tieFighter_char, char chewbacca_char);

int main()
{
    // Initializing the length of the racetrack with 43 blocks
    const int trackLength = 43;
    // Initializing the initial position of X Wing, Tie Fighter, Chewbacca
    int xWingPosition = 0, tieFighterPosition = 0, chewbaccaPosition = 0;
    // Declaring variable to store the number rounds
    int rounds;
    // Declaring variables to determine overall winner after all rounds
    int firstPlace, secondPlace, thirdPlace;
    // Array to keep track of wins for each racer
    int wins[3] = {0, 0, 0};    // [0] = X Wing, [1] = Tie Fighter, [2] = Chewbacca
    // Array to map index to racer name
    string racerNames[3] = {"X Wing", "Tie Fighter", "Chewbacca"};

    srand(time(0)); // Seed the random number generator

    // Asking user to enter the number of rounds for the race
    cout << "Enter the number of rounds: ";
    cin >> rounds;

    // Iteration to stimulate each rounds for a race
    for (int round = 1; round <= rounds; ++round)
    {    
        // Resetting the positions of the racers at the start of each round
        xWingPosition = 0, tieFighterPosition = 0, chewbaccaPosition = 0;

        // Displaying the number of rounds
        cout << "\n+-----------------------+\t";
        cout << "\n|\tRound " << round << " \t|";
        cout << "\n+-----------------------+\t\n\n";

        // Main loop to simulate the race
        while (true)
        {
            // Declaring variable to determine the place of each racer in each round of game
            string winner[3];

            // Formula to determine the random steps for each racers within their range
            int xWingSpeed = rand() % 3 + 2;        // Speed range from 2 - 4
            int tieFighterSpeed = rand() % 5 + 1;   // Speed range from 1 - 5
            int chewbaccaSpeed = rand() % 3 + 1;    // Speed range from 1 - 3
            
        
            // Updating the position of each racers based on the random generated steps
            xWingPosition += xWingSpeed;
            tieFighterPosition += tieFighterSpeed;
            chewbaccaPosition += chewbaccaSpeed;

            // Limiting the position of each racers to be within the racetrack
            if(xWingPosition > trackLength)
                xWingPosition = trackLength;

            if(tieFighterPosition > trackLength)
                tieFighterPosition = trackLength;

            if(chewbaccaPosition > trackLength)
                chewbaccaPosition = trackLength;

            // Pit stop Feature 
            // Check if any racer has reached the pit stop 
            if (xWingPosition == 28 || tieFighterPosition == 28 || chewbaccaPosition == 28)
            {
                // Displaying the updated racetrack and the current positions of each racers
                display_track(xWingPosition, tieFighterPosition, chewbaccaPosition, 'x', 't', 'c');
                cout << "\t\tX Wing moves " << xWingSpeed << " steps. New position: " << xWingPosition << endl;
                cout << "\t\tTie Fighter moves " << tieFighterSpeed << " steps. New position: " << tieFighterPosition << endl;
                cout << "\t\tChewbacca moves " << chewbaccaSpeed << " steps. New position: " << chewbaccaPosition << endl;

                // For display clarity
                cin.get();
                
                // Display the pit stop message 
                cout << "Pit stop !! Racer will wait for the other racers to make 3 moves" << endl; 

                // Counter for the number of moves made after the pit stop 
                int movesafterpitstop = 0;

                // Loop until both racers have made 2 moves after pit stop
                while (movesafterpitstop < 2)
                {
                    // If X Wing reached to block 28, the following statement will be executed
                    if (xWingPosition == 28)
                    {
                        // Generate random steps for each racers, except for X Wing
                        xWingSpeed = 0;
                        tieFighterSpeed = rand() % 5 + 1;
                        chewbaccaSpeed = rand() % 3 + 1;
                    
                        // Update the position of Tie Fighter 
                        tieFighterPosition += tieFighterSpeed;
                
                        // Update the position of third racer
                        chewbaccaPosition += chewbaccaSpeed;
                        
                    }
                    else if (tieFighterPosition == 28)
                    {
                        // Generate random steps for each racers, except for Tie Fighter
                        xWingSpeed = rand () % 3 + 2;
                        tieFighterSpeed = 0;
                        chewbaccaSpeed = rand() % 3 + 1;

                        // Update the position of X Wing
                        xWingPosition += xWingSpeed;
                
                        // Update the position of the third racer
                        chewbaccaPosition += chewbaccaSpeed;

                    }
                    else if (chewbaccaPosition == 28)
                    {
                        // Generate random steps for each racers, except for the third racer
                        xWingSpeed = rand () % 3 + 2;
                        tieFighterSpeed = rand() % 5 + 1;
                        chewbaccaSpeed = 0;

                        // Update the position of X Wing by adding random speed 
                        xWingPosition += xWingSpeed;

                        // Update the position of Tie Fighter by adding random speed 
                        tieFighterPosition += tieFighterSpeed;
                    }
                    
                    // Increment of the counter
                    movesafterpitstop++;

                    // Displaying the updated racetrack and the current positions of each racers
                    display_track(xWingPosition, tieFighterPosition, chewbaccaPosition, 'x', 't', 'c');
                    cout << "\t\tX Wing moves " << xWingSpeed << " steps. New position: " << xWingPosition << endl;
                    cout << "\t\tTie Fighter moves " << tieFighterSpeed << " steps. New position: " << tieFighterPosition << endl;
                    cout << "\t\tChewbacca moves " << chewbaccaSpeed << " steps. New position: " << chewbaccaPosition << endl;

                    // For display clarity
                    cin.get();
                }
            }// Ending of Pit stop feature

            // Displaying the updated racetrack and the current positions of each racers
            display_track(xWingPosition, tieFighterPosition, chewbaccaPosition, 'x', 't', 'c');
            cout << "\t\tX Wing moves " << xWingSpeed << " steps. New position: " << xWingPosition << endl;
            cout << "\t\tTie Fighter moves " << tieFighterSpeed << " steps. New position: " << tieFighterPosition << endl;
            cout << "\t\tChewbacca moves " << chewbaccaSpeed << " steps. New position: " << chewbaccaPosition << endl;

            // For display clarity
            cin.get();

            // To determine whether any of the racers has reached their final block
            if (xWingPosition >= trackLength || tieFighterPosition >= trackLength || chewbaccaPosition >= trackLength)
            {
                // Determine the order of finishers
                if (xWingPosition >= trackLength)
                    wins[0]++;
                if (tieFighterPosition >= trackLength)
                    wins[1]++;
                if (chewbaccaPosition >= trackLength)
                    wins[2]++;

                // Add a newline for clarity
                cout << endl;
                break;
            }
            cout << endl;
        }    
    }

    // Find the racer with the most wins
    if (wins[0] > wins[1] && wins[0] > wins[2])
    {
        firstPlace = 0;
        if (wins[1] > wins[2])
        {
            secondPlace = 1;
            thirdPlace = 2;
        }
        else
        {
            secondPlace = 2;
            thirdPlace = 1;
        }
    }
    else if (wins[1] > wins[0] && wins[1] > wins[2])
    {
        firstPlace = 1;
        if (wins[0] > wins[2])
        {
            secondPlace = 0;
            thirdPlace = 2;
        }
        else
        {
            secondPlace = 2;
            thirdPlace = 0;
        }
    }
    else
    {
        firstPlace = 2;
        if (wins[0] > wins[1])
        {
            secondPlace = 0;
            thirdPlace = 1;
        }
        else
        {
            secondPlace = 1;
            thirdPlace = 0;
        }
    }

    // Display the overall winners
    std::cout << "                        " << racerNames[firstPlace] << setw(10) << "\n";
    std::cout << "                     ______________                \n";
    std::cout << "    " << setw(11) << racerNames[secondPlace] << "     /              \\               \n";
    std::cout << "    _____________  /                \\    " << racerNames[thirdPlace] << setw(10) << "\n";
    std::cout << "   /             \\/        1st       \\_____________  \n";
    std::cout << "  /      2nd      \\                  /      3rd     \\  \n";
    std::cout << " /_________________\\________________/________________\\ \n";

    return 0;
}


// Function to display the racetrack, placing the characters of the racers at the given positions
void display_track (int xWingPosition, int tieFighterPosition, int chewbaccaPosition, char xWing_char, char tieFighter_char, char chewbacca_char)
{
    // Initializing constant variables of the size of the racetrack
    const int WIDTH = 31, HEIGHT = 22;

    // Initializing the array of the racetrack
    char track[HEIGHT][WIDTH];

    // Initialise all to spaces
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            track[i][j] = ' ';

    // Top part of the racetrack
    for (int i = 0; i <= 3; i = i + 3)  // Control the row
    {
        for (int j = 0; j < WIDTH - 1; j = j + 3) // Control the column
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
        }
        track[i][WIDTH - 1] = '+';
    }

    // Boxed part of the space
    for (int j = 0; j < WIDTH; j = j + 3)
    {
        track[1][j] = '|';
        track[2][j] = '|';
    }

    // | | Part
    for (int i = 4; i < 6; i++)
    {
        track[i][WIDTH - 4] = '|';
        track[i][WIDTH - 1] = '|';
    }

    // Top part of the racetrack
    for (int i = 6; i <= 9; i = i + 3)  // Control the row
    {
        for (int j = 6; j < WIDTH - 1; j = j + 3) // Control the column
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
        }
        track[i][WIDTH - 1] = '+';
    }

    // Boxed part of the space
    for (int j = 6; j < WIDTH; j = j + 3)
    {
        track[7][j] = '|';
        track[8][j] = '|';
    }

    // | | Part
    for (int i = 10; i < 12; i++)
    {
        track[i][6] = '|';
        track[i][9] = '|';
    }

    // Top part of the racetrack
    for (int i = 12; i <= 15; i = i + 3)  // Control the row
    {
        for (int j = 6; j < WIDTH - 1; j = j + 3) // Control the column
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
        }
        track[i][WIDTH - 1] = '+';
    }

    // Boxed part of the space
    for (int j = 6; j < WIDTH; j = j + 3)
    {
        track[13][j] = '|';
        track[14][j] = '|';
    }

    // | | Part
    for (int i = 16; i < 18; i++)
    {
        track[i][WIDTH - 4] = '|';
        track[i][WIDTH - 1] = '|';
    }

    // Top part of the racetrack
    for (int i = 18; i <= 21; i = i + 3)  // Control the column
    {
        for (int j = 0; j < WIDTH - 1; j = j + 3) // Control the row
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
        }
        track[i][WIDTH - 1] = '+';
    }

    // Boxed part of the space
    for (int j = 0; j < WIDTH; j = j + 3)
    {
        track[19][j] = '|';
        track[20][j] = '|';
    }

    // The most left part of the racetrack
    // | | part of the racetrack
    for(int i = 4; i < 18; i = i + 3)
    {
        track[i][0] = '|';
        track[i][3] = '|';
        track[i + 1][0] = '|';
        track[i + 1][3] = '|';
    }

    // +--+ part of the racetrack
    for(int i = 6; i < 18; i = i + 3)
    {
        track[i][0] = '+';
        track[i][1] = '-';
        track[i][2] = '-';
        track[i][3] = '+';
    }

    // Assigning X Wing symbol
    switch (xWingPosition)
    {
        // X Wing moves to the right
        case 0:
            track[19][1] = xWing_char;
            break;
        case 1:
            track[19][4] = xWing_char;
            break;
        case 2:
            track[19][7] = xWing_char;
            break;
        case 3:
            track[19][10] = xWing_char;
            break;
        case 4:
            track[19][13] = xWing_char;
            break;
        case 5:
            track[19][16] = xWing_char;
            break;
        case 6:
            track[19][19] = xWing_char;
            break;
        case 7:
            track[19][22] = xWing_char;
            break;
        case 8:
            track[19][25] = xWing_char;
            break;
        case 9:
            track[19][28] = xWing_char;
            break;
        //X Wing moves upward
        case 10:
            track[16][28] = xWing_char;
            break;
        case 11:
            track[13][28] = xWing_char;
            break;
        // X Wing moves to the left
        case 12:
            track[13][25] = xWing_char;
            break;
        case 13:
            track[13][22] = xWing_char;
            break;
        case 14:
            track[13][19] = xWing_char;
            break;
        case 15:
            track[13][16] = xWing_char;
            break;
        case 16:
            track[13][13] = xWing_char;
            break;
        case 17:
            track[13][10] = xWing_char;
            break;
        case 18:
            track[13][7] = xWing_char;
            break;
        // X Wing moves upward
        case 19:
            track[10][7] = xWing_char;
            break;
        case 20:
            track[7][7] = xWing_char;
            break;
        // X Wing moves to the right
        case 21:
            track[7][10] = xWing_char;
            break;
        case 22:
            track[7][13] = xWing_char;
            break;
        case 23:
            track[7][16] = xWing_char;
            break;
        case 24:
            track[7][19] = xWing_char;
            break;
        case 25:
            track[7][22] = xWing_char;
            break;
        case 26:
            track[7][25] = xWing_char;
            break;
        case 27:
            track[7][28] = xWing_char;
            break;
        // X Wing moves upward
        case 28:
            track[4][28] = xWing_char;
            break;
        case 29:
            track[1][28] = xWing_char;
            break;
        // X Wing moves to the left
        case 30:
            track[1][25] = xWing_char;
            break;
        case 31:
            track[1][22] = xWing_char;
            break;
        case 32:
            track[1][19] = xWing_char;
            break;
        case 33:
            track[1][16] = xWing_char;
            break;
        case 34:
            track[1][13] = xWing_char;
            break;
        case 35:
            track[1][10] = xWing_char;
            break;
        case 36:
            track[1][7] = xWing_char;
            break;
        case 37:
            track[1][4] = xWing_char;
            break;
        case 38:
            track[1][1] = xWing_char;
            break;
        // X Wing moves downward
        case 39:
            track[4][1] = xWing_char;
            break;
        case 40:
            track[7][1] = xWing_char;
            break;
        case 41:
            track[10][1] = xWing_char;
            break;
        case 42:
            track[13][1] = xWing_char;
            break;
        case 43:
            track[16][1] = xWing_char;
            break;
    }

    // Assigning Tie Fighter symbol
    switch (tieFighterPosition)
    {
        // Tie Fighter moves to the right
        case 0:
            track[19][2] = tieFighter_char;
            break;
        case 1:
            track[19][5] = tieFighter_char;
            break;
        case 2:
            track[19][8] = tieFighter_char;
            break;
        case 3:
            track[19][11] = tieFighter_char;
            break;
        case 4:
            track[19][14] = tieFighter_char;
            break;
        case 5:
            track[19][17] = tieFighter_char;
            break;
        case 6:
            track[19][20] = tieFighter_char;
            break;
        case 7:
            track[19][23] = tieFighter_char;
            break;
        case 8:
            track[19][26] = tieFighter_char;
            break;
        case 9:
            track[19][29] = tieFighter_char;
            break;
        // Tie Fighter moves upward
        case 10:
            track[16][29] = tieFighter_char;
            break;
        case 11:
            track[13][29] = tieFighter_char;
            break;
        // Tie Fighter moves to the left
        case 12:
            track[13][26] = tieFighter_char;
            break;
        case 13:
            track[13][23] = tieFighter_char;
            break;
        case 14:
            track[13][20] = tieFighter_char;
            break;
        case 15:
            track[13][17] = tieFighter_char;
            break;
        case 16:
            track[13][14] = tieFighter_char;
            break;
        case 17:
            track[13][11] = tieFighter_char;
            break;
        case 18:
            track[13][8] = tieFighter_char;
            break;
        // Tie Fighter moves upward
        case 19:
            track[10][8] = tieFighter_char;
            break;
        case 20:
            track[7][8] = tieFighter_char;
            break;
        // Tie Fighter moves to the right
        case 21:
            track[7][11] = tieFighter_char;
            break;
        case 22:
            track[7][14] = tieFighter_char;
            break;
        case 23:
            track[7][17] = tieFighter_char;
            break;
        case 24:
            track[7][20] = tieFighter_char;
            break;
        case 25:
            track[7][23] = tieFighter_char;
            break;
        case 26:
            track[7][26] = tieFighter_char;
            break;
        case 27:
            track[7][29] = tieFighter_char;
            break;
        // Tie Fighter moves upward
        case 28:
            track[4][29] = tieFighter_char;
            break;
        case 29:
            track[1][29] = tieFighter_char;
            break;
        // Tie Fighter moves to the left
        case 30:
            track[1][26] = tieFighter_char;
            break;
        case 31:
            track[1][23] = tieFighter_char;
            break;
        case 32:
            track[1][20] = tieFighter_char;
            break;
        case 33:
            track[1][17] = tieFighter_char;
            break;
        case 34:
            track[1][14] = tieFighter_char;
            break;
        case 35:
            track[1][11] = tieFighter_char;
            break;
        case 36:
            track[1][8] = tieFighter_char;
            break;
        case 37:
            track[1][5] = tieFighter_char;
            break;
        case 38:
            track[1][2] = tieFighter_char;
            break;
        // Tie Fighter moves downward
        case 39:
            track[4][2] = tieFighter_char;
            break;
        case 40:
            track[7][2] = tieFighter_char;
            break;
        case 41:
            track[10][2] = tieFighter_char;
            break;
        case 42:
            track[13][2] = tieFighter_char;
            break;
        case 43:
            track[16][2] = tieFighter_char;
            break;
    }

    // Assigning Chewbacca symbol
    switch (chewbaccaPosition)
    {
        // Chewbacca moves to the right
        case 0:
            track[20][1] = chewbacca_char;
            break;
        case 1:
            track[20][4] = chewbacca_char;
            break;
        case 2:
            track[20][7] = chewbacca_char;
            break;
        case 3:
            track[20][10] = chewbacca_char;
            break;
        case 4:
            track[20][13] = chewbacca_char;
            break;
        case 5:
            track[20][16] = chewbacca_char;
            break;
        case 6:
            track[20][19] = chewbacca_char;
            break;
        case 7:
            track[20][22] = chewbacca_char;
            break;
        case 8:
            track[20][25] = chewbacca_char;
            break;
        case 9:
            track[20][28] = chewbacca_char;
            break;
        // Chewbacca moves upward
        case 10:
            track[17][28] = chewbacca_char;
            break;
        case 11:
            track[14][28] = chewbacca_char;
            break;
        // Chewbacca moves to the left
        case 12:
            track[14][25] = chewbacca_char;
            break;
        case 13:
            track[14][22] = chewbacca_char;
            break;
        case 14:
            track[14][19] = chewbacca_char;
            break;
        case 15:
            track[14][16] = chewbacca_char;
            break;
        case 16:
            track[14][13] = chewbacca_char;
            break;
        case 17:
            track[14][10] = chewbacca_char;
            break;
        case 18:
            track[14][7] = chewbacca_char;
            break;
        // Chewbacca moves upward
        case 19:
            track[11][7] = chewbacca_char;
            break;
        case 20:
            track[8][7] = chewbacca_char;
            break;
        // Chewbacca moves to the right
        case 21:
            track[8][10] = chewbacca_char;
            break;
        case 22:
            track[8][13] = chewbacca_char;
            break;
        case 23:
            track[8][16] = chewbacca_char;
            break;
        case 24:
            track[8][19] = chewbacca_char;
            break;
        case 25:
            track[8][22] = chewbacca_char;
            break;
        case 26:
            track[8][25] = chewbacca_char;
            break;
        case 27:
            track[8][28] = chewbacca_char;
            break;
        // Chewbacca moves upward
        case 28:
            track[5][28] = chewbacca_char;
            break;
        case 29:
            track[2][28] = chewbacca_char;
            break;
        // Chewbacca moves to the right
        case 30:
            track[2][25] = chewbacca_char;
            break;
        case 31:
            track[2][22] = chewbacca_char;
            break;
        case 32:
            track[2][19] = chewbacca_char;
            break;
        case 33:
            track[2][16] = chewbacca_char;
            break;
        case 34:
            track[2][13] = chewbacca_char;
            break;
        case 35:
            track[2][10] = chewbacca_char;
            break;
        case 36:
            track[2][7] = chewbacca_char;
            break;
        case 37:
            track[2][4] = chewbacca_char;
            break;
        case 38:
            track[2][1] = chewbacca_char;
            break;
        // Chewbacca moves downward
        case 39:
            track[5][1] = chewbacca_char;
            break;
        case 40:
            track[8][1] = chewbacca_char;
            break;
        case 41:
            track[11][1] = chewbacca_char;
            break;
        case 42:
            track[14][1] = chewbacca_char;
            break;
        case 43:
            track[17][1] = chewbacca_char;
            break;
    }

    // Display the racetrack
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
            cout << track[i][j];
        cout << endl;
    }
    cout << endl;
}
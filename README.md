Summative Proposal: Typing Game
Written by: Sean Wei

Description of Game
A typing game requires the user to precisely type individual letters and characters that display on the screen which will proceed in the game. 
This will function as a challenging way to learn/develop typing skills and allows the user to see his or her improvements by showing their WPM.

Functions and Header files that will be used to implement the Game
- I will include the header file “conio.h” which is not part of the C standard library. 
    - This will allow me to use the function getch() which gets each character without and buffers, so it returns the characters without needing to press ENTER.
- I will include the header file <iostream> which allows me to input/output.
    - This will allow me to bold my text using \e[1m and \e[0m which is used to show the correct character inputted. 
    - This will allow me to color my text using \x1b[31m which is used to show the incorrect character inputted.
- I will include the header file <fstream> which will allow me to access files and read/write lines from/to the file.

Extra details of the game that can be added later
- A feature i can add to this game is an text image that will move every second
- Another feature I can add is to implement backspace, which will remove incorrect characters so the user can reenter the correct character.

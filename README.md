# Console Reference

This program was designed to work with contacts and information about them. **It supports saving contacts in the file.** It's a version 1.2 and it works in the console. 
In the next version I'm going to move it into __SFML window__.

## Running the programm

In the console we can move through the menu using arrows on our keyboard.
I've realised these functions:

- Adding and printing users
- Saving contacts in the file
- Searching by name, firm, phone number, occupation
- Animation in the console with the '*' symbol.

### Clarification
1) I wait for the buttons with the command _getch()
2) I use $sstream$ library to work with files. We need to save our contacts if we $don't$ want to lose them after closing the console.
3) In this version we use $vectors$ to keep information about contacts. The next version will work with associative containers, such as unordered_map, set, pair, and others.
4) Now simple animation is realised in the console. In the next version I will use SFML/Graphics.

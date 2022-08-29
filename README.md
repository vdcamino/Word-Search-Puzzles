# Word Search Puzzles

This program aims to solve word search puzzles

When running the code, the following workflow is executed:

1st step -> We create the structures that we will use
2nd step -> We read a dictionary (around 10,000 words) through a .txt file and insert each word in the trie
3rd step -> The dimensions of the puzzle (the char array) are asked to the user
4th step -> Next, two options are offered to the user:
    Option 1:
        -> The user creates the puzzle (he fills the 2d-char array)
        -> Then the program solves it and prints the words it has found in the array
    Option 2:
        -> The program generates the puzzle through a rand() function and then checks which and how many words are in the puzzle
        -> If there is no word in the array, a new array is generated and the process repeats until we have at least 1 word to be found
        -> Once a word is found, we insert it into a linked list
        -> Next, we print the puzzle and a count saying "Number of words to find = X" (the number of elements of the linked list)
        -> Finally, the user has 2 options:
            2.1 -> "Check word" which checks if the word he has found is in the linked list
            2.2 -> "Solve the puzzle for me" which prints the linked list
5th step -> Destroy the dynamically allocated structures
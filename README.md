# Hash Table Program
### Programmed by: Noah Carlow

This is a Hash Table/Map program written in C++. This program reads input data set consisting of four parts: the first part is a hash table size requested by a user; the second part is a list of projects with  its project name, and its number of participants. This part will end with the line “EndOfInsertion”; the third part is a number of commands to follow; and the forth part is a list of commands.

### Commands
* int hash_function(std::string key);     // Calculates the index using a hash formula
* void create_hash_table();               // Creates the Hash Table with user input
* void hash_display();                    // Displays content of the Hash Table
* void hash_search(std::string projName); // Searches for project inputed by user and returns cost
* void hash_delete(std::string projName); // Deletes a project inputed by user and returns cost
* void hash_max_cost();                   // Searches for the highest cost project in the Hash Table and returns it
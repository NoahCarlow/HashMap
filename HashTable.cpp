// TODO Add Header
// including a description and comments for each
// function/method, at the top of each class, and each file

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "HashTable.h"

// Calculates the index using a hash formula by using projName as the key
int HashTable::hash_function(std::string key)
{
    // adds all the ASCII values together of the project name multiplied by index to prevent variations of the same word
    int sum = 0;
    for(int i = 0; i < key.length(); i++)
    {
        sum += key[i]*i;
    }
    // returns the sum of all ASCII values mod hashSize to keep it within the size of the Hash Table
    return sum % hashSize;
}

// Creates the Hash Table with user input
void HashTable::create_hash_table()
{
    std::cout << "Please enter a hash table size: ";
    std::cin >> hashSize;

    std::vector<std::string> userProjInput;

    std::string projInput = "";
    std::getline(std::cin,projInput); // cin has to be done this way because c++ cin doesn't like whitespace

    std::stringstream ss(projInput);

    while(ss.good())
    {
        std::string subString;
        getline(ss, subString, ',');
        userProjInput.push_back(subString);
    }
    // ***TODO run this input until the user enters ENDLINE***
}

// Displays content of the Hash Table
void HashTable::hash_display()
{

}

// Searches for project inputed by user and returns cost
int HashTable::hash_search(std::string projName)
{

}

// Deletes a project inputed by user and returns cost
int HashTable::hash_delete(std::string projName)
{

}

// Searches for the highest cost project in the Hash Table and returns it
int HashTable::hash_max_cost()
{

}
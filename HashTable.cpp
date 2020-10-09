// TODO Add Header
// including a description and comments for each
// function/method, at the top of each class, and each file

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
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
    // creates our array of size hashSize entered by user
    projectHashTable = new Project[hashSize];

    // Initializes our Hash Table with emptpy data
    for(int i = 0; i < hashSize; i++)
    {
        projectHashTable[i].projCost = 0;
        projectHashTable[i].projName = "";
        projectHashTable[i].projRegion = "";
    }
    
    // control is used in a if statement below
    int control = 0;
    while(true)
    {
        std::vector<std::string> userProjInput;
        std::string projInput = "";
        
        // cin has to be done this way because cin doesn't like whitespace
        getline(std::cin,projInput);
        // stops asking for input when user types "EndOfInsertion"
        if(projInput == "EndOfInsertion")
        {
            break;
        }

        // this loop parses the input that is comma delimited
        std::stringstream ss(projInput);
        while(ss.good())
        {
            std::string subString;
            getline(ss, subString, ',');
            userProjInput.push_back(subString);
        }
        // userProjInput[0] is the projName so we run the hash_function on it to get the index
        int key = hash_function(userProjInput[0]);
        // initializes project data entered by user into correct index of the Hash Table

        // we dont want this to run until after 1 iteration because getline will run once before asking for input from user
        if(control > 0)
        {
            // stores the input from user into variable types to setup to be loaded in Hash Table
            std::string userProjName = userProjInput[0];
            std::string userProjRegion = userProjInput[1];
            int userProjCost = stoi(userProjInput[2]);
            // loads data into project at specified index after hash function
            projectHashTable[key].projName = userProjName;
            projectHashTable[key].projRegion = userProjRegion;
            projectHashTable[key].projCost = userProjCost;
        }
        control += 1;
    }
    // TODO number of commands followed by what commands they are
    int numberOfCommands;
    std::cout << "Please enter a number of commands: ";
    std::cin >> numberOfCommands;
    // ...
}

// Displays content of the Hash Table
void HashTable::hash_display()
{
    std::cout << "Hash Table Content" << std::endl;
    std::cout << "---------------------" << std::endl;

    for(int i = 0; i < hashSize; i++)
    {
        // TODO get linked list size output
        std::cout << "index: " << i << ", linked list size: " << std::endl;
        if(projectHashTable[i].projCost == 0)
        {
            std::cout << "The list is empty" << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Project Name: " << projectHashTable[i].projName << std::endl;
            std::cout << "Region: " << projectHashTable[i].projRegion << std::endl;
            std::cout << "Cost: " << projectHashTable[i].projCost << std::endl;
            std::cout << std::endl;
        }
    }
}

// Searches for project inputed by user and returns cost
int HashTable::hash_search(std::string projName)
{
    return 0;
}

// Deletes a project inputed by user and returns cost
int HashTable::hash_delete(std::string projName)
{
    return 0;
}

// Searches for the highest cost project in the Hash Table and returns it
int HashTable::hash_max_cost()
{
    return 0;
}
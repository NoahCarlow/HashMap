// Author: Noah Carlow
// Class ID: CSE 360
// Description: header file for hash functions with descriptions of each

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>

// Struct for Project which holds name, region, and cost
struct Project
{
    std::string projName;
    std::string projRegion;
    int projCost;
    Project* nextProject;
};

struct HashTable
{
    int hashSize;
    struct Project* projectHashTable;

    int hash_function(std::string key);     // Calculates the index using a hash formula
    void create_hash_table();               // Creates the Hash Table with user input
    void hash_display();                    // Displays content of the Hash Table
    void hash_search(std::string projName);  // Searches for project inputed by user and returns cost
    void hash_delete(std::string projName);  // Deletes a project inputed by user and returns cost
    void hash_max_cost();                    // Searches for the highest cost project in the Hash Table and returns it
};

#endif
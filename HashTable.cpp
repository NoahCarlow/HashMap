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
        projectHashTable[i].nextProject = NULL;
    }
    
    // control is used in an if statement below
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

            // checks if the spot in the hash table is empty if its not we need to implement linking
            if(projectHashTable[key].projName == "" && projectHashTable[key].projRegion == "")
            {
                // loads data into project at specified index after hash function
                projectHashTable[key].projName = userProjName;
                projectHashTable[key].projRegion = userProjRegion;
                projectHashTable[key].projCost = userProjCost;
            }
            else
            {
                // links the project to the existing project since a collision occured
                Project* ptr = &projectHashTable[key];
                Project* linkedProject = new Project;

                linkedProject->projName = userProjName;
                linkedProject->projRegion = userProjRegion;
                linkedProject->projCost = userProjCost;
                linkedProject->nextProject = NULL;

                // looks for the last project and stores the pointer in nextProject
                while(ptr->nextProject != NULL)
                {
                    ptr = ptr->nextProject;
                }
                ptr->nextProject = linkedProject;
            }
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
        int linkedListSize = 0;
        if(projectHashTable[i].projName != "")
        {
            linkedListSize++;
            if(projectHashTable[i].nextProject != NULL)
            {
                linkedListSize++;
                Project linkedProjectDataTwo = *projectHashTable[i].nextProject;
                while(linkedProjectDataTwo.nextProject != NULL)
                {
                    linkedListSize++;
                    linkedProjectDataTwo = *linkedProjectDataTwo.nextProject;
                }
            }
        }

        std::cout << "index: " << i << ", linked list size: " << linkedListSize << std::endl;
        if(projectHashTable[i].projName == "" && projectHashTable[i].projRegion == "")
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

            // checks if there is anymore projects to print if a collision occured using the first project pointer
            if(projectHashTable[i].nextProject != NULL)
            {
                // gets access to the project data stored within the pointer of the chained project
                Project linkedProjectData = *projectHashTable[i].nextProject;
                std::cout << "Project Name: " << linkedProjectData.projName << std::endl;
                std::cout << "Region: " << linkedProjectData.projRegion << std::endl;
                std::cout << "Cost: " << linkedProjectData.projCost << std::endl;
                std::cout << std::endl;

                // checks if there is anymore projects to print if a collision occured using the linked project pointer
                while(linkedProjectData.nextProject != NULL)
                {
                    // gets access to the project data stored within the pointer of the chained project
                    linkedProjectData = *linkedProjectData.nextProject;
                    std::cout << "Project Name: " << linkedProjectData.projName << std::endl;
                    std::cout << "Region: " << linkedProjectData.projRegion << std::endl;
                    std::cout << "Cost: " << linkedProjectData.projCost << std::endl;
                    std::cout << std::endl;
                }
            }
        }
    }
}

// Searches for project inputed by user and returns cost
void HashTable::hash_search(std::string projName)
{
    // gets the index that we should search at using our hash function
    int index = hash_function(projName);

    // checks if the first project in the index is found
    if(projectHashTable[index].projName == projName)
    {
        std::string name = projectHashTable[index].projName;
        int cost = projectHashTable[index].projCost;
        std::cout << "The Project: " << name << " with Cost " << cost << " is found" << std::endl;
    }
    // if first project is not equal to search then check if its chained to another project
    else if(projectHashTable[index].nextProject != NULL)
    {
        // gets access to the project data stored within the pointer of the chained project
        Project linkedProjectData = *projectHashTable[index].nextProject;
        if(linkedProjectData.projName == projName)
        {
            std::string name = linkedProjectData.projName;
            int cost = linkedProjectData.projCost;
            std::cout << "The Project: " << name << " with Cost " << cost << " is found" << std::endl;
        }
        // keep traversing through chained projects and check if search is equal to project name
        else
        {
            while(linkedProjectData.nextProject != NULL)
            {
                // gets access to the project data stored within the pointer of the chained project
                linkedProjectData = *linkedProjectData.nextProject;
                if(linkedProjectData.projName == projName)
                {
                    std::string name = linkedProjectData.projName;
                    int cost = linkedProjectData.projCost;
                    std::cout << "The Project: " << name << " with Cost " << cost << " is found" << std::endl;
                    break;
                }
            }
        }
    }
    // if nothing is found through out the whole hash table then return not found
    else
    {
        std::cout << "The Project: " << projName << " is not found" << std::endl;
    }
}

// Deletes a project inputed by user and returns cost
void HashTable::hash_delete(std::string projName)
{
    // gets the index that we should search at using our hash function
    int index = hash_function(projName);

    // checks if the first project in the index is found
    if(projectHashTable[index].projName == projName)
    {
        std::string name = projectHashTable[index].projName;
        int cost = projectHashTable[index].projCost;
        std::cout << "The Project: " << name << " with Cost " << cost << " is removed" << std::endl;

        // removes all the data and changes the pointer if it points to another project
        if(projectHashTable[index].nextProject != NULL)
        {
            // gets access to the project data stored within the pointer of the chained project
            Project linkedProjectData = *projectHashTable[index].nextProject;
            projectHashTable[index].projName = linkedProjectData.projName;
            projectHashTable[index].projRegion = linkedProjectData.projRegion;
            projectHashTable[index].projCost = linkedProjectData.projCost;
            projectHashTable[index].nextProject = linkedProjectData.nextProject;
        }
        else
        {
            projectHashTable[index].projName = "";
            projectHashTable[index].projRegion = "";
            projectHashTable[index].projCost = 0;
            projectHashTable[index].nextProject = NULL;
        }
    }
    // if first project is not equal to search then check if its chained to another project
    else if(projectHashTable[index].nextProject != NULL)
    {
        // gets access to the project data stored within the pointer of the chained project
        Project linkedProjectData = *projectHashTable[index].nextProject;
        if(linkedProjectData.projName == projName)
        {
            std::string name = linkedProjectData.projName;
            int cost = linkedProjectData.projCost;
            std::cout << "The Project: " << name << " with Cost " << cost << " is removed" << std::endl;

            // before we delete the object we have to check if it chains to another in the list then store that link in the node previous to it
            if(linkedProjectData.nextProject != NULL)
            {
                projectHashTable[index].nextProject = linkedProjectData.nextProject;
            }
            // if the project we are removing is not linked to another project then the original project's pointer is set to NULL
            else if(linkedProjectData.nextProject == NULL)
            {
                projectHashTable[index].nextProject = NULL;
            }

            // remove all the data in the project we are erasing
            linkedProjectData.projName = "";
            linkedProjectData.projRegion = "";
            linkedProjectData.projCost = 0;
            linkedProjectData.nextProject = NULL;
            // this is bad memory management because this object is still in our memory it's just not linked
            // may want to fix this at some point
        }
        // keep traversing through chained projects and check if search is equal to project name
        else
        {
            while(linkedProjectData.nextProject != NULL)
            {
                void* testy = linkedProjectData.nextProject;

                linkedProjectData = *linkedProjectData.nextProject;
                if(linkedProjectData.projName == projName)
                {
                    std::string name = linkedProjectData.projName;
                    int cost = linkedProjectData.projCost;
                    std::cout << "The Project: " << name << " with Cost " << cost << " is removed" << std::endl;
                    
                    linkedProjectData.projName = "";
                    linkedProjectData.projRegion = "";
                    linkedProjectData.projCost = 0;
                    linkedProjectData.nextProject = NULL;

                    break;
                }
            }
        }
    }
    // if nothing is found through out the whole hash table then return not found
    else
    {
        std::cout << "The Project: " << projName << " is not removed" << std::endl;
    }
}

// Searches for the highest cost project in the Hash Table and returns it
int HashTable::hash_max_cost()
{
    return 0;
}
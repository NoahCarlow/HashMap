// TODO Add Header
// including a description and comments for each
// function/method, at the top of each class, and each file

//write your hash analysis -- how did you come up with your hash function? Was the number of collisions what you expected? Did your hash function work well? If you had to change your function to reduce the number of collisions, how did you change it?

#include <iostream>
#include <string>
#include "HashTable.h"

int main()
{
    HashTable myHashTable;
    myHashTable.create_hash_table();
    myHashTable.hash_display();
}
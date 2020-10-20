// Author: Noah Carlow
// Class ID: CSE 360
// Description: main driver file that calls the hash table functions

// I came up with my hash function by studying other hash functions and seeing how they avoided collisions. This helped me understand what a bad vs good hash
// function was. The number of collisions was exactly as I expected. Depending on the size of the hash table, the collisions are very minimal.
// With that being said, I would conclude that my hash function is very effective and the computation is easy. To avoid collisions at the beginning, I had a
// problem where the same set of characters in different spots i.e. ("this" & "hits") would give the same key. I avoided this by multiplying each letter by the
// current index.

#include <iostream>
#include <string>
#include "HashTable.h"

int main()
{
    HashTable myHashTable;
    myHashTable.create_hash_table();
}
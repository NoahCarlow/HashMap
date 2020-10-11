// TODO Add Header
// including a description and comments for each
// function/method, at the top of each class, and each file

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
    std::string name = "noah";
    myHashTable.create_hash_table();
    myHashTable.hash_display();
    //myHashTable.hash_delete(name);
    //myHashTable.hash_display();
    myHashTable.hash_max_cost();
}
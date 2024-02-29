#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct Employee {
    int key;
};

struct HashTable {
    struct Employee* table[TABLE_SIZE];
};

void initializeHashTable(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}


void insert(struct HashTable* ht, int key, struct Employee* emp) {
    int hkey = hashFunction(key);
    int index = hkey;
    int i = 0;

    while (ht->table[index] != NULL) {
        i++;
        index = (hkey + i) % TABLE_SIZE;
    }

    ht->table[index] = emp;
}

struct Employee* search(struct HashTable* ht, int key) {
    int hkey = hashFunction(key);
    int index = hkey;
    int i = 0;

    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key) {
            return ht->table[index];
        }

        i++;
        index = (hkey + i) % TABLE_SIZE;
    }

    return NULL;
}

void displayHashTable(struct HashTable* ht) {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] != NULL) {
            printf("Index %d: Key %d\n", i, ht->table[i]->key);
        }
    }
}

int main() {
    struct HashTable ht;
    initializeHashTable(&ht);

    struct Employee emp1 = {101};
    struct Employee emp2 = {201};
    struct Employee emp3 = {301};

    insert(&ht, emp1.key, &emp1);
    insert(&ht, emp2.key, &emp2);
    insert(&ht, emp3.key, &emp3);

    displayHashTable(&ht);

    int searchKey = 201;
    struct Employee* result = search(&ht, searchKey);

    if (result != NULL) {
        printf("\nEmployee with key %d found!\n", searchKey);
    } else {
        printf("\nEmployee with key %d not found!\n", searchKey);
    }

    return 0;
}

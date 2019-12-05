#ifndef _HashTable_
#define _HashTable_

#include<stdio.h>
#include<assert.h>
#include<stdint.h>
#include<stddef.h>

typedef struct _node_ Node;
typedef struct _hash_ Hash;

struct _node_ {
	char data[30];
	Node *next;
};

struct _hash_ {
	int32_t size;
	Node **address_list;
	int32_t count;
};

Hash *hashTable_new(int32_t size);
uint32_t hashtable_Lookup(Hash *h,char *ele);
Hash *hashtable_addelement(Hash *h, char *ele);
Hash *hashtable_delete_element(Hash *t,char *ele);


#endif
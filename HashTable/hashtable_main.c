#include<stdio.h>
#include<assert.h>
#include<stdint.h>
#include<stddef.h>
#include "hashtable.h"

int main()
{
	printf("coming here:\n");
	Hash *h = hashTable_new(13); // size should be size
	h=hashtable_addelement(h,"hash");
	h=hashtable_addelement(h,"stop");
	h=hashtable_addelement(h,"tops");
	h=hashtable_addelement(h,"pots");
	assert(h->count==4);
	assert(hashtable_Lookup(h,"stop")==1);

	h = hashtable_delete_element(h,"ajith");
	assert(h->count==4);

	h=hashtable_delete_element(h,"tops");
	assert(h->count==3);

	
	
	return 0;
}